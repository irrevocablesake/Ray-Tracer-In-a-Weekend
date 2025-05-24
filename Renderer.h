#ifndef RENDERER_H
#define RENDERER_H

#include "Vector3.h"
#include "Point3.h"
#include "Color3.h"
#include "Camera.h"
#include "Ray.h"
#include "Image.h"
#include "Viewport.h"
#include<iostream>

class Renderer{
    private:
        Image image;
        Viewport viewport;
        Camera camera;
        
    public: 
        Renderer( const Image &image ) : image( image ) {}

        void initialize();

        void render();
        void writePixelColor( std::ostream &out, const Color3 &pixelColor );
        Color3 processPixelColor( Ray &ray );
};

Color3 Renderer::processPixelColor( Ray &ray ){
    Color3 white( 1.0, 1.0, 1.0 );
    Color3 blue( 0.5, 0.7, 1.0 );
    Color3 red( 1.0, 0.0, 0.0 );

    Color3 color = lerpColor( red, blue, ray.direction().y() );
    
    return color;
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
            Point3 pixelPosition = viewport.topLeftCorner + ( i * viewport.pixelDeltaHeight ) + ( j * viewport.pixelDeltaWidth );

            Vector3 direction = unitVector( pixelPosition - camera.position );
            Vector3 normalizedDirection = normalizeVector( direction );
            
            Ray ray( camera.position, normalizedDirection );

            Color3 pixelColor = processPixelColor( ray );
            writePixelColor( std::cout, pixelColor );
        }
    }

    std::clog << "\rDone.                               \n";
}

#endif