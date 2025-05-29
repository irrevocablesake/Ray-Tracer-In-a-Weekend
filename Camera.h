#ifndef CAMERA_H
#define CAMERA_H

#include "Point3.h"

class Camera{
    public:
        Point3 position;

        //distance b/w sensor and lens
        double focalLength;
        double vFOV;

        Camera() : position( 0, 0, 0 ) { }
};

#endif