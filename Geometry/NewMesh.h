// New Mesh.
// -------------------------------------------------------------------
// Copyright (C) 2010 OpenEngine.dk (See AUTHORS) 
// 
// This program is free software; It is covered by the GNU General 
// Public License version 2 or any later version. 
// See the GNU General Public License for more details (see LICENSE). 
//--------------------------------------------------------------------

#ifndef _OE_NEW_MESH_H_
#define _OE_NEW_MESH_H_

namespace OpenEngine {
    namespace Geometry {
    
        class Material;
        typedef boost::shared_ptr<Material> MaterialPtr;
        class NewGeometrySet;
        typedef boost::shared_ptr<NewGeometrySet> NewGeometrySetPtr;

        /**
         * Geometry Types (just happens to have the same values
         * as OpenGL...)
         */
        enum Type {
            POINTS         = 0x0000,
            LINES          = 0x0001,
            LINE_STRIP     = 0x0003,
            TRIANGLES      = 0x0004,
            TRIANGLE_STRIP = 0x0005,
            QUADS          = 0x0007};

        class NewMesh {
        protected:
        public:
            NewMesh() {}
        };

    }
}

#endif
