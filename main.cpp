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
    
    const int IMAGE_WIDTH = 640;
    Image image( IMAGE_WIDTH );

    World world;

    world.add( make_shared< Sphere > ( Point3( -1, 0, -1 ), 0.5, make_shared< Dielectric >( 1.50 )));
    world.add( make_shared< Sphere > ( Point3( -1, 0, -1 ), 0.4, make_shared< Dielectric >( 1.00 / 1.50 )));
    world.add( make_shared< Sphere > ( Point3( 0, 0, -1 ), 0.5, make_shared< Diffuse >( Color3( 0.4, 0.4, 0.4 )  )));
    world.add( make_shared< Sphere > ( Point3( 1, 0, -1 ), 0.5, make_shared< Metal >( Color3( 1.0, 1.0, 1.0 ), 0.0  )));

    world.add( make_shared< Sphere > ( Point3( 0, -100.5, -1 ), 100, make_shared< Diffuse >( Color3( 0.4, 0.4, 0.4 )  )));

    Renderer renderer( world, image );
    renderer.initialize();
    renderer.render();

    return 0;
}