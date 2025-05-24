#include "Renderer.h"

#include<iostream>
#include "Ray.h"
#include "Camera.h"
#include "Image.h"
#include "World.h"
#include "Sphere.h"

#include <memory>

using std::make_shared;

int main(){

    
    const int IMAGE_WIDTH = 400;
    Image image( IMAGE_WIDTH );

    World world;

    world.add( make_shared< Sphere > ());
    world.add( make_shared< Sphere > ( Point3( -2, 0, -3 ), 0.3 ));

    Renderer renderer( world, image );
    renderer.initialize();
    renderer.render();

    return 0;
}