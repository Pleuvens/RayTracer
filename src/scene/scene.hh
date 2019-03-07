#pragma once

#include <vector>

#include "../utils/vector3.hh"
#include "../camera/camera.hh"
#include "../lights/ambient_light.hh"
#include "../lights/directional_light.hh"
#include "../lights/point_light.hh"
#include "../objects/object.hh"
#include "../raytracer/ray.hh"

class Scene
{
    public:
        Scene();
        Scene(Camera cam_,
        std::vector<Object> objects_,
        AmbientLight alight,
        std::vector<PointLight> plights,
        std::vector<DirectionalLight> dlights);

        inline void setCamera(const Camera& camera_) { camera = camera_; }
        void setLight(const AmbientLight& ambient, const std::vector<PointLight>& points, const std::vector<DirectionalLight>& directionals);
        void setPrimitives(const std::vector<Object> objs);

        void setScene();

        void setOutput();

    protected:
        Camera camera;
        int obj_count;
        std::vector<Object> objects;
        AmbientLight a_light;
        std::vector<PointLight> p_lights;
        std::vector<DirectionalLight> d_lights;
        int r_width;
        int r_height;
        std::vector<Color> pixels;
};