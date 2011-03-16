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
        class NewIndices : public virtual IIndices {
        protected:
            unsigned int size;
            T* data;
        public:
            NewIndices() : size(0), data(NULL) {}
            virtual ~NewIndices(){
                if (this->data) delete this->data;
                this->data = NULL;
            }
            
            virtual NewIndices<T>* Clone() { throw Core::NotImplemented(); }
            virtual Types::Type GetType() { return Types::GetResourceType<T>(); }
            virtual unsigned int GetDimension() { return 1; }
            virtual unsigned int GetSize() { return size; }
            virtual void Resize(unsigned int size) { throw Core::NotImplemented(); }

            virtual void UpdateData(void* data, unsigned int offset = 0, unsigned int elements = 0) { throw Core::NotImplemented(); }
            virtual unsigned int GetIndex(unsigned int i) { return (unsigned int)data[i]; }
            virtual void* MapData(IBuffer::AccessType access, unsigned int offset = 0, unsigned int elements = 0) { return data; }
            virtual void UnmapData() { }

            virtual std::string ToString() { 
                std::ostringstream out;
                out << size << " indices of type " << Types::GetResourceType<T>() << ".\n";
                out << "[";
                for (unsigned int i = 0; i < size; ++i){
                    out << data[i];
                    if (i+1<size) out << ", ";
                }
                out << "]";

                return out.str();
            }

        };

    }
}

#endif
