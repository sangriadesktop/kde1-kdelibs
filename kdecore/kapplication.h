// $Id$
// Revision 1.41  1998/01/06 22:54:29  kulow
// $Log$
// Revision 1.9  1997/05/17 20:38:22  kalle
// Kalle:
// - Bugfix for KPanner (from Paul Kendall)
// - Better colors with kdisplay schemes (from Bernd Wuebben)
// - new behavior in KApplication::invokeHTMLHelp(): if the first
//   argument (the filename) is empty, the filename is defaulted to
// 	$KDEDIR/doc/HTML/<appname>/<appname>.html
// - KApplication::getCaption for Matthias added (breaks binary compatibility!)
//
// Revision 1.8  1997/05/15 20:33:20  wuebben
// Bernd: Added signals:
// kdisplayFontChanged()
// kdisplayPaletteChanged()
// kdisplayStyleChaned()
// Some applications such as kedit need to know when the Font, Palette,
// or Style ngeduy.
//
// Revision 1.7  1997/05/13 05:49:00  kalle
// Kalle: Default arguments for KConfig::read*Entry()
// app-specific config files don't start with a dot
// Bufgix for the bugfix in htmlobj.cpp (FontManager)
//
// Revision 1.6  1997/05/08 22:53:16  kalle
// Kalle:
// KPixmap gone for good
// Eliminated static objects from KApplication and HTML-Widget
//
// Revision 1.5  1997/05/02 16:46:34  kalle
// Kalle: You may now override how KApplication reacts to external changes
// KButton uses the widget default palette
// new kfontdialog version 0,5
// new kpanner by Paul Kendall
// new: KIconLoader
//
// Revision 1.4  1997/04/28 06:57:45  kalle
// Various widgets moved from apps to libs
// Added KSeparator
// Several bugs fixed
// Patches from Matthias Ettrich
// Made ksock.cpp more alpha-friendly
// Removed XPM-Loading from KPixmap
// Reaping zombie KDEHelp childs
// WidgetStyle of KApplication objects configurable via kdisplay
//
// Revision 1.3  1997/04/21 22:37:23  kalle
// Bug in Kconfig gefixed (schrieb sein app-spezifisches File nicht mehr)
// kcolordlg und kapp abgedated (von Martin Jones)
//
// Revision 1.2  1997/04/15 20:01:55  kalle
// Kalles changes for 0.8
//
// Revision 1.1.1.1  1997/04/13 14:42:41  cvsuser
// Source imported
//
// Revision 1.1.1.1  1997/04/09 00:28:07  cvsuser
// Sources imported
//
// Revision 1.10  1997/03/16 22:33:39  kalle
// appName()
//
// Revision 1.9  1997/03/09 17:28:32  kalle
// KTextStream -> QTextStream
//
// Revision 1.8  1997/01/15 21:46:26  kalle
// getConfig() and getConfigState() public (kfm needs them)
//
// Revision 1.7  1997/01/15 20:18:36  kalle
// merged changed from 0.52
//
// Revision 1.6  1996/12/14 13:52:46  kalle
// Some documentation to the constructors added.
//
// Revision 1.5  1996/12/14 13:49:58  kalle
// finding out the state the application config object is in
//
// Revision 1.4  1996/12/14 12:49:31  kalle
// method names start with a small letter
//
// Revision 1.3  1996/12/07 22:22:23  kalle
// Drag and Drop
//
// Revision 1.2  1996/12/01 11:20:23  kalle
// private members, GetConfig() inline
//
// Revision 1.1  1996/12/01 10:57:10  kalle
// Initial revision
//
//
// KApplication header file - base class for all KDE applications
//
// (C) 1996 Matthias Kalle Dalheimer <mda@stardivision.de>
//
// DND stuff by Torben Weis <weis@stud.uni-frankfurt.de>
// 09.12.96
//
// Revision 1.25  1997/10/04 19:42:45  kalle
// new KConfig
//
#ifndef _KCONFIG_H
#include <Kconfig.h>
#endif
// Save icon and mini-icon pixmap
// - KApplication::saveYourself (signal)
// - KApplication::tempFileName()
// - KApplication::checkRecoverFile()
//
//
// MD: Implemented reading of the colour scheme contrast variable. This allows
// you to choose the highlights and lowlights used to draw widgets and has been
// part of the colour scheme specification for some time
/** A base class for all KDE applications.
// Revision 1.20  1997/09/11 19:44:54  kalle
// New debugging scheme for KDE (binary incompatible!)


#ifndef klocale
#define klocale KApplication::getKApplication()->getLocale()
#endif
#define i18n KApplication::getKApplication()->getLocale()->translate
#ifndef i18n
* @version $Id$
#endif

class KIconLoader;
  Q_OBJECT;

/** Constructor. Pass command-line arguments. A KConfig object is
#include <drag.h>
* @version $Id$
#include <qapp.h>
#include <qfile.h>
/** 
* Constructor. Pass command-line arguments. 
*
/** Constructor. Pass command-line arguments. A KConfig object is
* queried afterwards with getConfigState(). 
*/
* accelerators, common menu entries, a KConfig object
* etc. KApplication installs a signal handler for the SIGCHLD signal
/** 
* Constructor. Pass command-line arguments. 
/** Destructor */
* name is "~/." + rAppName + "rc". The state of the application-specific 
* Destructor 
/** Return the current application object.
	*
	* A KConfig object is
	* created that contains an application-specific config file whose
	* name is "~/." + argv[0] + "rc". This constructor should be considered
	* obsolete. The state of the application-specific config file may be
/** 
* Return the current application object.
/** Return the logical application name as set in the constructor.
* to the single global KApplication object, since more than one cannot be
* created in the same application. It saves the trouble of having to pass
* the pointer to it explicitly to every function that may require it.
/** Retrieve the application config object. 
/** 
*
* Return the logical application name as set in the constructor.
*/

  /** 
/** Possible return values for getConfigState().
	{ return aIconPixmap; }
* @see getConfigState
  
  /**
	* Get the mini-icon for the application.
	* @return a QPixmap with the icon.
/** Retrieve the state of the app-config object. Possible return values
*/

  /** Sets the top widget of the application . This widget will
    * be used for communication with the session manager.
/** 
* Retrieve the state of the app-config object. 
* @see ConfigState
* Possible return values
* are APPCONFIG_NONE (the application-specific config file could not be
* opened neither read-write nor read-only), APPCONFIG_READONLY (the
/** Invoke the kdehelp HTML help viewer. 
*
* @see #ConfigState
*/
  void registerTopWidget();
  /* obsolete, will dissappear (Matthias) */
