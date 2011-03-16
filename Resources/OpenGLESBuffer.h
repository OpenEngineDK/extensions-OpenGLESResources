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

namespace OpenEngine {
    namespace Resources {

        template <class T>
        class OpenGLESBuffer : public Buffer<T>,
                               public virtual IOpenGLESBuffer {
        protected:
            GLuint bufferId;

        public:
            OpenGLESBuffer() 
                : Buffer<T>(), bufferId(0) {}
            
            OpenGLESBuffer(int dim, unsigned int size, T* data, IBuffer::AccessType access = WRITE_ONLY)
                : Buffer<T>(dim, size, access != WRITE_ONLY ? data : NULL) {
                if (this->data == NULL)
                    bufferId = CreateBuffer(dim, size, data);
            }

            virtual ~OpenGLESBuffer() {
                // If the buffer has been allocated on the GPU then delete it.
                if (bufferId){
                    glDeleteBuffers(1, &bufferId);
                    bufferId = 0;
                }
            }

            virtual OpenGLESBuffer<T>* Clone() { throw Core::NotImplemented(); }

            virtual Types::Type GetType() { return Types::GetResourceType<T>(); }
            virtual unsigned int GetDimension() { return this->dim; }

            virtual unsigned int GetSize() { return this->size; }
            virtual void Resize(unsigned int size) { 
                if (this->data == NULL)
                    throw Core::Exception("Cannot resize an OpenGL ES Buffer that is write only");
                else
                    throw Core::NotImplemented();
            }
            
            virtual void UpdateData(void* data, unsigned int offset = 0, unsigned int elements = 0) {
                elements = elements == 0 ? this->size - offset : elements;
#if OE_SAFE
                if (offset + elements > this->size)
                    throw Core::Exception("Cannot update ES buffer of size " + 
                                          Utils::Convert::ToString(this->size) + " with " + 
                                          Utils::Convert::ToString(elements) + 
                                          " elements at offset " + 
                                          Utils::Convert::ToString(offset) + ".");
#endif

                glBindBuffer(GL_ARRAY_BUFFER, bufferId);
                glBufferSubData(GL_ARRAY_BUFFER, offset * this->dim * sizeof(T), elements * this->dim * sizeof(T), data);
                CHECK_FOR_GLES2_ERROR();
            }
            
            virtual void* MapData(IBuffer::AccessType access, unsigned int offset = 0, unsigned int elements = 0) {
                // If data isn't null then work directly on CPU data.
                if (this->data) return this->data + offset;

                // Else we should work on the GPU data, but that is write only                
                if (access == READ_ONLY || access == READ_WRITE)
                    throw Core::Exception("Buffer was created with WRITE_ONLY access type and cannot be read from.");

                glBindBuffer(GL_ARRAY_BUFFER, bufferId);
                // @TODO glMapBufferOES is slow if the entire buffer is updated.
                T* ret = (T*)glMapBufferOES(GL_ARRAY_BUFFER, GL_WRITE_ONLY_OES);
                CHECK_FOR_GLES2_ERROR();
                return ret + offset;
            }
            virtual void UnmapData() { 
                // If data is located at the GPU then unbind it
                if (this->data == NULL){
                    glUnmapBufferOES(GL_ARRAY_BUFFER);
                    CHECK_FOR_GLES2_ERROR();
                }
            }
            
            virtual std::string ToString() { return Buffer<T>::ToString(); }

            void Apply(GLint loc) { 
                if (this->data){
                    glVertexAttribPointer(loc, this->dim, Types::GetResourceType<T>(), GL_FALSE, 0, this->data);
                }else{
                    glBindBuffer(GL_ARRAY_BUFFER, bufferId);
                    glVertexAttribPointer(loc, this->dim, Types::GetResourceType<T>(), GL_FALSE, 0, 0);
                }
                CHECK_FOR_GLES2_ERROR();
            }
            
            void Release() { }
        };

    }
}

#endif
