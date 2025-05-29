#ifndef CAMERA_H
#define CAMERA_H

#include "Vector3.h"
#include "Point3.h"
#include "Ray.h"

class Camera{
    public:
        Point3 position;

        //distance b/w sensor and lens
        double focalLength;
        double vFOV;

        Point3 lookFrom;
        Point3 lookAt;
        Vector3 vup;

        Camera() : position( 0, 0, 0 ) { }

        void updatePosition() {
            position = Point3( lookFrom.x(), lookFrom.y(), lookFrom.z() );
        }

        void updateOrientation(){
            w = unitVector( ( lookFrom - lookAt ) );
            u = unitVector( cross( vup, w ) );
            v = cross( w, u );
        }

    public:
        Vector3 u;
        Vector3 v;
        Vector3 w;
};

#endif