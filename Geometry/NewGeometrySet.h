// GeometrySet.
// -------------------------------------------------------------------
// Copyright (C) 2011 OpenEngine.dk (See AUTHORS) 
// 
// This program is free software; It is covered by the GNU General 
// Public License version 2 or any later version. 
// See the GNU General Public License for more details (see LICENSE). 
//--------------------------------------------------------------------

#ifndef _OE_GEOMETRY_SET_H_
#define _OE_GEOMETRY_SET_H_

#include <Resources/Buffer.h>

#include <map>
#include <string>

namespace OpenEngine {
    namespace Geometry{

        /**
         * Typedef attribute lists.
         */
        typedef std::map<std::string, Resources::IBuffer*> AttributeLists;

        /**
         * The geometry set class contains all of the pr. vertex
         * information of a mesh.
         */
        class NewGeometrySet {
        protected:
            unsigned int size;
            AttributeLists attrs;
        public:
            NewGeometrySet() : size(0)  {}

            /**
             * Clones the data in the geometry set.
             *
             * @return A new GeometrySet with the cloned data.
             */
            NewGeometrySet* Clone();

            /**
             * Get the size of each IBuffer in the GeometrySet.
             */
            inline unsigned int GetSize() const { return size; }

            /**
             * Get the IBuffer corresponding to given attribute name.
             */
            inline Resources::IBuffer* GetAttributeList(const std::string name) const { 
                AttributeLists::const_iterator itr = attrs.find(name);
                if (itr == attrs.end()) return NULL;
                return itr->second;
            }

            /**
             * Get vertices.
             */
            inline Resources::Buffer<3, float>* GetVertices() const { return NULL; }

        };
    }
}

#endif
