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
#include <Resources/OpenGLESBuffer.h>

namespace OpenEngine {
    namespace Resources {

        template <class T>
        class OpenGLESIndices : public OpenGLESBuffer<1, T>,
                                public IOpenGLESIndices {
        public:
            OpenGLESIndices() {}

            //virtual OpenGLESIndices<T>* Clone() { throw Core::NotImplemented(); }
            virtual IBuffer* Clone() { throw Core::NotImplemented(); }

            virtual Types::Type GetType() { return Types::GetResourceType<T>(); }
            virtual unsigned int GetDimension() { return 1; }

            virtual unsigned int GetSize() { return this->size; }
            virtual void Resize(unsigned int size) { throw Core::NotImplemented(); }
            virtual void* MapData(IBuffer::AccessType access) { return this->data; }
            virtual void UnmapData() { }
            virtual std::string ToString() { throw Core::NotImplemented(); }

            unsigned int GetIndex(unsigned int i) { return (unsigned int)this->data[i]; }
            
            void Draw(GLenum mode) {
                glDrawElements(mode, this->size, Types::GetResourceType<T>(), this->data);
                CHECK_FOR_GLES2_ERROR();
            }
        };

    }
}

#endif
