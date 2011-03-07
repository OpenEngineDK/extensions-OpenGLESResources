// OpenGL ES Buffer class.
// -------------------------------------------------------------------
// Copyright (C) 2010 OpenEngine.dk (See AUTHORS) 
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
            unsigned int size;
            T* data;

        public:
            OpenGLESBuffer() 
                : size(0), data(NULL) {}
            OpenGLESBuffer(unsigned int size, T* data)
                : size(size), data(data) {}
            OpenGLESBuffer(IDataBlockPtr hat){
                size = hat->GetSize();
#ifdef OE_SAFE
                if (hat->GetDimension() != N || 
                    hat->GetType() != GetType())
                    throw Exception("IDataBlockPtr does not match OpenGLESBuffer template args.");
#endif
                data = new T[size * N];
                memcpy(data, hat->GetVoidData(), sizeof(T) * N * size);
            }

            //virtual OpenGLESBuffer<N,T>* Clone() { throw Core::NotImplemented(); }
            virtual IBuffer* Clone() { throw Core::NotImplemented(); }

            virtual Types::Type GetType() { return Types::GetResourceType<T>(); }
            virtual unsigned int GetDimension() { return N; }

            virtual unsigned int GetSize() { return size; }
            virtual void Resize(unsigned int size) { throw Core::NotImplemented(); }
            virtual void* MapData(IBuffer::AccessType access) { return data; }
            virtual void UnmapData() { }
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

            void Apply(GLint loc) { 
                glVertexAttribPointer(loc, N, Types::GetResourceType<T>(), GL_FALSE, 0, data);
                CHECK_FOR_GLES2_ERROR();
            }
            void Release() { }
        };

    }
}

#endif
