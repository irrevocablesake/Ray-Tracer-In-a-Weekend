#ifndef MATERIAL_H
#define MATERIAL_H

#include "Color3.h"
#include "Ray.h"
#include "IntersectionManager.h"

class Material {
    public:
        virtual ~Material() = default;

        virtual void scatter( const Ray &ray, Color3 &attenuation, Ray &scattered, IntersectionManager &intersectionManager ) const = 0;
};

class Normal : public Material {
    public:
        Normal() {}

        void scatter( const Ray &ray, Color3 &attenuation, Ray &scattered, IntersectionManager &intersectionManager ) const override {
            scattered = Ray( intersectionManager.point, intersectionManager.normal );
            attenuation = 0.5 * Color3( scattered.direction().x() + 1, scattered.direction().y() + 1, scattered.direction().z() + 1 );
        }
};

#endif