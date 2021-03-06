#include <iostream>
#include <cmath>
#include <optional>

#include "camera.hh"
#include "canvas.hh"
#include "constants.hh"
#include "plane.hh"
#include "ray.hh"
#include "sphere.hh"

int main(void) {
    Plane floor;
    Material floor_m;
    floor_m.setColor(Color(1, 0.9, 0.9));
    floor_m.setSpecular(0);
    floor.setMaterial(floor_m);

    Plane left_wall;
    left_wall.setTransform(Matrix::translation(0, 0, 5)
                           * (Matrix::rotationY(PI / 4)
                           * (Matrix::rotationX(PI / 2))));
    left_wall.setMaterial(floor_m);

    Plane right_wall;
    right_wall.setTransform(Matrix::translation(0, 0, 5)
                           * (Matrix::rotationY(-PI / 4)
                           * (Matrix::rotationX(-PI / 2))));
    right_wall.setMaterial(floor_m);

    Sphere middle;
    middle.setTransform(Matrix::translation(0, 1, 0.5));
    Material middle_m;
    middle_m.setColor(Color(0.1, 1, 0.5));
    middle_m.setDiffuse(0.7);
    middle_m.setSpecular(0.3);
    middle.setMaterial(middle_m);

    Sphere right;
    right.setTransform(Matrix::translation(-1, 0.75, -0.5)
                       * Matrix::scaling(0.75, 0.75, 0.75));
    Material right_m;
    right_m.setColor(Color(0.5, 1, 0.1));
    right_m.setDiffuse(0.7);
    right_m.setSpecular(0.3);
    right.setMaterial(right_m);

    Sphere left;
    left.setTransform(Matrix::translation(0.5, 0.5, -0.75)
                      * Matrix::scaling(0.5, 0.5, 0.5));
    Material left_m;
    left_m.setColor(Color(1, 0.8, 0.1));
    left_m.setDiffuse(0.7);
    left_m.setSpecular(0.3);
    left.setMaterial(left_m);

    PointLight light(Point(-10, 10, -10), Color(1, 1, 1));

    World w;
    w.addObject(std::make_shared<Plane> (floor));
    //w.addObject(std::make_shared<Plane> (left_wall));
    //w.addObject(std::make_shared<Plane> (right_wall));
    w.addObject(std::make_shared<Sphere> (middle));
    w.addObject(std::make_shared<Sphere> (right));
    w.addObject(std::make_shared<Sphere> (left));
    w.addLight(std::make_shared<PointLight> (light));

    Camera c(50, 100, PI / 3);
    c.setTransform(Matrix::viewTransform(Point(0, 1.5, -5), Point(0, 1, 0),
                                         Vector(1, 0, 0)));
    Canvas canvas = c.render(w);
    canvas.canvasToPPM("/tmp/test.ppm");
    return 0;
}
