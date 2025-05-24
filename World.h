#ifndef WORLD_H
#define WORLD_H

#include "Mesh.h"

#include <vector>
#include <memory>

using std::shared_ptr;

class World{
    public:
        std::vector< shared_ptr< Mesh > > meshList;

        World() {}

        void clear() {
            meshList.clear();
        }

        void add( shared_ptr< Mesh > mesh ){
            meshList.push_back( mesh );
        }

        raycast( Ray &ray ){
            bool hitAnything = false;

            for( const auto &mesh : meshList ){
                if( mesh -> hit( ray ) ){
                    hitAnything = true;
                }
            }

            return hitAnything;
        }
};

#endif