/**
* Invoke the kdehelp HTML help viewer. 
*
* @param aFilename	The filename that is to be loaded. Its location
*			is computed automatically according to the KFSSTND. 
/** Get the KDE base dir. This is the value of the KDEDIR
*			a "#" (hash) character.
*/
	* Retrieve the state of the app-config object. 
	*
/** 
* Get the KDE base dir. 
/** Find a file using standard KDE search paths.  Possible search paths
	* @return the name of the directory
	*/
  static const QString& kde_configdir();

/** 
/** Get the KDE font list. This method allows you to get the KDE font 
*  list which was composed by the user with kfontmanager. Usually you should 
*  work only with those fonts in your kapplication. 
  /**
	* Get the local KDE base dir
/** 
* Get the KDE font list.
*
* This method allows you to get the KDE font 
/** Return a text for the window caption. This would be set either by
*/
	* Get the local KDE config dir
	*
	* This is usually $HOME/.kde/share/config
/**
  //@Man: Drag 'n Drop stuff
  //@{
  /// An X11 atom used for IPC
	* document.
  /// An X11 atom used for IPC
	* @return A new filename for auto-saving. You have to free() this
  /// An X11 atom used for IPC

  /// An X11 atom used for IPC
	* @param pFilename The full path to the document you want to open.
  /// An X11 atom used for IPC
	* pointer yourself, otherwise you have a memory leak.
	*/
  /// Get the X11 display
  /**
  /// Used by KDNDDropZone to register
	* @return whether the KLocale object has already been constructed
  /// Used by KDNDDropZone during shutdown
  /**
  /// Set the DropZone which reveives root drop events.
  /**
  //@}
	* An X11 atom used for IPC
  * Used by KDNDDropZone during shutdown
//@Man: Drag 'n Drop stuff
//@{
/// List of all DropZones.
  * Set the DropZone which reveives root drop events.
  */
