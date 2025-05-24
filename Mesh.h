#ifndef MESH_H
#define MESH_H

#include "Ray.h"

class Mesh {
    public: 
        virtual bool hit( Ray &ray ) const = 0;
};

#endif