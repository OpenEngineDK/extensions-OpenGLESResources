// OpenGLES indices.
// -------------------------------------------------------------------
// Copyright (C) 2011 OpenEngine.dk (See AUTHORS) 
// 
// This program is free software; It is covered by the GNU General 
// Public License version 2 or any later version. 
// See the GNU General Public License for more details (see LICENSE). 
//--------------------------------------------------------------------

#ifndef _OPENGL_ES_INDICES_H_
#define _OPENGL_ES_INDICES_H_

#include <Resources/IOpenGLESIndices.h>
#include <Resources/NewIndices.h>

#include <typeinfo>

namespace OpenEngine {
    namespace Resources {

        template <class T>
        class OpenGLESIndices : public NewIndices<T>,
                                public IOpenGLESIndices {
        public:
            OpenGLESIndices() : NewIndices<T>() {}

            template <class S>
            OpenGLESIndices(unsigned int size, S* data) 
                : NewIndices<T>() {
                this->size = size;
                this->data = new T[size];
                if (typeid(T) == typeid(S)){
                    // Same type, simple copy
                    memcpy(this->data, data, sizeof(T) * size);
                }else{
                    // Other type, must convert every element
                    for (unsigned int i = 0; i < size; ++i)
                        this->data[i] = data[i];
                }
            }
            
            virtual ~OpenGLESIndices() {
                if (this->data) delete this->data;
                this->data = NULL;
            }

            virtual OpenGLESIndices<T>* Clone() { throw Core::NotImplemented(); }

            virtual Types::Type GetType() { return Types::GetResourceType<T>(); }
            virtual unsigned int GetDimension() { return 1; }

            virtual unsigned int GetSize() { return this->size; }
            virtual void Resize(unsigned int size) { throw Core::NotImplemented(); }

            virtual void UpdateData(void* data, unsigned int offset = 0, unsigned int elements = 0) { throw Core::NotImplemented(); }
            virtual void* MapData(IBuffer::AccessType access, unsigned int offset = 0, unsigned int elements = 0) { return this->data; }
            virtual void UnmapData() { }
            virtual std::string ToString() { 
                this->data = (T*)MapData(READ_ONLY);
                std::string str = NewIndices<T>::ToString();
                UnmapData();
                return str;
            }

            unsigned int GetIndex(unsigned int i) { return (unsigned int)this->data[i]; }
            
            void Draw(GLenum mode) {
                glDrawElements(mode, this->size, Types::GetResourceType<T>(), this->data);
                CHECK_FOR_GLES2_ERROR();
            }
        };

    }
}

#endif
