// OpenGLES buffer interface.
// -------------------------------------------------------------------
// Copyright (C) 2011 OpenEngine.dk (See AUTHORS) 
// 
// This program is free software; It is covered by the GNU General 
// Public License version 2 or any later version. 
// See the GNU General Public License for more details (see LICENSE). 
//--------------------------------------------------------------------

#ifndef _I_OPENGL_ES_BUFFER_H_
#define _I_OPENGL_ES_BUFFER_H_

#include <Resources/IBuffer.h>
#include <Meta/OpenGLES2.h>

namespace OpenEngine {
    namespace Resources {

        class IOpenGLESBuffer : public virtual IBuffer {
        public:
            virtual void Apply(GLint loc) = 0;
            virtual void Release() = 0;

            template <class T>
            static inline GLuint CreateBuffer(int dim, unsigned int size, T* data){
                GLuint bufferId;
                glGenBuffers(1, &bufferId);
                glBindBuffer(GL_ARRAY_BUFFER, bufferId);
                CHECK_FOR_GLES2_ERROR();

                GLsizeiptr glSize = sizeof(T) * dim * size;
                glBufferData(GL_ARRAY_BUFFER, glSize, data, GL_STATIC_DRAW);
                CHECK_FOR_GLES2_ERROR();

                glBindBuffer(GL_ARRAY_BUFFER, 0);                
                CHECK_FOR_GLES2_ERROR();
                
                return bufferId;
            }
        };

    }
}

#endif