/** The last drop zone the mouse was over.
/**
* List of all DropZones.
*/
	*/
  Atom getDndRootProtocolAtom() { return DndRootProtocol; }    
/// The DropZone which receives root drop events.
* If we get a DndLeaveProtocol we must inform 'lastEnteredDropZone'
* that the mouse left the DropZone.
/// Used to catch X11 events
/**
* The DropZone which receives root drop events.
/// An X11 atom used for IPC
  /**
/// An X11 atom used for IPC
	* List of all DropZones.
/// An X11 atom used for IPC
	*/
/// An X11 atom used for IPC
  QList<KDNDDropZone> dropZones;
/// An X11 atom used for IPC

/// The X11 display
	* that the mouse left the DropZone.
//@}
	*/
  KDNDDropZone *lastEnteredDropZone;

  /**
/**
* The X11 display
*/
  /**
	* Two X11 atoms used for session management
private slots:
  QTextStream* pConfigStream; // stream of the application-specific config file
  QFile* pConfigFile; // application-specific config file
	* X11 atoms used for IPC
	*/
  Atom DndProtocol;
  Atom DndEnterProtocol;
 void appHelpActivated();
  void aboutKDE();
  void aboutApp();
  void aboutQt();

private:
  void* pAppData; // don't touch this without Kalles permission
  KConfig* pConfig; // application config object
  KConfig* pSessionConfig; //instance specific application config object
  QString aSessionName; // logical name of the instance specific config file
  QWidget* pTopWidget;
  QString aAppName; // logical application name
  QString aCaption; // the name for the window title
  QString aWmCommand; // for userdefined session management
  KIconLoader* pIconLoader; // the application's own icon loader
  KLocale* pLocale;  
  static KCharsets* pCharsets;  // it shouldn't be static, but you would loose binary compability 
  void* dummy2; // do not use these without asking kalle@kde.org
  void* dummy3;
  void* dummy4;
  QString aAppAboutString; // The text for the about box
  QString aDummyString2; // do not touch
  QString aDummyString3; // do not touch
  QString aDummyString4; // do not touch
  bool bLocaleConstructed; // has the KLocale object already been constructed
  bool bSessionManagement; 
  bool bSessionManagementUserDefined;
  QPixmap aIconPixmap;
  QPixmap aMiniIconPixmap;
/** KApplication has changed its Palette on behalf of kdisplay.

  void buildSearchPaths();
  void appendSearchPath( const char *path );

signals:
/** KApplication has changed its GUI Style on behalf of kdisplay.
* Normally, widgets will update their palettes automatically, but you
* should connect to this to program special behaviour.
*/

public:
/** 
/** KApplication has changed its Font on behalf of kdisplay.
* respond to an explicit setGUIStyle() call), but you should connect to
* this to program special behaviour.
*/
  QColor selectColor;
  QColor selectTextColor;
  void kdisplayStyleChanged();

  /**
	* KApplication has changed its Font due to a KDisplay request.
	*
	* Normally widgets will update their fonts automatically, but you should
	* connect to this to monitor global font changes, especially if you are
	* using explicit fonts.
	*/
  void kdisplayFontChanged();

  /** 
	* KApplication has changed either its GUI style, its font or its palette
	* due to a kdisplay request. Normally, widgets will update their styles
	* automatically, but yout should connect to this to program special
	* behavior. */
  void appearanceChanged();

  /** Session management is about to close your application.
	*
	* Connect to this signal in order to save your data. Do NOT
	* manipulate the UI in that slot, it is blocked by kwm.
	*
	* Use the getSessionConfig() Kconfig object to store all
	* your instance specific datas.
	*
	* Note: you should not do that if you are using the KTopLevelWidget.
	*       Overload saveProperties(...)/readProperties(...) in that case.
	*       This gives you also the possibillity to handle multiple windows
	*       application in an easy manner.
	*/
  void saveYourself();
};

#endif
