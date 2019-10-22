#include <iostream>
#include <cmath>
#include <optional>

#include "camera.hh"
#include "canvas.hh"
#include "constants.hh"
#include "ray.hh"

int main(void) {
    Sphere floor;
    floor.setTransform(Matrix::scaling(30, 0.03, 30));
    Material floor_m;
    floor_m.setColor(Color(1, 0.9, 0.9));
    floor_m.setSpecular(0);
    floor.setMaterial(floor_m);

    Sphere left_wall;
    left_wall.setTransform(Matrix::translation(0, 0, 15)
                           * (Matrix::rotationY(-PI / 4)
                           * (Matrix::rotationX(PI / 2)
                           * Matrix::scaling(30, 0.03, 30))));
    left_wall.setMaterial(floor_m);

    Sphere right_wall;
    right_wall.setTransform(Matrix::translation(0, 0, 15)
                           * (Matrix::rotationY(PI / 4)
                           * (Matrix::rotationX(PI / 2)
                           * Matrix::scaling(30, 0.03, 30))));
    right_wall.setMaterial(floor_m);

    Sphere middle;
    middle.setTransform(Matrix::translation(-1.5, 3, 1.5));
    Material middle_m;
    middle_m.setColor(Color(0.1, 1, 0.5));
    middle_m.setDiffuse(0.7);
    middle_m.setSpecular(0.3);
    middle.setMaterial(middle_m);

    Sphere right;
    right.setTransform(Matrix::translation(4.5, 1.5, -1.5)
                       * Matrix::scaling(1.5, 1.5, 1.5));
    Material right_m;
    right_m.setColor(Color(0.5, 1, 0.1));
    right_m.setDiffuse(0.7);
    right_m.setSpecular(0.3);
    right.setMaterial(right_m);

    Sphere left;
    left.setTransform(Matrix::translation(-4.5, 0.99, -2.25)
                      * Matrix::scaling(0.99, 0.99, 0.99));
    Material left_m;
    left_m.setColor(Color(1, 0.8, 0.1));
    left_m.setDiffuse(0.7);
    left_m.setSpecular(0.3);
    left.setMaterial(left_m);

    PointLight light(Point(-30, 30, -30), Color(1, 1, 1));

    World w;
    w.setObjects(std::vector<Sphere>({floor, left_wall, right_wall, middle,
                                      right, left}));
    w.setLights(std::vector<PointLight>({light}));

    Camera c(150, 300, PI / 3);
    c.setTransform(Matrix::viewTransform(Point(0, 4.5, -15), Point(0, 3, 0),
                                         Vector(1, 0, 0)));
    Canvas canvas = c.render(w);
    canvas.canvasToPPM("/tmp/test.ppm");
    return 0;
}
