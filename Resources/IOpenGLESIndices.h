// OpenGLES indices interface.
// -------------------------------------------------------------------
// Copyright (C) 2011 OpenEngine.dk (See AUTHORS) 
// 
// This program is free software; It is covered by the GNU General 
// Public License version 2 or any later version. 
// See the GNU General Public License for more details (see LICENSE). 
//--------------------------------------------------------------------

#ifndef _I_OPENGL_ES_INDICES_H_
#define _I_OPENGL_ES_INDICES_H_

#include <Meta/OpenGLES2.h>
#include <Resources/IIndices.h>

namespace OpenEngine {
    namespace Resources {

        class IOpenGLESIndices : public virtual IIndices {
        public:
            virtual void Draw(GLenum mode) = 0;
        };


    }
}

#endif
