// Indices.
// -------------------------------------------------------------------
// Copyright (C) 2011 OpenEngine.dk (See AUTHORS) 
// 
// This program is free software; It is covered by the GNU General 
// Public License version 2 or any later version. 
// See the GNU General Public License for more details (see LICENSE). 
//--------------------------------------------------------------------

#ifndef _OE_NEW_INDICES_H_
#define _OE_NEW_INDICES_H_

#include <Resources/IIndices.h>
#include <Core/Exceptions.h>

namespace OpenEngine {
    namespace Resources {
        
        template<class T>
        class NewIndices : public IIndices {
            NewIndices() {}
            
            virtual NewIndices<T>* Clone() { throw Core::NotImplemented(); }
            virtual Types::Type GetType() { throw Core::NotImplemented(); }
            virtual unsigned int GetDimension() { throw Core::NotImplemented(); }
            virtual unsigned int GetSize() { throw Core::NotImplemented(); }
            virtual void Resize(unsigned int size) { throw Core::NotImplemented(); }

            virtual unsigned int GetIndex(unsigned int i) { throw Core::NotImplemented(); }
            virtual void* MapData(IBuffer::AccessType access) { throw Core::NotImplemented(); }
            virtual void UnmapData() { throw Core::NotImplemented(); }

            virtual std::string ToString() { throw Core::NotImplemented(); }

        };

    }
}

#endif
