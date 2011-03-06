// New Mesh node.
// -------------------------------------------------------------------
// Copyright (C) 2011 OpenEngine.dk (See AUTHORS) 
// 
// This program is free software; It is covered by the GNU General 
// Public License version 2 or any later version. 
// See the GNU General Public License for more details (see LICENSE). 
//--------------------------------------------------------------------

#ifndef _OE_NEW_MESH_NODE_H_
#define _OE_NEW_MESH_NODE_H_

#include <Scene/ISceneNode.h>

#include <boost/shared_ptr.hpp>

namespace OpenEngine {
    namespace Geometry {
        class NewMesh;
        typedef boost::shared_ptr<NewMesh> NewMeshPtr;
    }
    namespace Scene {

        /**
         * Mesh node.
         * Acts as a simple node wrapping a mesh.
         *
         * @class MeshNode MeshNode.h Scene/MeshNode.h
         */
        class NewMeshNode : public ISceneNode {
            OE_SCENE_NODE(NewMeshNode, ISceneNode)
        protected:
            Geometry::NewMeshPtr mesh;

        public:
            NewMeshNode();
            NewMeshNode(const NewMeshNode& node);
            explicit NewMeshNode(Geometry::NewMeshPtr mesh);

            Geometry::NewMeshPtr GetMesh() const;
            void SetMesh(Geometry::NewMeshPtr mesh);
        };

    }
}

#endif
