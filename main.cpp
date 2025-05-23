#include "Renderer.h"

#include<iostream>
#include "Ray.h"

int main(){

    const int IMAGE_HEIGHT = 400;
    const int IMAGE_WIDTH = 400;

    Renderer renderer( IMAGE_WIDTH, IMAGE_HEIGHT );
    renderer.render();

    return 0;
}