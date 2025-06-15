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
    
    const int IMAGE_WIDTH = 600;
    const double ASPECT_RATIO = 16.0 / 9.0;
    Image image( IMAGE_WIDTH, ASPECT_RATIO );

    World world;

    auto material_ground = make_shared<Diffuse>(Color3(0.8, 0.8, 0.0));
    auto material_center = make_shared<Diffuse>(Color3(0.1, 0.2, 0.5));
    auto material_left   = make_shared<Dielectric>(1.50);
    auto material_bubble = make_shared<Dielectric>(1.00 / 1.50);
    auto material_right  = make_shared<Metal>(Color3(0.8, 0.6, 0.2), 1.0);

    world.add(make_shared<Sphere>(Point3( 0.0, -100.5, -1.0), 100.0, material_ground));
    world.add(make_shared<Sphere>(Point3( 0.0,    0.0, -1.2),   0.5, material_center));
    world.add(make_shared<Sphere>(Point3(-1.0,    0.0, -1.0),   0.5, material_left));
    world.add(make_shared<Sphere>(Point3(-1.0,    0.0, -1.0),   0.4, material_bubble));
    world.add(make_shared<Sphere>(Point3( 1.0,    0.0, -1.0),   0.5, material_right));

    Renderer renderer( world, image );

    renderer.samplesPerPixel = 10;
    renderer.maxDepth = 10;
    renderer.vFOV = 20.0;
    renderer.lookFrom = Point3( -2, 2, 1 );
    renderer.lookAt = Point3( 0, 0, -1 );
    renderer.vUp = Vector3( 0, 1, 0 );
    renderer.defocusAngle = 0;
    renderer.focusDistance = 10.0;

    renderer.initialize();
    renderer.render();

    return 0;
}