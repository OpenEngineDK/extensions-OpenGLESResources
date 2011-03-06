// Mesh node.
// -------------------------------------------------------------------
// Copyright (C) 2007 OpenEngine.dk (See AUTHORS) 
// 
// This program is free software; It is covered by the GNU General 
// Public License version 2 or any later version. 
// See the GNU General Public License for more details (see LICENSE). 
//--------------------------------------------------------------------

#include <Scene/NewMeshNode.h>
#include <Geometry/NewMesh.h>

using namespace OpenEngine::Geometry;

namespace OpenEngine {
    namespace Scene {
        
        NewMeshNode::NewMeshNode() {
            mesh = NewMeshPtr();
        }

        NewMeshNode::NewMeshNode(const NewMeshNode& node) 
            : ISceneNode(node) {
            mesh = node.GetMesh();
        }

        NewMeshNode::NewMeshNode(NewMeshPtr mesh) {
            this->mesh = mesh;
        }
        
        NewMeshPtr NewMeshNode::GetMesh() const{
            return mesh;
        }

        void NewMeshNode::SetMesh(NewMeshPtr mesh){
            this->mesh = mesh;
        }

        
    }
}
