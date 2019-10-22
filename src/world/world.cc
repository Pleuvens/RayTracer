#include <algorithm>
#include <iterator>

#include "op_overloading.hh"
#include "world.hh"

#include "test_world.hpp"

World World::defaultWorld()
{
    World w;
    w.setLights(std::vector<PointLight>({PointLight(Point(-10, 10, -10),
                    Color(1, 1, 1))}));
    Material m;
    m.setColor(Color(0.8, 1.0, 0.6));
    m.setDiffuse(0.7);
    m.setSpecular(0.2);
    Sphere s1;
    s1.setMaterial(m);
    Sphere s2;
    s2.setTransform(Matrix::scaling(0.5, 0.5, 0.5));
    w.setObjects(std::vector<Sphere>({s1, s2}));
    return w;
}

std::vector<Intersection> World::intersect(Ray r)
{
   std::vector<Intersection> res;
   res.reserve(_objects.size() * 2);
   for (auto object = _objects.begin(); object != _objects.end(); object++)
   {
       auto xs = r.intersect(*object);
       res.insert(res.end(), xs.begin(), xs.end());
   }
   std::sort(res.begin(), res.end());
   return res;
}

Color World::shadeHit(const Intersection& comps)
{
    Color c = Color::black();
    for (size_t i = 0; i < _lights.size(); i++)
    {
        c += comps.getObject().getMaterial().lighting(_lights[i],
            comps.getPoint(), comps.getEyeVector(), comps.getNormalVector(),
            isShadowed(comps.getOverPoint()));
    }
    return c; 
}

Color World::colorAt(Ray r) 
{
    auto xs = intersect(r);
    auto hit = Intersection::hit(xs);
    if (hit == std::nullopt)
        return Color::black();
    auto comps = r.prepareComputations(*hit);
    return shadeHit(comps);
}

bool World::isShadowed(Point point)
{
    Vector v = Vector(_lights[0].getPosition() - point);
    auto distance = v.magnitude();
    auto direction = v.normalize();

    Ray r(point, direction);
    auto xs = intersect(r);
    auto hit = Intersection::hit(xs);
    if (hit != std::nullopt && hit->getT() < distance)
        return true;
    return false;
}
