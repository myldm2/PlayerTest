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

#include <stdlib.h>

#ifdef __APPLE__
#include <OpenGLES/ES3/gl.h>
#endif

#include <stdio.h>

/// esCreateWindow flag - RGB color buffer
#define ES_WINDOW_RGB           0
/// esCreateWindow flag - ALPHA color buffer
#define ES_WINDOW_ALPHA         1
/// esCreateWindow flag - depth buffer
#define ES_WINDOW_DEPTH         2
/// esCreateWindow flag - stencil buffer
#define ES_WINDOW_STENCIL       4
/// esCreateWindow flat - multi-sample buffer
#define ES_WINDOW_MULTISAMPLE   8

///
// Types
//
#ifndef FALSE
#define FALSE 0
#endif
#ifndef TRUE
#define TRUE 1
#endif

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

GLboolean ESUTIL_API esCreateWindow ( ESContext *esContext, const char *title, GLint width, GLint height, GLuint flags );

//
/// \brief Register a draw callback function to be used to render each frame
/// \param esContext Application context
/// \param drawFunc Draw callback function that will be used to render the scene
//
void ESUTIL_API esRegisterDrawFunc ( ESContext *esContext, void ( ESCALLBACK *drawFunc ) ( ESContext * ) );

//
/// \brief Register a callback function to be called on shutdown
/// \param esContext Application context
/// \param shutdownFunc Shutdown callback function
//
void ESUTIL_API esRegisterShutdownFunc ( ESContext *esContext, void ( ESCALLBACK *shutdownFunc ) ( ESContext * ) );

//
/// \brief Register an update callback function to be used to update on each time step
/// \param esContext Application context
/// \param updateFunc Update callback function that will be used to render the scene
//
void ESUTIL_API esRegisterUpdateFunc ( ESContext *esContext, void ( ESCALLBACK *updateFunc ) ( ESContext *, float ) );

//
/// \brief Register a keyboard input processing callback function
/// \param esContext Application context
/// \param keyFunc Key callback function for application processing of keyboard input
//
void ESUTIL_API esRegisterKeyFunc ( ESContext *esContext,
                                   void ( ESCALLBACK *drawFunc ) ( ESContext *, unsigned char, int, int ) );
//
/// \brief Log a message to the debug output for the platform
/// \param formatStr Format string for error log.
//
void ESUTIL_API esLogMessage ( const char *formatStr, ... );

#endif /* esUtil_h */
