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

        template <class T>
        class Buffer : public virtual IBuffer {
        protected:
            int dim;
            unsigned int size;
            T* data;

        public:
            Buffer() : dim(0), size(0), data(NULL) {}
            Buffer(int dim, unsigned int size, T* data) : dim(dim), size(size), data(data) {}

            virtual Buffer<T>* Clone() { throw Core::NotImplemented(); }
            virtual Types::Type GetType() { return Types::GetResourceType<T>(); }
            virtual unsigned int GetDimension() { return dim; }
            virtual unsigned int GetSize() { return size; }
            virtual void Resize(unsigned int size) { throw Core::NotImplemented(); }
            virtual void* MapData(IBuffer::AccessType access) { return data; }
            virtual void UnmapData() { }
            virtual std::string ToString() { 
                std::ostringstream out;
                out << "size: " << size << ", dimension: " << dim << ", type: " << Types::GetResourceType<T>() << "\n";
                T* data = (T*)MapData(READ_ONLY);
                out << "[";
                for (unsigned int i = 0; i < size; ++i){
                    if (i % dim == 0) out << "(";
                    out << data[i];
                    if (i % (unsigned int)dim == (unsigned int)dim-1) out << ")";
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
