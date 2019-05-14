#include <cmath>
#include <iostream>

#include "svati_parser.hh"

SvatiParser::SvatiParser(std::string filename_)
: Parser(filename_)
{
    infile = std::ifstream(filename);
}

void SvatiParser::parseCamera(Scene& scene)
{
    int width, height;
    float x, y, z, ux, uy, uz, vx, vy, vz, fov;

    std::string name;

    infile >> name >> width >> height >> x >> y >> z
            >> ux >> uy >> uz >> vx >> vy >> vz >> fov;

    scene.setCamera(Camera(width, height, Vector3(x, y, z),
                    Vector3(ux, uy, uz), Vector3(vx, vy, vz), fov * (std::atan(1.0) * 4) / 180 ));
}

void SvatiParser::parseLight(Scene& scene)
{
    std::string name;
    float r, g, b;

    infile >> name >> r >> g >> b;

    AmbientLight a_light = AmbientLight(Color(r,g,b), Vector3());

    infile >> name;

    std::vector<DirectionalLight> d_lights;
    std::vector<PointLight> p_lights;

    while (name == "d_light" || name == "p_light")
    {
        float x, y, z;

        infile >> r >> g >> b >> x >> y >> z;

        if (name == "d_light")
        {
            d_lights.push_back(DirectionalLight(Color(r, g, b), Vector3(x, y, z)));
        } else
        {
            p_lights.push_back(PointLight(Color(r, g, b), Vector3(x, y, z)));
        }
        infile >> name;
    }

    scene.setLight(a_light, p_lights, d_lights);
}

void SvatiParser::parsePrimitive(Scene& scene)
{
    std::string name;
    int nb_meshes;

    infile >> nb_meshes;

    std::vector<Object> objects;

    for (int i = 0; i < nb_meshes; ++i)
    {
        Object o = Object();
        if (!(infile >> name))
            break;
        Material m = Material();
        std::vector<Vector3> v;
        std::vector<Vector3> vn;
        while (name[0] != 'v')
        {
            float value, r, g, b;

            if (name[0] != 'K')
                infile >> value;
            else
                infile >> r >> g >> b;
            
            if (name == "d")
                m.setDissolve(value);
            else if (name == "Ka")
                m.setAmbientReflectivity(Color(r, g, b));
            else if (name == "Kd")
                m.setDiffuseReflectivity(Color(r, g, b));
            else if (name == "Ks")
                m.setSpecularReflectivity(Color(r, g, b));
            else if (name == "Ns")
                m.setSpecularExponent(value);
            else if (name == "Ni")
                m.setOpticalDensity(value);
            else if (name == "Nr")
                m.setReflectionCoefficient(value);

            infile >> name;
        }
        while (name[0] == 'v')
        {
            float x, y, z;
            infile >> x >> y >> z;
            if (name == "v")
            {
                v.push_back(Vector3(x, y, z));
            } else
            {
                vn.push_back(Vector3(x, y, z));
            }
            
            if (!(infile >> name))
                break;
        }
        o.setMaterial(m);
        o.setVertex(v);
        o.setVertexNormal(vn);
        o.setTriangles();
        objects.push_back(o);
    }
    scene.setPrimitives(objects);
    std::cout << objects.size() << std::endl;
}

Scene SvatiParser::parse()
{
    Scene scene = Scene();

    parseCamera(scene);
    parseLight(scene);
    parsePrimitive(scene);

    return scene;
}