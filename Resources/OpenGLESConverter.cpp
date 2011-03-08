// OpenGL ES resource converter class.
// -------------------------------------------------------------------
// Copyright (C) 2011 OpenEngine.dk (See AUTHORS) 
// 
// This program is free software; It is covered by the GNU General 
// Public License version 2 or any later version. 
// See the GNU General Public License for more details (see LICENSE). 
//--------------------------------------------------------------------

#include <Resources/OpenGLESConverter.h>

#include <Geometry/GeometrySet.h>
#include <Geometry/NewGeometrySet.h>
#include <Geometry/Mesh.h>
#include <Geometry/NewMesh.h>
#include <Resources/IDataBlock.h>
#include <Resources/IDataBlock.h>
#include <Scene/MeshNode.h>
#include <Scene/SceneNode.h>
#include <Scene/NewMeshNode.h>

using namespace OpenEngine::Geometry;
using namespace OpenEngine::Scene;

namespace OpenEngine {
namespace Resources {
        
    void OpenGLESConverter::ConvertScene(ISceneNode* scene){
        scene->VisitSubNodes(*this);
    }

    void OpenGLESConverter::VisitMeshNode(MeshNode *node){
        MeshPtr mesh = node->GetMesh();
        GeometrySetPtr geom = mesh->GetGeometrySet();
        map<std::string, IBuffer*> attrs;
        AttributeBlocks::iterator attrItr = geom->GetAttributeLists().begin();
        
        while(attrItr != geom->GetAttributeLists().end()){
            attrs[attrItr->first] = ConvertToESBuffer(attrItr->second);
            ++attrItr;
        }
        NewGeometrySet* newGeom = new NewGeometrySet(attrs);
        
        IndicesPtr i = mesh->GetIndices();
        IIndices* indices = CreateIndices(i->GetSize(), i->GetData());

        NewMeshPtr newMesh = NewMeshPtr(new NewMesh(newGeom, mesh->GetMaterial(), 
                                                    indices, (NewMesh::GeometricType)mesh->GetType()));
        
        NewMeshNode* meshNode = new NewMeshNode(newMesh);

        node->GetParent()->ReplaceNode(node, meshNode);

        std::list<ISceneNode*> subNodes = node->subNodes;
        for (std::list<ISceneNode*>::iterator itr = subNodes.begin();
             itr != subNodes.end(); ++itr){
            node->RemoveNode(*itr);
            meshNode->AddNode(*itr);
        }
        
        meshNode->Accept(*this);
        
        //node->VisitSubNodes(*this);
    }
        
    IBuffer* OpenGLESConverter::ConvertToESBuffer(IDataBlockPtr data){
        switch(data->GetType()){
        case Types::UINT:
            return new OpenGLESBuffer<unsigned int>(data);
        case Types::INT:
            return new OpenGLESBuffer<int>(data);
        case Types::FLOAT:
            return new OpenGLESBuffer<float>(data);
        default:
            throw Core::NotImplemented("Unsupported Data Block configuration");
        }
        
        throw Core::NotImplemented("Unsupported Data Block configuration");
    }

}
}
