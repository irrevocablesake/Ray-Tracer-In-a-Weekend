#ifndef SPHERE_H
#define SPHERE_H

#include "Vector3.h"
#include "Mesh.h"

class Sphere : public Mesh{
    public:

        Point3 position;
        double radius;

        Sphere() : position( 0, 0, -1.5 ), radius( 0.5 ) { }
        Sphere( const Point3 &position, const double &radius ) : position( position ), radius( radius ) { }

        bool hit( Ray &ray ) const override {
            
            Vector3 spherePositionRay = position - ray.origin();
            double a = dot( ray.direction(), ray.direction() );
            double b = -2.0 * dot( ray.direction(), spherePositionRay );
            double c = dot( spherePositionRay, spherePositionRay ) - radius * radius;

            double discriminant = b * b - 4 * a * c;

            ray.hit = ( discriminant >= 0 );

            return ray.hit;
        }
};

#endif