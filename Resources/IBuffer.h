// Buffer interface.
// -------------------------------------------------------------------
// Copyright (C) 2010 OpenEngine.dk (See AUTHORS) 
// 
// This program is free software; It is covered by the GNU General 
// Public License version 2 or any later version. 
// See the GNU General Public License for more details (see LICENSE). 
//--------------------------------------------------------------------

#ifndef _OE_I_BUFFER_H_
#define _OE_I_BUFFER_H_

#include <Math/Vector.h>
#include <Resources/Types/ResourceTypes.h>

#include <string>

namespace OpenEngine {
    namespace Resources {

        class IBuffer {
        public:
            enum AccessType {READ_ONLY = 0x88B8,
                             WRITE_ONLY = 0x88B9,
                             READ_WRITE = 0x88BA};

            virtual IBuffer* Clone() = 0;
            virtual Types::Type GetType() = 0;
            virtual unsigned int GetDimension() = 0;
            virtual unsigned int GetSize() = 0;
            virtual void Resize(unsigned int size) = 0;
            virtual void* MapData(AccessType access) = 0;
            virtual void UnmapData() = 0;
            virtual std::string ToString() = 0;
        };

    }
}

#endif
