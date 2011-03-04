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

#include <Meta/OpenGLES2.h>

namespace OpenEngine {
    namespace Resources {

        class IOpenGLESBuffer /*: public IDataBlock */ {
        public:
            virtual void Apply(GLint loc) = 0;
            virtual void Release() = 0;
        };

    }
}

#endif
