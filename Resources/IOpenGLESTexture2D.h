// OpenGLES 2D texture interface.
// -------------------------------------------------------------------
// Copyright (C) 2011 OpenEngine.dk (See AUTHORS) 
// 
// This program is free software; It is covered by the GNU General 
// Public License version 2 or any later version. 
// See the GNU General Public License for more details (see LICENSE). 
//--------------------------------------------------------------------

#ifndef _I_OPENGL_ES_TEXTURE_H_
#define _I_OPENGL_ES_TEXTURE_H_

#include <Meta/OpenGLES.h>
#include <Resources/ITexture2D.h>

namespace OpenEngine {
    namespace Resources {
        
        class IOpenGLESTexture2D : public ITexture2D {
        public:
            void Apply(GLint loc) = 0;
            void Release() = 0;
        };

    }
}

#endif
