// Indices interface.
// -------------------------------------------------------------------
// Copyright (C) 2010 OpenEngine.dk (See AUTHORS) 
// 
// This program is free software; It is covered by the GNU General 
// Public License version 2 or any later version. 
// See the GNU General Public License for more details (see LICENSE). 
//--------------------------------------------------------------------

#ifndef _OE_I_INDICES_H_
#define _OE_I_INDICES_H_

#include <Resources/IBuffer.h>

namespace OpenEngine {
    namespace Resources {

        class IIndices : public virtual IBuffer {
        public:
            virtual unsigned int GetIndex(unsigned int i) = 0;
        };

    }
}

#endif
