// Buffer class.
// -------------------------------------------------------------------
// Copyright (C) 2011 OpenEngine.dk (See AUTHORS) 
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
        class Buffer : public virtual IBuffer {
        protected:
            unsigned int size;
            T* data;

        public:
            Buffer() : size(0), data(NULL) {}
            Buffer(unsigned int size, T* data) : size(size), data(data) {}

            virtual Buffer<N, T>* Clone() { throw Core::NotImplemented(); }
            virtual Types::Type GetType() { throw Core::NotImplemented(); }
            virtual unsigned int GetDimension() { throw Core::NotImplemented(); }
            virtual unsigned int GetSize() { throw Core::NotImplemented(); }
            virtual void Resize(unsigned int size) { throw Core::NotImplemented(); }
            virtual void* MapData(IBuffer::AccessType access) { throw Core::NotImplemented(); }
            virtual void UnmapData() { throw Core::NotImplemented(); }
            virtual std::string ToString() { 
                std::ostringstream out;
                out << "size: " << size << ", dimension: " << N << ", type: " << Types::GetResourceType<T>() << "\n";
                T* data = (T*)MapData(READ_ONLY);
                out << "[";
                for (unsigned int i = 0; i < size; ++i){
                    if (i % N == 0) out << "(";
                    out << data[i];
                    if (i % N == N-1) out << ")";
                    if (i+1<size) out << ", ";
                }
                out << "]";
                UnmapData();

                return out.str();
            }
        };

    }
}

#endif
