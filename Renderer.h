#ifndef RENDERER_H
#define RENDERER_H

#include "Color3.h"
#include<iostream>

class Renderer{
    private:
        const int IMAGE_WIDTH;
        const int IMAGE_HEIGHT;
        
    public: 
        Renderer( const int &imageWidth, const int &imageHeight ) : IMAGE_WIDTH( imageWidth ), IMAGE_HEIGHT( imageHeight ) { };
        void render();

        void processPixelColor( std::ostream &out, const Color3 &pixelColor );
};

void Renderer::processPixelColor( std::ostream &out, const Color3 &pixelColor ){
    double rNormalized = pixelColor.r();
    double gNormalized = pixelColor.g();
    double bNormalized = pixelColor.b();
            
    int rChannel = 255 * rNormalized;
    int gChannel = 255 * gNormalized;
    int bChannel = 255 * bNormalized;

    std::cout << rChannel << ' ' << gChannel << ' ' << bChannel << '\n';
}

void Renderer::render(){
    
    std::cout << "P3\n" << IMAGE_WIDTH << ' ' << IMAGE_HEIGHT << '\n' << "255\n";

    for( int i = 0; i < IMAGE_HEIGHT; i++ ){

        std::clog << "\rScanlines remaining: " << IMAGE_HEIGHT - ( i + 1 ) << ' ' <<  std::flush; 

        for( int j = 0; j < IMAGE_WIDTH; j++ ){
            Color3 pixelColor = Color3( double(j) / ( IMAGE_WIDTH - 1 ), double(i) / ( IMAGE_HEIGHT - 1 ), 0.0 );
            processPixelColor( std::cout, pixelColor );
        }
    }

    std::clog << "\rDone.                               \n";
}

#endif