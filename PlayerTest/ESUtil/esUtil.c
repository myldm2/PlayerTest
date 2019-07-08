//
//  esUtil.c
//  PlayerTest
//
//  Created by 玉洋 on 2019/7/5.
//  Copyright © 2019 玉洋. All rights reserved.
//

#include "esUtil.h"
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include "esUtil.h"

typedef FILE esFile;

#include "FileWrapper.h"

typedef struct
__attribute__ ( ( packed ) )
{
    unsigned char  IdSize,
    MapType,
    ImageType;
    unsigned short PaletteStart,
    PaletteSize;
    unsigned char  PaletteEntryDepth;
    unsigned short X,
    Y,
    Width,
    Height;
    unsigned char  ColorDepth,
    Descriptor;
    
} TGA_HEADER;

GLboolean ESUTIL_API esCreateWindow( ESContext *esContext, const char *title, GLint width, GLint height, GLuint flags )
{
    return GL_TRUE;
}

///
//  esRegisterDrawFunc()
//
void ESUTIL_API esRegisterDrawFunc ( ESContext* esContext, void ( ESCALLBACK *drawFunc ) ( ESContext * ) )
{
    esContext->drawFunc = drawFunc;
}

///
//  esRegisterShutdownFunc()
//
void ESUTIL_API esRegisterShutdownFunc ( ESContext *esContext, void ( ESCALLBACK *shutdownFunc ) ( ESContext * ) )
{
    esContext->shutdownFunc = shutdownFunc;
}

///
//  esRegisterUpdateFunc()
//
void ESUTIL_API esRegisterUpdateFunc ( ESContext *esContext, void ( ESCALLBACK *updateFunc ) ( ESContext *, float ) )
{
    esContext->updateFunc = updateFunc;
}


///
//  esRegisterKeyFunc()
//
void ESUTIL_API esRegisterKeyFunc ( ESContext *esContext,
                                   void ( ESCALLBACK *keyFunc ) ( ESContext *, unsigned char, int, int ) )
{
    esContext->keyFunc = keyFunc;
}

void ESUTIL_API esLogMessage( const char *formatStr, ... )
{
    va_list params;
    char buf[BUFSIZ];
    
    va_start ( params, formatStr );
    vsprintf ( buf, formatStr, params );
    printf ( "%s", buf );
    va_end ( params );
}

static esFile *esFileOpen ( void *ioContext, const char *fileName )
{
    esFile *pFile = NULL;
    fileName = GetBundleFileName ( fileName );
    pFile = fopen ( fileName, "rb" );
    return pFile;
}

static void esFileClose ( esFile *pFile )
{
    if ( pFile != NULL )
    {
        fclose ( pFile );
        pFile = NULL;
    }
}

static int esFileRead ( esFile *pFile, int bytesToRead, void *buffer )
{
    int bytesRead = 0;
    
    if ( pFile == NULL )
    {
        return bytesRead;
    }
    
    bytesRead = fread ( buffer, bytesToRead, 1, pFile );
    
    return bytesRead;
}

///
// esLoadTGA()
//
//    Loads a 8-bit, 24-bit or 32-bit TGA image from a file
//
char *ESUTIL_API esLoadTGA ( void *ioContext, const char *fileName, int *width, int *height )
{
    char        *buffer;
    esFile      *fp;
    TGA_HEADER   Header;
    int          bytesRead;
    
    // Open the file for reading
    fp = esFileOpen ( ioContext, fileName );
    
    if ( fp == NULL )
    {
        // Log error as 'error in opening the input file from apk'
        esLogMessage ( "esLoadTGA FAILED to load : { %s }\n", fileName );
        return NULL;
    }
    
    bytesRead = esFileRead ( fp, sizeof ( TGA_HEADER ), &Header );
    
    *width = Header.Width;
    *height = Header.Height;
    
    if ( Header.ColorDepth == 8 ||
        Header.ColorDepth == 24 || Header.ColorDepth == 32 )
    {
        int bytesToRead = sizeof ( char ) * ( *width ) * ( *height ) * Header.ColorDepth / 8;
        
        // Allocate the image data buffer
        buffer = ( char * ) malloc ( bytesToRead );
        
        if ( buffer )
        {
            bytesRead = esFileRead ( fp, bytesToRead, buffer );
            esFileClose ( fp );
            
            return ( buffer );
        }
    }
    
    return ( NULL );
}
