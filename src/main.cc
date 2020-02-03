#include <cmath>
#include <fstream>
#include <iostream>
#include <limits>
#include <vector>

#include "vector.hh"
#include "shapes.hh"

Vec3f cast_ray(const Vec3f &origin, const Vec3f &dir, std::vector<Sphere> spheres) {
    float dist = std::numeric_limits<float>::max();
    for (size_t i = 0; i < spheres.size(); i++) {
        if (spheres[i].ray_intersect(origin, dir, dist))
            return Vec3f(0.4, 0.4, 0.3);
    }
    return Vec3f(0.2, 0.7, 0.8);
}

void render(std::vector<Sphere> spheres) {
    const int width = 1024;
    const int height = 768;
    const float fov = 30.f;
    std::vector<Vec3f> framebuffer(width * height);

    for (size_t j = 0; j < height; j++) {
        for (size_t i = 0; i < width; i++) {
            float x = (2 * (i + 0.5) / (float) width - 1) * std::tan(fov / 2.) *
                width / (float) height;
            float y = -(2 * (j + 0.5) / (float)height - 1) * std::tan(fov / 2.);
            Vec3f dir = Vec3f(x, y, -1).normalize();
            framebuffer[j * width + i] = cast_ray(Vec3f(0, 0, 0), dir, spheres);
        }
    }

    std::ofstream ofs;
    ofs.open("out.ppm");
    ofs << "P6\n" << width << " " << height << "\n255\n";
    for (size_t i = 0; i < height * width; i++) {
        for (size_t j = 0; j < 3; j ++) {
            ofs << (char)(255 * std::max(0.f, std::min(1.f, framebuffer[i][j])));
        }
    }
    ofs.close();
}

int main() {
    Sphere s(Vec3f(0, 0, -2), 0.1);
    Sphere s1(Vec3f(0.1, 0, -2), 0.1);
    Sphere s2(Vec3f(0, .1, -2), 0.1);
    Sphere s3(Vec3f(-0.1, -0.1, -2), 0.1);
    std::vector<Sphere> spheres = { s, s1, s2, s3 };
    render(spheres);
    return 0;
}
