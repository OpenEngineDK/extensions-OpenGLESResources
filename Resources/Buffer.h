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
#include <Utils/Convert.h>

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
            Buffer(int dim, unsigned int size, T* data) : dim(dim), size(size) {
                if (data){
                    this->data = new T[dim * size];
                    memcpy(this->data, data, dim * size * sizeof(T));
                }else
                    this->data = NULL;
            }
            virtual ~Buffer(){
                if (data) delete data;
            }

            virtual Buffer<T>* Clone() { throw Core::NotImplemented(); }
            virtual Types::Type GetType() { return Types::GetResourceType<T>(); }
            virtual unsigned int GetDimension() { return dim; }
            virtual unsigned int GetSize() { return size; }
            virtual void Resize(unsigned int size) { throw Core::NotImplemented(); }

            virtual void UpdateData(void* data, unsigned int offset = 0, unsigned int elements = 0) { 
                elements = elements == 0 ? size - offset : elements;
#if OE_SAFE
                if (offset + elements > size)
                    throw Core::Exception("Cannot update buffer of size " + Utils::Convert::ToString(size) + " with " + Utils::Convert::ToString(elements) + " elements at offset " + Utils::Convert::ToString(offset) + ".");
#endif
                memcpy(this->data + offset, data, sizeof(T) * elements);
            }
            virtual void* MapData(IBuffer::AccessType access, unsigned int offset = 0, unsigned int elements = 0) { return data + offset; }
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
