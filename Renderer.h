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
#include "PixelSampler.h"
#include<iostream>

class Renderer{
    private:
        Image image;
        Viewport viewport;
        Camera camera;
        World world;
        PixelSampler pixelSampler;
        
        int samplesPerPixel = 100;

    public: 
        Renderer( const World &world, const Image &image ) : world( world ), image( image ) {}

        void initialize();

        void render();
        void writePixelColor( std::ostream &out, const Color3 &pixelColor );
};

inline double linearToGamma( double linearComponent ){
    if( linearComponent > 0 ){
        return std::sqrt( linearComponent );
    }

    return 0;
}

void Renderer::writePixelColor( std::ostream &out, const Color3 &pixelColor ){
    double rNormalized = pixelColor.r();
    double gNormalized = pixelColor.g();
    double bNormalized = pixelColor.b();
            
    double rGammaCorrected = linearToGamma( rNormalized );
    double gGammaCorrected = linearToGamma( gNormalized );
    double bGammaCorrected = linearToGamma( bNormalized );

    static const Interval intensity( 0.000, 1.000 );
    int rChannel = 255 * intensity.clamp( rGammaCorrected );
    int gChannel = 255 * intensity.clamp( gGammaCorrected );
    int bChannel = 255 * intensity.clamp( bGammaCorrected );

    std::cout << rChannel << ' ' << gChannel << ' ' << bChannel << '\n';
}

void Renderer::initialize(){

    camera.focalLength = 1.0;
    camera.vFOV = 90;
    viewport = Viewport( image, camera );
    pixelSampler = PixelSampler( camera, viewport, samplesPerPixel );
}

void Renderer::render(){

    std::cout << "P3\n" << image.width << ' ' << image.height << '\n' << "255\n";

    for( int i = 0; i < image.height; i++ ){

        std::clog << "\rScanlines remaining: " << image.height - ( i + 1 ) << ' ' <<  std::flush; 

        for( int j = 0; j < image.width; j++ ){
            Color3 pixelColor = pixelSampler.samplePixel( i, j, world );
            writePixelColor( std::cout, pixelColor );
        }
    }

    std::clog << "\rDone.                               \n";
}

#endif