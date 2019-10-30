#include <algorithm>
#include <iterator>

#include "op_overloading.hh"
#include "sphere.hh"
#include "world.hh"

#include "test_world.hpp"

World World::defaultWorld()
{
    World w;
    w.addLight(std::make_shared<PointLight>(Point(-10, 10, -10),
                    Color(1, 1, 1)));
    Material m;
    m.setColor(Color(0.8, 1.0, 0.6));
    m.setDiffuse(0.7);
    m.setSpecular(0.2);
    Sphere s1;
    s1.setMaterial(m);
    Sphere s2;
    s2.setTransform(Matrix::scaling(0.5, 0.5, 0.5));
    w.addObject(std::make_shared<Sphere>(s1));
    w.addObject(std::make_shared<Sphere>(s2));
    return w;
}

World::Object_p World::getObject(const int index) const
{
    return _objects.at(index);
}

World::Light_p World::getLight(const int index) const
{
    return _lights.at(index);
}

bool World::contains(Object_p o) const noexcept
{
    for (size_t i = 0; i < _objects.size(); i++)
    {
        if (*(_objects[i]) == *o)
            return true;
    }
    return false;
}

bool World::contains(Light_p l) const noexcept
{
    for (size_t i = 0; i < _lights.size(); i++)
    {
        if (*(_lights[i]) == *l)
            return true;
    }
    return false;
}

void World::addObject(Object_p o) noexcept
{
    _objects.push_back(o);
}

void World::addLight(Light_p l) noexcept
{
    _lights.push_back(l);
}

std::vector<Intersection> World::intersect(Ray r)
{
   std::vector<Intersection> res;
   res.reserve(_objects.size() * 2);
   for (auto object = _objects.begin(); object != _objects.end(); object++)
   {
       auto xs = r.intersect(**object);
       res.insert(res.end(), xs.begin(), xs.end());
   }
   std::sort(res.begin(), res.end());
   return res;
}

Color World::shadeHit(Intersection comps, int remaining)
{
    Color c = Color::black();
    for (size_t i = 0; i < _lights.size(); i++)
    {
        c += comps.getObject().getMaterial().lighting(*getLight(i),
            comps.getPoint(), comps.getEyeVector(), comps.getNormalVector(),
            isShadowed(comps.getOverPoint()));
    }
    return c + reflectedColor(comps, remaining); 
}

Color World::colorAt(Ray r, int remaining) 
{
    auto xs = intersect(r);
    auto hit = Intersection::hit(xs);
    if (hit == std::nullopt)
        return Color::black();
    auto comps = r.prepareComputations(*hit);
    return shadeHit(comps, remaining);
}

bool World::isShadowed(Point point)
{
    Vector v = Vector(getLight(0)->getPosition() - point);
    auto distance = v.magnitude();
    auto direction = v.normalize();

    Ray r(point, direction);
    auto xs = intersect(r);
    auto hit = Intersection::hit(xs);
    if (hit != std::nullopt && hit->getT() < distance)
        return true;
    return false;
}

Color World::reflectedColor(Intersection i, int remaining)
{
    if (!remaining || isEqual(i.getObject().getMaterial().getReflective(), 0))
        return Color::black();
    Ray reflect_ray(i.getOverPoint(), i.getReflectVector());
    Color color = colorAt(reflect_ray, remaining - 1);
    return color * i.getObject().getMaterial().getReflective();
}
