#include <stdio.h>
#include <stdlib.h>
#include <iostream.h>
#include <string.h>
#ifdef HAVE_CONFIG_H
#include <config.h>
#endif
extern "C" {
#include <mediatool.h>
}
#include "kaudio.h"



/******************************************************************************
 *
 * Function:	mystrdup()
 *
 * Task:	Duplicate a string, using freshly allocated memory.
 *		See "man strdup" for more information
 *
 * in:		s	Adress of string.
 * 
 * out:		char*	Adress of new created/copied string.
 *
 * Comment:	This is a drop-in replacement function for strdup().
 *		As the mentioned function is not POSIX, this is necessary
 *		for portabilty.
 *
 *****************************************************************************/
char *mystrdup(char *s)
{
  char *tmp = (char*)malloc(strlen(s)+1);
  if (tmp)
    strcpy(tmp,s);
  return tmp;
}

KAudio::KAudio()
{
  char		ServerId[256];
  char		KMServerCidFile[256];
  char		*tmpadr;
  FILE		*KMServerCidHandle;
  MediaCon	m;

  ServerContacted = false;
  WAVname         = NULL;

  /*********************************************************************************
   * Read in audio player id (This is NOT a pid, but a communication connection id)
   *********************************************************************************/
  tmpadr= getenv("HOME");
  strcpy(KMServerCidFile,tmpadr);
  strcpy(KMServerCidFile+strlen(KMServerCidFile),"/.kaudioserver");
  KMServerCidHandle = fopen(KMServerCidFile,"r");
  if (KMServerCidHandle == NULL)
    {
      cerr << "PID could not get read.\n";
      return;
    }

  fscanf(KMServerCidHandle,"%s\n",ServerId);
  fclose (KMServerCidHandle);



  /************* connect audio player ******************************/
  MdConnect(atoi(ServerId), &m);
  if ( m.shm_adr == NULL )
    {
      cerr << "Could not find media master.\n";
      return;
    }
  /************* query for chunk adresses **************************/
  FnamChunk   = (MdCh_FNAM*)FindChunkData(m.shm_adr, "FNAM");
  if (!FnamChunk)
    {
      cerr << "No FNAM chunk.\n";
      return;
    }
  IhdrChunk   = (MdCh_IHDR*)FindChunkData(m.shm_adr, "IHDR");
  if (!IhdrChunk)
    {
      cerr << "No IHDR chunk.\n";
      return;
    }
  KeysChunk   = (MdCh_KEYS*)FindChunkData(m.shm_adr, "KEYS");
  if (!KeysChunk)
    {
      cerr << "No KEYS chunk.\n";
      return;
    }

  MdConnectInit();

  ServerContacted = true;
}




bool KAudio::play()
{
  if (!ServerContacted)
    return false;

  EventCounterRaise( &(KeysChunk->play) ,1);
  return true;
}

bool KAudio::play(char *filename)
{
  if (!ServerContacted)
    return false;

  setFilename(filename);
  FileNameSet( FnamChunk, WAVname);
  return play();
}

bool KAudio::setFilename(char *filename)
{
  if (!ServerContacted)
    return false;
  if (WAVname  != NULL)
    free(WAVname);
  WAVname = mystrdup(filename);

  return true;
}

bool KAudio::stop()
{
  if (!ServerContacted)
    return false;

  EventCounterRaise(&(KeysChunk->stop) ,1);
  return true;
}


int KAudio::serverStatus()
{
  return !ServerContacted;
}
