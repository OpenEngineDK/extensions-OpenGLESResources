// OpenGL ES resource converter class.
// -------------------------------------------------------------------
// Copyright (C) 2011 OpenEngine.dk (See AUTHORS) 
// 
// This program is free software; It is covered by the GNU General 
// Public License version 2 or any later version. 
// See the GNU General Public License for more details (see LICENSE). 
//--------------------------------------------------------------------

#ifndef _OE_OPENGL_ES_RESOURCE_CONVERTER_H_
#define _OE_OPENGL_ES_RESOURCE_CONVERTER_H_

#include <Resources/OpenGLESBuffer.h>
#include <Resources/OpenGLESIndices.h>
#include <Scene/ISceneNodeVisitor.h>

#include <boost/shared_ptr.hpp>

namespace OpenEngine {
    namespace Scene {
        class ISceneNode;
        class MeshNode;
    }
    namespace Resources {
        
        class IDataBlock;
        typedef boost::shared_ptr<IDataBlock> IDataBlockPtr;

        class OpenGLESConverter : public Scene::ISceneNodeVisitor {
        public:
            OpenGLESConverter() {}
            virtual ~OpenGLESConverter() {}
            
            void ConvertScene(Scene::ISceneNode* scene);

            void VisitMeshNode(Scene::MeshNode *node);
            
            template<int N, class T>
            IBuffer* CreateBuffer(unsigned int size, T* data){
                return new OpenGLESBuffer<N, T>(size, data);
            }

            template<class T>
            IIndices* CreateIndices(unsigned int size, T* data){
                if (typeid(T) == typeid(int) || typeid(T) == typeid(unsigned int))
                    return new OpenGLESIndices<unsigned short>(size, data);
                else
                    return new OpenGLESIndices<T>(size, data);
            }

        protected:
            IBuffer* ConvertToESBuffer(IDataBlockPtr data);
        };
    }
}

#endif
