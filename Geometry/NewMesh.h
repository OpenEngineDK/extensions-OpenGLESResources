// New Mesh.
// -------------------------------------------------------------------
// Copyright (C) 2011 OpenEngine.dk (See AUTHORS) 
// 
// This program is free software; It is covered by the GNU General 
// Public License version 2 or any later version. 
// See the GNU General Public License for more details (see LICENSE). 
//--------------------------------------------------------------------

#ifndef _OE_NEW_MESH_H_
#define _OE_NEW_MESH_H_

#include <boost/shared_ptr.hpp>

namespace OpenEngine {
    namespace Resources {
        class IIndices;
    }
    namespace Geometry {

        class Material;
        typedef boost::shared_ptr<Material> MaterialPtr;
        class NewGeometrySet;

        /**
         * Geometry Types (just happens to have the same values
         * as OpenGL...)
         */
        class NewMesh {
        public:
            enum GeometricType {
                POINTS         = 0x0000,
                LINES          = 0x0001,
                LINE_STRIP     = 0x0003,
                TRIANGLES      = 0x0004,
                TRIANGLE_STRIP = 0x0005,
                QUADS          = 0x0007};

        protected:
            NewGeometrySet* geom;
            MaterialPtr mat;
            Resources::IIndices* indices;
            GeometricType type;
        public:
            NewMesh(NewGeometrySet* geom,
                    MaterialPtr mat,
                    Resources::IIndices* indices,
                    GeometricType type);

            virtual ~NewMesh();
            
            virtual NewMesh* Clone();
            
            /**
             * Returns the geometry set used by this mesh.
             */
            inline NewGeometrySet* GetGeometrySet() const { return geom; }

            /**
             * Returns the material used by this mesh.
             */ 
            inline MaterialPtr GetMaterial() const { return mat; }

            /**
             * Return the indices.
             */
            inline Resources::IIndices* GetIndices() const { return indices; }

            /**
             * Returns the geometric type.
             */
            inline GeometricType GetType() const { return type; }
        };

    }
}

#endif
