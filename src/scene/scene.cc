#include <cmath>

#include "scene.hh"

Scene::Scene(Camera cam_, int objcount,
        std::vector<Object> objects_,
        AmbientLight alight,
        std::vector<PointLight> plights,
        std::vector<DirectionalLight> dlights)
{
    camera = cam_;
    objects = objects_;
    a_light = alight;
    p_lights = plights;
    d_lights = dlights;
}

void Scene::setScene()
{
    camera.getU().normalize();
    camera.getV().normalize();

    Vector3 w = camera.getU() * camera.getV();

    w = w.inverse();

    float L = (camera.getWidth() / 2) / tan(camera.getFOV() / 2);

    Vector3 c = camera.getPos() + w * L;

    r_width = camera.getWidth();
    r_height = camera.getHeight();

    for (int i = 0; i < r_width * r_height; i++)
        pixels.push_back(Color(0, 0, 0));

    for (int y = -camera.getHeight() / 2; y < camera.getHeight() / 2; y++)
    {
        for (int x = -camera.getWidth() / 2; x < camera.getWidth() / 2; x++)
        {
            Vector3 p = c + camera.getU() * x + camera.getV() * y;

            Vector3 d = Vector3::fromPoints(camera.getPos(), p);

            Ray r = Ray(camera.getPos(), d.normalize());

            int m = y + camera.getHeight() / 2;
            int n = x + camera.getWidth() / 2;

            int index_obj = -1;
            int index_tt = -1;
            float distance = 0;
            Vector3 inters = Vector3::fromPoints(camera.getPos(), p);

            for (int i = 0; i < obj_count; ++i)
            {
                for (int j = 0; j < objects[i].getVSize() / 3; j++)
                {
                    if (r.triangleIntersection(objects[i].getTriangles[j], inters))
                    {
                        if (index_obj < 0 || distance > Vector3::distance(r.getOrigin(), inters))
                        {
                            index_obj = i;
                            index_tt = j;
                            distance = Vector3::distance(r.getOrigin(), inters);
                        }
                    }
                }
            }

            if (index_obj > -1)
            {
                Color ak = objects[index_obj].getMaterial().getAmbientReflectivity() * a_light.getColor();
                for (int l = 0; l < d_lights.size(); l++)
                {
                    ak += d_lights[l].apply(objects[index_obj], index_tt);
                }

                for (int l = 0; l < p_lights.size(); l++)
                {
                    p_lights[l].setDirection(Vector3::fromPoints(p_lights[l].getPos(),inters));
                    ak += p_lights[l].apply(objects[index_obj], index_tt, Vector3::distance(p_lights[l].getPos(), inters));
                }
                pixels[m * r_width + n] = ak;
            }
        }
    }
}