#ifndef RENDERER_H
#define RENDERER_H

#include "Vector3.h"
#include "Point3.h"
#include "Color3.h"
#include "Camera.h"
#include "Ray.h"
#include "Image.h"
#include "Viewport.h"
#include "World.h"
#include "Interval.h"
#include "IntersectionManager.h"
#include "Material.h"
#include<iostream>

class Renderer{
    private:
        Image image;
        Viewport viewport;
        Camera camera;
        World world;
        
    public: 
        Renderer( const World &world, const Image &image ) : world( world ), image( image ) {}

        void initialize();

        void render();
        void writePixelColor( std::ostream &out, const Color3 &pixelColor );
        Color3 processPixelColor( Ray &ray );
};

Color3 Renderer::processPixelColor( Ray &ray ){
    Color3 white( 1.0, 1.0, 1.0 );
    Color3 blue( 0.5, 0.7, 1.0 );
    Color3 red( 1.0, 0.0, 0.0 );
    Color3 black( 0.0, 0.0, 0.0 );

    IntersectionManager intersectionManager;

    bool hit = world.raycast( ray, Interval( 0, INF ), intersectionManager );

    
    
    if( hit ){

        Ray scattered;
        Color3 attenuation;

        intersectionManager.material -> scatter( ray, attenuation, scattered, intersectionManager ) ){
        
        return attenuation;
    }

    Vector3 normalizedDirection = normalizeVector( unitVector( ray.direction() ) );
    Color3 color = lerpColor( white, blue, normalizedDirection.y() );
    
    return blue;
}

void Renderer::writePixelColor( std::ostream &out, const Color3 &pixelColor ){
    double rNormalized = pixelColor.r();
    double gNormalized = pixelColor.g();
    double bNormalized = pixelColor.b();
            
    int rChannel = 255 * rNormalized;
    int gChannel = 255 * gNormalized;
    int bChannel = 255 * bNormalized;

    std::cout << rChannel << ' ' << gChannel << ' ' << bChannel << '\n';
}

void Renderer::initialize(){

    camera.focalLength = 1.0;
    viewport = Viewport( image, camera );
}

void Renderer::render(){

    std::cout << "P3\n" << image.width << ' ' << image.height << '\n' << "255\n";

    for( int i = 0; i < image.height; i++ ){

        std::clog << "\rScanlines remaining: " << image.height - ( i + 1 ) << ' ' <<  std::flush; 

        for( int j = 0; j < image.width; j++ ){
            Point3 pixelPosition = viewport.pixel00Location + ( i * viewport.pixelDeltaHeight ) + ( j * viewport.pixelDeltaWidth );

            Ray ray( camera.position, pixelPosition - camera.position  );

            Color3 pixelColor = processPixelColor( ray );
            writePixelColor( std::cout, pixelColor );
        }
    }

    std::clog << "\rDone.                               \n";
}

#endif