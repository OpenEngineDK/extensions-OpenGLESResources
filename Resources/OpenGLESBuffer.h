// OpenGL ES Buffer class.
// -------------------------------------------------------------------
// Copyright (C) 2011 OpenEngine.dk (See AUTHORS) 
// 
// This program is free software; It is covered by the GNU General 
// Public License version 2 or any later version. 
// See the GNU General Public License for more details (see LICENSE). 
//--------------------------------------------------------------------

#ifndef _OE_OPENGL_ES_BUFFER_H_
#define _OE_OPENGL_ES_BUFFER_H_

#include <Resources/IOpenGLESBuffer.h>
#include <Resources/Buffer.h>

#include <Resources/IDataBlock.h>

namespace OpenEngine {
    namespace Resources {

        template <class T>
        class OpenGLESBuffer : public Buffer<T>,
                               public virtual IOpenGLESBuffer {
        protected:
            //GLint id;

        public:
            OpenGLESBuffer() 
                : Buffer<T>() {}
            OpenGLESBuffer(int dim, unsigned int size, T* data)
                : Buffer<T>(dim, size, data) {}
            OpenGLESBuffer(IDataBlockPtr hat){
                this->size = hat->GetSize();
                this->dim = hat->GetDimension();
#ifdef OE_SAFE
                if (hat->GetType() != GetType())
                    throw Exception("IDataBlockPtr does not match OpenGLESBuffer template args.");
#endif
                this->data = new T[this->size * this->dim];
                memcpy(this->data, hat->GetVoidData(), sizeof(T) * this->dim * this->size);
            }

            virtual OpenGLESBuffer<T>* Clone() { throw Core::NotImplemented(); }

            virtual Types::Type GetType() { return Types::GetResourceType<T>(); }
            virtual unsigned int GetDimension() { return this->dim; }

            virtual unsigned int GetSize() { return this->size; }
            virtual void Resize(unsigned int size) { throw Core::NotImplemented(); }
            virtual void* MapData(IBuffer::AccessType access) { return this->data; }
            virtual void UnmapData() { }
            virtual std::string ToString() { return Buffer<T>::ToString(); }

            void Apply(GLint loc) { 
                glVertexAttribPointer(loc, this->dim, Types::GetResourceType<T>(), GL_FALSE, 0, this->data);
                CHECK_FOR_GLES2_ERROR();
            }
            void Release() { }
        };

    }
}

#endif
