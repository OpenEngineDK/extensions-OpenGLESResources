// Mesh.
// -------------------------------------------------------------------
// Copyright (C) 2010 OpenEngine.dk (See AUTHORS) 
// 
// This program is free software; It is covered by the GNU General 
// Public License version 2 or any later version. 
// See the GNU General Public License for more details (see LICENSE). 
//--------------------------------------------------------------------

#include <Geometry/NewMesh.h>

#include <Geometry/NewGeometrySet.h>
#include <Core/Exceptions.h>

namespace OpenEngine {
    namespace Geometry {
        NewMesh::NewMesh(NewGeometrySet* geom,
                         Material* mat,
                         Resources::IIndices* indices,
                         GeometricType type)
            : geom(geom), mat(mat), indices(indices), type(type) {}
        
        NewMesh::~NewMesh(){}
            
        NewMesh* NewMesh::Clone(){
            throw Core::NotImplemented();
        }
        
    }
}
