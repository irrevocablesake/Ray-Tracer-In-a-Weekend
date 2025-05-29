#ifndef MATERIAL_H
#define MATERIAL_H

#include "Color3.h"
#include "Ray.h"
#include "IntersectionManager.h"
#include "Random.h"
#include "Vector3.h"

class Material {
    public:
        virtual ~Material() = default;

        virtual bool scatter( const Ray &ray, Color3 &attenuation, Ray &scattered, IntersectionManager &intersectionManager ) const = 0;
};

class Normal : public Material {
    public:
        Normal() {}

        bool scatter( const Ray &ray, Color3 &attenuation, Ray &scattered, IntersectionManager &intersectionManager ) const override {
            scattered = Ray( intersectionManager.point, intersectionManager.normal );
            attenuation = 0.5 * Color3( scattered.direction().x() + 1, scattered.direction().y() + 1, scattered.direction().z() + 1 );
        
            return true;
        }
};

class Diffuse : public Material {
    public:
        Diffuse() {}
        Diffuse( Color3 color ) : albedo( color ) {}

        Vector3 reflected( const Vector3 &normal ) const{
            Vector3 unitVector = generateRandomUnitVector();
            if( dot( unitVector, normal ) > 0.0 ){
                return unitVector;
            }
            
            return -unitVector;
        }

        bool scatter( const Ray &ray, Color3 &attenuation, Ray &scattered, IntersectionManager &intersectionManager ) const override {
            Vector3 reflectedVector = intersectionManager.normal + reflected( intersectionManager.normal );

            if( reflectedVector.nearZero() ){
                reflectedVector = intersectionManager.normal;
            }
            
            scattered = Ray( intersectionManager.point, reflectedVector );
            attenuation = albedo;

            return true;
        }

    private:
        Color3 albedo;
};

class Metal : public Material {
    public:

        Metal( const Color3 &color, double fuzz ) : albedo( color ), fuzz( fuzz < 1 ? fuzz : 1 ) { }

        Vector3 reflected( const Vector3 & vector, const Vector3 &normal ) const{
            return vector - 2 * dot( vector, normal ) * normal;
        }

        bool scatter( const Ray &ray, Color3 &attenuation, Ray &scattered, IntersectionManager &intersectionManager ) const override {
            Vector3 reflectedVector = reflected( ray.direction(), intersectionManager.normal );
            reflectedVector = unitVector( reflectedVector ) + ( fuzz * generateRandomUnitVector() );
            scattered = Ray( intersectionManager.point, reflectedVector );
            attenuation = albedo;

            return ( dot( scattered.direction(), intersectionManager.normal ) > 0 );
        }

    private:
        Color3 albedo;
        double fuzz;
};

#endif