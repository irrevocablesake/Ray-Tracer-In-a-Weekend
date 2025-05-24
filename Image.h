#ifndef IMAGE_H
#define IMAGE_H

#include<iostream>

class Image{
    public:
        const double ASPECT_RATIO = 16.0 / 9.0;

        int width;
        int height;

        Image() : width( 2 ), height( 1 ) {}
        Image( const int &width ) : width( width ) {

            if( width <= 1 ){
                throw std::invalid_argument("Image Width must be atleast 1");
            }

            this -> width = width;
            this -> height = width / ASPECT_RATIO;
        }
};

#endif