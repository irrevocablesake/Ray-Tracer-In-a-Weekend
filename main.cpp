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
    
    const int IMAGE_WIDTH = 800;
    const double ASPECT_RATIO = 1.0;
    Image image( IMAGE_WIDTH, ASPECT_RATIO );

    World world;

    auto groundMaterial = make_shared<Diffuse>(Color3(0.5, 0.5, 0.5));
    auto material = make_shared<Diffuse>(Color3(0.8, 0.2, 0.2));

    world.add(make_shared<Sphere>(Point3( 0.0, -100.45, -1.0), 100.0, groundMaterial));
    world.add(make_shared<Sphere>(Point3( 0.0,    0.0, -1),   0.45, material));

    Renderer renderer( world, image );

    renderer.samplesPerPixel = 500;
    renderer.maxDepth = 50;
    renderer.vFOV = 20.0;
    renderer.lookFrom = Point3( -2, 0.5, 2.0 );
    renderer.lookAt = Point3( 0, 0, -1 );
    renderer.vUp = Vector3( 0, 1, 0 );

    renderer.defocusAngle = 0.4;
    renderer.focusDistance = 3.64;

    renderer.initialize();
    renderer.render();

    return 0;
}