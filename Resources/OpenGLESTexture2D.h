// OpenGLES 2D texture.
// -------------------------------------------------------------------
// Copyright (C) 2011 OpenEngine.dk (See AUTHORS) 
// 
// This program is free software; It is covered by the GNU General 
// Public License version 2 or any later version. 
// See the GNU General Public License for more details (see LICENSE). 
//--------------------------------------------------------------------

#include <Resources/IOpenGLESTexture2D.h>
#include <Resources/Texture2D.h>

namespace OpenEngine {
    namespace Resources {

        template <class T>
        class OpenGLESTexture2D : public IOpenGLESTexture2D,
                                  public Texture2D<T>{
        protected:

        public:
            OpenGLESTexture2D() {}

            void Apply(GLint loc){

            }

            void Release() {
                
            }
            
        };

    }
}

