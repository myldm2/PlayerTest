//
//  esUtil.h
//  PlayerTest
//
//  Created by 玉洋 on 2019/7/5.
//  Copyright © 2019 玉洋. All rights reserved.
//

#ifndef esUtil_h
#define esUtil_h

#define ESUTIL_API
#define ESCALLBACK

#ifdef __APPLE__
#include <OpenGLES/ES3/gl.h>
#endif

#include <stdio.h>

typedef struct
{
    GLfloat    m[4][4];
} ESMatrix;

typedef struct ESContext ESContext;

struct ESContext
{
    void    *platformData;
    void    *userData;
    GLint   width;
    GLint   height;
    void ( ESCALLBACK *drawFunc ) ( ESContext * );
    void ( ESCALLBACK *shutdownFunc ) ( ESContext * );
    void ( ESCALLBACK *keyFunc ) ( ESContext *, unsigned char, int, int );
    void ( ESCALLBACK *updateFunc ) ( ESContext *, float deltaTime );
};

#endif /* esUtil_h */
