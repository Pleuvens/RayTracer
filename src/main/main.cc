#include <iostream>
#include <cmath>
#include <optional>

#include "canvas.hh"
#include "ray.hh"

int main(void) {
    Point ray_origin(0, 0, -5);
    int wall_z = 10;
    float wall_size = 7.0;
    int canvas_pixels = 100;
    float pixel_size = wall_size / canvas_pixels;
    float half = wall_size / 2;
    Canvas canvas(canvas_pixels, canvas_pixels);
    Color color(1, 0, 0);
    Sphere shape;
    Material m;
    m.setColor(Color(1, 0.2, 1));
    shape.setMaterial(m);
    PointLight light(Point(-10, 10, -10), Color(1, 1, 1));

    for (int y = 0; y < canvas_pixels; y++)
    {
        auto world_y = half - pixel_size * y;
        for (int x = 0; x < canvas_pixels; x++)
        {
            auto world_x = -half + pixel_size * x;
            Point position(world_x, world_y, wall_z);
            Vector ray_direction(position - ray_origin);
            Ray r(ray_origin, ray_direction.normalize());
            auto xs = r.intersect(shape);
            
            auto hit = Intersection::hit(xs);

            if (hit != std::nullopt)
            {
                auto point = r.position(hit->getT());
                auto normal = hit->getObject().normalAt(point); 
                auto eye = Vector(r.getDirection() * -1);
                color = hit->getObject().getMaterial().lighting(light, point, eye,
                        normal);
                canvas.setPixel(y, x, color);
            }
        }
    }

    canvas.canvasToPPM("/tmp/test.ppm");
    return 0;
}
