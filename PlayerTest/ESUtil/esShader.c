//
//  esShader.c
//  PlayerTest
//
//  Created by 玉洋 on 2019/7/8.
//  Copyright © 2019 玉洋. All rights reserved.
//

#include "esUtil.h"
#include <stdlib.h>

GLuint ESUTIL_API esLoadShader ( GLenum type, const char *shaderSrc )
{
    GLuint shader;
    GLint compiled;
    
    shader = glCreateShader( type );
    
    if ( shader == 0 )
    {
        return 0;
    }
    
    glShaderSource ( shader, 1, &shaderSrc, NULL );
    glCompileShader ( shader );
    glGetShaderiv ( shader, GL_COMPILE_STATUS, &compiled );
    
    if ( !compiled )
    {
        GLint infoLen = 0;
        
        glGetShaderiv ( shader, GL_INFO_LOG_LENGTH, &infoLen );
        
        if ( infoLen > 1 )
        {
            char *infoLog = malloc ( sizeof ( char ) * infoLen );
            
            glGetShaderInfoLog ( shader, infoLen, NULL, infoLog );
            esLogMessage ( "Error compiling shader:\n%s\n", infoLog );
            
            free ( infoLog );
        }
        
        glDeleteShader ( shader );
        return 0;
    }

    return shader;
}
