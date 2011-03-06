// OpenGLES indices.
// -------------------------------------------------------------------
// Copyright (C) 2011 OpenEngine.dk (See AUTHORS) 
// 
// This program is free software; It is covered by the GNU General 
// Public License version 2 or any later version. 
// See the GNU General Public License for more details (see LICENSE). 
//--------------------------------------------------------------------

#ifndef _OPENGL_ES_INDICES_H_
#define _OPENGL_ES_INDICES_H_

#include <Resources/IOpenGLESIndices.h>
#include <Resources/OpenGLESBuffer.h>

namespace OpenEngine {
    namespace Resources {

        template <class T>
        class OpenGLESIndices : public OpenGLESBuffer<1, T> {
        public:
            OpenGLESIndices() {}
            void Draw(GLenum mode) {}
        };

    }
}

#endif
