#ifndef PIXELSAMPLER_H
#define PIXELSAMPLER_H

#include "Vector3.h"
#include "Point3.h"
#include "Ray.h"
#include "Color3.h"
#include "Viewport.h"
#include "Camera.h"
#include "IntersectionManager.h"
#include "World.h"
#include "Material.h"

#include "random.h"

class PixelSampler{
    public:
        int samplesPerPixel;
        double average;
        Viewport viewport;
        Camera camera;

        PixelSampler() {} 
        PixelSampler( Camera &camera, Viewport &viewport, int samplesPerPixel ) : camera( camera ), viewport( viewport ), samplesPerPixel( samplesPerPixel ) {
            average = 1 / double( samplesPerPixel );
         }

        Color3 samplePixel( int i, int j, World &world );
        Vector3 sample();
        
        Color3 processPixelColor( Ray &ray, World &world );
};

Color3 PixelSampler::processPixelColor( Ray &ray, World &world ){
    Color3 white( 1.0, 1.0, 1.0 );
    Color3 blue( 0.5, 0.7, 1.0 );
    Color3 red( 1.0, 0.0, 0.0 );
    Color3 black( 0.0, 0.0, 0.0 );

    IntersectionManager intersectionManager;

    bool hit = world.raycast( ray, Interval( 0, INF ), intersectionManager );

    
    
    if( hit ){

        Ray scattered;
        Color3 attenuation;

        intersectionManager.material -> scatter( ray, attenuation, scattered, intersectionManager );

        return attenuation;
    }

    Vector3 normalizedDirection = normalizeVector( unitVector( ray.direction() ) );
    Color3 color = lerpColor( white, blue, normalizedDirection.y() );
    
    return blue;
}

Vector3 PixelSampler::sample() {
    return Vector3( generateRandom() - 0.5, generateRandom() - 0.5, 0 );
}

Color3 PixelSampler::samplePixel( int i, int j, World &world ){
    Color3 pixelColor( 0, 0, 0 );
    
    for( int count = 0; count < samplesPerPixel; count++ ){
        Vector3 offset = sample();
        Point3 pixelSample = viewport.pixel00Location + ( ( i + offset.x() ) * viewport.pixelDeltaHeight ) + ( ( j + offset.y() ) * viewport.pixelDeltaWidth );

        Ray ray( camera.position, ( pixelSample - camera.position ) );

        pixelColor += processPixelColor( ray, world );
    }

    return ( pixelColor * average );
}

#endif