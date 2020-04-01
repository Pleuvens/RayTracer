#include <cmath>
#include <fstream>
#include <iostream>
#include <limits>

#include "scene.hh"

constexpr size_t recursive_depth = 4;

bool Scene::scene_intersect(const Vec3f &origin, const Vec3f &dir,
        Vec3f &hit, Vec3f& normal, Material& material) const {
    float dist = std::numeric_limits<float>::max();
    for (size_t i = 0; i < spheres_.size(); i++) {
        float tmp_dist;
        if (spheres_[i].ray_intersect(origin, dir, tmp_dist) && tmp_dist < dist) {
            dist = tmp_dist;
            hit = origin + dir * dist;
            normal = (hit - spheres_[i].center_).normalize();
            material = spheres_[i].material_;
        }
    }
    return dist < std::numeric_limits<float>::max();
}

Vec3f Scene::cast_ray(const Vec3f &origin, const Vec3f &dir, size_t depth) const {
    Vec3f hit, normal;
    Material material;

    if (depth > recursive_depth ||
            !scene_intersect(origin, dir, hit, normal, material))
        return Vec3f(0.2, 0.7, 0.8);

/*
    Vec3f reflect_dir = Vec3f::reflect(dir, normal).normalize();
    Vec3f reflect_origin = Vec3f::sum(reflect_dir, normal) < 0
        ? hit - normal * 1e-3 : hit + normal * 1e+3;
    Vec3f reflect_color = cast_ray(reflect_origin, reflect_dir, depth + 1);
    Vec3f refract_dir = Vec3f::refract(dir, normal, material.refractive_index_).normalize();
    Vec3f refract_origin = Vec3f::sum(refract_dir, normal) < 0
        ? hit - normal * 1e-3 : hit + normal * 1e+3;
    Vec3f refract_color = cast_ray(refract_origin, refract_dir, depth + 1);
*/
    float diffuse_light_intensity = 0;
    float specular_light_intensity = 0;
    for (size_t i = 0; i < lights_.size(); i++) {
        Vec3f light_dir = (lights_[i].position_ - hit).normalize();
/* 
        float light_distance = (lights_[i].position_ - hit).norm();
        Vec3f shadow_origin = Vec3f::sum(light_dir, normal) < 0 ?
            hit - normal * 1e-3 : hit + normal * 1e-3;
        Vec3f shadow_hit, shadow_normal;
        Material tmp_material;

        if (scene_intersect(shadow_origin, light_dir, shadow_hit, shadow_normal,
                    tmp_material)
                && (shadow_hit - shadow_origin).norm() < light_distance)
            continue;
*/
        diffuse_light_intensity += lights_[i].intensity_ *
            std::max(0.f, Vec3f::sum(light_dir,normal));
        specular_light_intensity +=
            powf(std::max(0.f, Vec3f::sum(Vec3f::reflect(light_dir, normal), dir)),
                    material.specular_) * lights_[i].intensity_;
    }
    return //material.diffuse_ * diffuse_light_intensity * material.albedo_[0] +
        Vec3f(1., 1., 1.) * specular_light_intensity * material.albedo_[1];// +
        //reflect_color * material.albedo_[2] +
        //refract_color * material.albedo_[3];
}

void Scene::render() const {
    const int width = 1024;
    const int height = 768;
    const float fov = M_PI/2.;
    std::vector<Vec3f> framebuffer(width * height);

    for (size_t j = 0; j < height; j++) {
        for (size_t i = 0; i < width; i++) {
            float x = (2 * (i + 0.5) / (float) width - 1) * tan(fov / 2.) *
                width / (float) height;
            float y = -(2 * (j + 0.5) / (float)height - 1) * tan(fov / 2.);
            Vec3f dir = Vec3f(x, y, -1).normalize(); 
            framebuffer[j * width + i] = cast_ray(Vec3f(0, 0, 0), dir, 0);
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
