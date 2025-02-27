 
/**
* kimgio.h -- Implementation of interface to the KDE Image IO library.
* Sirtaj Singh Kang <taj@kde.org>, 23 Sep 1998.
*
* $Id: kimgio.cpp,v 1.2.4.1 1999/08/23 15:51:45 porten Exp $
*
* This library is distributed under the conditions of the GNU LGPL.
*/

static int registered = 0;

#include"jpeg.h"
#include"pngr.h"
#include"xview.h"
#include"eps.h"
#include"tiffr.h"

#ifdef HAVE_CONFIG_H
#include"config.h"
#endif

#include<qimage.h>

void kimgioRegister(void)
{
	if( registered ) {
        debug("KIMGIO: Already registered.");
		return;
	}

	registered = 1;

#ifdef HAVE_LIBJPEG
	// JPEG
	QImageIO::defineIOHandler( "JPEG", "^\377\330", 0,
			kimgio_jpeg_read, kimgio_jpeg_write );
    debug("KIMGIO: Registering JPEG.");
#endif

	// XV thumbnails
	QImageIO::defineIOHandler( "XV", "^P7 332", "T", 
		kimgio_xv_read, kimgio_xv_write );

	QImageIO::defineIOHandler("EPS", "^%!PS-Adobe-[^\n]+\n"
		"%%BoundingBox", "T", kimgio_epsf_read, kimgio_epsf_write );

#ifdef HAVE_LIBPNG
	QImageIO::defineIOHandler( "PNG", "^.PNG", 0,
		kimgio_png_read, kimgio_png_write );
    debug("KIMGIO: Registering PNG.");
#endif

#ifdef HAVE_LIBTIFF
	QImageIO::defineIOHandler("TIFF","[MI][MI]", 0,
                kimgio_tiff_read, kimgio_tiff_write );
    debug("KIMGIO: Registering TIFF.");
#endif
}
