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
