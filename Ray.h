#ifndef RAY_H
#define RAY_H

#include "Point3.h"
#include "Vector3.h"

class Ray{
    public:
        Ray() {}
        Ray( const Point3 &origin, const Vector3 &displacement ) : _origin( origin ), _displacement( displacement ) {}

        const Point3 &origin() const;
        const Vector3 &displacement() const;

        Point3 at( double t ) const;

    private:
        Point3 _origin;
        Vector3 _displacement;
};

const Point3& Ray::origin() const {
    return _origin;
}

const Vector3& Ray::displacement() const {
    return _displacement;
}

inline Point3 operator+( const Point3 &point, const Vector3 &vector ) {
    return Point3( point.x() + vector.x(), point.y() + vector.y(), point.z() + vector.z() );
}

Point3 Ray::at( double t ) const {
    return _origin + t * _displacement;
}

#endif