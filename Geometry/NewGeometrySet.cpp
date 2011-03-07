// GeometrySet.
// -------------------------------------------------------------------
// Copyright (C) 2011 OpenEngine.dk (See AUTHORS) 
// 
// This program is free software; It is covered by the GNU General 
// Public License version 2 or any later version. 
// See the GNU General Public License for more details (see LICENSE). 
//--------------------------------------------------------------------

#include <Geometry/NewGeometrySet.h>

#include <Core/Exceptions.h>

namespace OpenEngine {
    namespace Geometry{

        NewGeometrySet::NewGeometrySet(std::map<std::string, Resources::IBuffer*> attrs)
            : attrs(attrs) {
            size = attrs.begin()->second->GetSize();
#if OE_SAFE
            AttributeLists::const_iterator itr = attrs.begin();
            while (itr != attrs.end()){
                if (itr->second->GetSize() != size)
                    throw Core::Exception(itr->first + " not of same size as other IBuffers.");
                ++itr;
            }
#endif
        }

        NewGeometrySet* NewGeometrySet::Clone(){
            throw Core::NotImplemented("NewGeometrySet clone not implemented yet.");
        }

    }
}
