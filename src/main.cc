#include "scene.hh"

int main() {
    Material      ivory(1.0, Vec4f(0.6,  0.3, 0.1, 0.0), Vec3f(0.4, 0.4, 0.3),   50.);
    Material      glass(1.5, Vec4f(0.0,  0.5, 0.1, 0.8), Vec3f(0.4, 0.4, 0.3),   50.);
    Material red_rubber(1.0, Vec4f(0.9,  0.1, 0.0, 0.0), Vec3f(0.3, 0.1, 0.1),   10.);
    Material     mirror(1.0, Vec4f(0.0, 10.0, 0.8, 0.0), Vec3f(1.0, 1.0, 1.0), 1425.);
    
    Sphere  s(Vec3f(  -3,    0, -16), 2,      ivory);
    Sphere s1(Vec3f(-1.0, -1.5, -12), 2,     mirror);
    Sphere s2(Vec3f( 1.5, -0.5, -18), 3, red_rubber);
    Sphere s3(Vec3f(   7,    5, -18), 4,      glass);
    std::vector<Sphere> spheres = { s, s1, s2, s3 };
    
    Light  l(Light(Vec3f(-20, 20,  20), 1.5));
    Light l1(Light(Vec3f( 30, 50, -25), 1.8));
    Light l2(Light(Vec3f( 30, 20,  30), 1.7));
    std::vector<Light> lights = { l, l1, l2 };

    Scene scene(lights, spheres);
    
    scene.render();
    return 0;
}
