#include "Renderer.h"

#include<iostream>
#include "Ray.h"
#include "Camera.h"
#include "Image.h"

int main(){

    
    const int IMAGE_WIDTH = 400;
    Image image( IMAGE_WIDTH );

    Renderer renderer( image );
    renderer.initialize();
    renderer.render();

    return 0;
}