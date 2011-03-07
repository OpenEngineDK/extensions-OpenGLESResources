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

        template <int N, class T>
        class OpenGLESBuffer : public Buffer<N,T>,
                               public virtual IOpenGLESBuffer {
        protected:
            //GLint id;

        public:
            OpenGLESBuffer() 
                : Buffer<N, T>() {}
            OpenGLESBuffer(unsigned int size, T* data)
                : Buffer<N, T>(size, data) {}
            OpenGLESBuffer(IDataBlockPtr hat){
                this->size = hat->GetSize();
#ifdef OE_SAFE
                if (hat->GetDimension() != N || 
                    hat->GetType() != GetType())
                    throw Exception("IDataBlockPtr does not match OpenGLESBuffer template args.");
#endif
                this->data = new T[this->size * N];
                memcpy(this->data, hat->GetVoidData(), sizeof(T) * N * this->size);
            }

            virtual OpenGLESBuffer<N,T>* Clone() { throw Core::NotImplemented(); }

            virtual Types::Type GetType() { return Types::GetResourceType<T>(); }
            virtual unsigned int GetDimension() { return N; }

            virtual unsigned int GetSize() { return this->size; }
            virtual void Resize(unsigned int size) { throw Core::NotImplemented(); }
            virtual void* MapData(IBuffer::AccessType access) { return this->data; }
            virtual void UnmapData() { }
            virtual std::string ToString() { return Buffer<N, T>::ToString(); }

            void Apply(GLint loc) { 
                glVertexAttribPointer(loc, N, Types::GetResourceType<T>(), GL_FALSE, 0, this->data);
                CHECK_FOR_GLES2_ERROR();
            }
            void Release() { }
        };

    }
}

#endif
