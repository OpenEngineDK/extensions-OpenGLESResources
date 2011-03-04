// Buffer class.
// -------------------------------------------------------------------
// Copyright (C) 2010 OpenEngine.dk (See AUTHORS) 
// 
// This program is free software; It is covered by the GNU General 
// Public License version 2 or any later version. 
// See the GNU General Public License for more details (see LICENSE). 
//--------------------------------------------------------------------

#ifndef _OE_BUFFER_H_
#define _OE_BUFFER_H_

#include <Resources/IBuffer.h>
#include <Core/Exceptions.h>

namespace OpenEngine {
    namespace Resources {

        template <int N, class T>
        class Buffer : public IBuffer {
        public:
            Buffer() {}

            virtual Buffer<N, T>* Clone() { throw Core::NotImplemented(); }
            virtual Types::Type GetType() { throw Core::NotImplemented(); }
            virtual unsigned int GetDimension() { throw Core::NotImplemented(); }
            virtual unsigned int GetSize() { throw Core::NotImplemented(); }
            virtual void Resize(unsigned int size) { throw Core::NotImplemented(); }
            virtual void* MapData(IBuffer::AccessType access) { throw Core::NotImplemented(); }
            virtual void UnmapData() { throw Core::NotImplemented(); }
            virtual std::string ToString() { throw Core::NotImplemented(); }
        };

    }
}

#endif
