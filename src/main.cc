#include <cmath>
#include <fstream>
#include <iostream>
#include <limits>
#include <vector>

#include "vector.hh"
#include "shapes.hh"
#include "light.hh"

Vec3f reflect(const Vec3f& I, const Vec3f &N) {
    return I - N * 2.f * (I * N);
}

constexpr size_t recursive_depth = 4;

bool scene_intersect(const Vec3f &origin, const Vec3f &dir, std::vector<Sphere> spheres,
        Vec3f &hit, Vec3f& N, Material& material) {
    float dist = std::numeric_limits<float>::max();
    for (size_t i = 0; i < spheres.size(); i++) {
        float tmp_dist;
        if (spheres[i].ray_intersect(origin, dir, tmp_dist) && tmp_dist < dist) {
            dist = tmp_dist;
            hit = origin + dir * dist;
            N = (hit - spheres[i].center_).normalize();
            material = spheres[i].material_;
        }
    }
    return dist < std::numeric_limits<float>::max();
}

Vec3f cast_ray(const Vec3f &origin, const Vec3f &dir, std::vector<Sphere> spheres,
        std::vector<Light> lights, size_t depth = 0) {
    Vec3f hit, N;
    Material material;

    if (depth > recursive_depth ||
            !scene_intersect(origin, dir, spheres, hit, N, material))
        return Vec3f(0.2, 0.7, 0.8);

    Vec3f reflect_dir = reflect(dir, N).normalize();
    Vec3f reflect_origin = Vec3f::sum(reflect_dir, N) < 0
        ? hit - N * 1e-3 : hit + N * 1e+3;
    Vec3f reflect_color = cast_ray(reflect_origin, reflect_dir, spheres, lights,
            depth + 1);

    float diffuse_light_intensity = 0;
    float specular_light_intensity = 0;
    for (size_t i = 0; i < lights.size(); i++) {
        Vec3f light_dir = (lights[i].position_ - hit).normalize();
        
        float light_distance = (lights[i].position_ - hit).norm();
        Vec3f shadow_origin = Vec3f::sum(light_dir, N) < 0 ?
            hit - N * 1e-3 : hit + N * 1e-3;
        Vec3f shadow_hit, shadow_N;
        Material tmp_material;

        if (scene_intersect(shadow_origin, light_dir, spheres, shadow_hit, shadow_N,
                    tmp_material)
                && (shadow_hit - shadow_origin).norm() < light_distance)
            continue;

        diffuse_light_intensity += lights[i].intensity_ *
            std::max(0.f, Vec3f::sum(light_dir,N));
        specular_light_intensity += powf(std::max(0.f, Vec3f::sum(reflect(light_dir, N),
                        dir)), material.specular_) * lights[i].intensity_;
    }
    return material.diffuse_ * diffuse_light_intensity * material.albedo_[0] +
        Vec3f(1., 1., 1.) * specular_light_intensity * material.albedo_[1] +
        reflect_color * material.albedo_[2];
}

void render(std::vector<Sphere> spheres, std::vector<Light> lights) {
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
            framebuffer[j * width + i] = cast_ray(Vec3f(0, 0, 0), dir, spheres, lights);
        }
    }

    std::ofstream ofs;
    ofs.open("out.ppm");
    ofs << "P6\n" << width << " " << height << "\n255\n";
    for (size_t i = 0; i < height * width; i++) {
        Vec3f c = framebuffer[i];
        float max = std::max(c[0], std::max(c[1], c[2]));
        if (max > 1)
            c = c * (1. / max);
        for (size_t j = 0; j < 3; j ++) { 
            ofs << (char)(255 * std::max(0.f, std::min(1.f, framebuffer[i][j])));
        }
    }
    ofs.close();
}

int main() {
    Material ivory(Vec3f(0.6, 0.3, 0.1), Vec3f(0.4, 0.4, 0.3), 50.);
    Material red_rubber(Vec3f(0.9, 0.1, 0.0), Vec3f(0.3, 0.1, 0.1), 10.);
    Material mirror(Vec3f(0.0, 10.0, 0.8), Vec3f(1.0, 1.0, 1.0), 1425.);
    Sphere s(Vec3f(3, 0, -16), 2, ivory);
    Sphere s1(Vec3f(1.0, 1.5, -12), 2, mirror);
    Sphere s2(Vec3f( -1.5, 0.5, -18), 3, red_rubber);
    Sphere s3(Vec3f( -7, -5, -18), 4, mirror);
    std::vector<Sphere> spheres = { s, s1, s2, s3 };
    Light l(Light(Vec3f(20, -20, 20), 1.5));
    Light l1(Light(Vec3f( -30, -50, -25), 1.8));
    Light l2(Light(Vec3f( -30, -20,  30), 1.7));
    std::vector<Light> lights = { l, l1, l2 };
    render(spheres, lights);
    return 0;
}
