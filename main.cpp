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

    auto R = std::cos(PI/4);

    auto material_left  = make_shared<Diffuse>(Color3(0,0,1));
    auto material_right = make_shared<Diffuse>(Color3(1,0,0));

    world.add(make_shared<Sphere>(Point3(-R, 0, -1), R, material_left));
    world.add(make_shared<Sphere>(Point3( R, 0, -1), R, material_right));

    Renderer renderer( world, image );
    renderer.initialize();
    renderer.render();

    return 0;
}