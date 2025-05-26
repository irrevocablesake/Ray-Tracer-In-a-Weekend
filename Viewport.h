#ifndef VIEWPORT_H
#define VIEWPORT_H

#include "Camera.h"
#include "Image.h"
#include "Vector3.h"
#include "Point3.h"
#include "Ray.h"

class Viewport {
    public: 
        double width;
        double height;

        Point3 position;

        Vector3 widthVector;
        Vector3 heightVector;

        Vector3 pixelDeltaWidth;
        Vector3 pixelDeltaHeight;

        Point3 topLeftCorner;

        Point3 pixel00Location;

        //is this correct to use
        double shrinkFactor = 0.009;

        Viewport() {} 

        Viewport( const Image &image, const Camera &camera ) {
            width = shrinkFactor * image.width;
            height = width / ( double ( image.width ) / image.height );

            position = camera.position - Vector3( 0, 0, camera.focalLength );

            widthVector = Vector3( width, 0, 0 );
            heightVector = Vector3( 0, -height, 0 );

            pixelDeltaWidth = widthVector / image.width;
            pixelDeltaHeight = heightVector / image.height;

            topLeftCorner = position - widthVector / 2 - heightVector / 2;

            pixel00Location = topLeftCorner + 0.5 * ( pixelDeltaWidth + pixelDeltaHeight  );
        }
};

#endif