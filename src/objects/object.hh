#pragma once

#include <vector>

#include "../utils/color.hh"
#include "../utils/vector3.hh"
#include "../material/material.hh"
#include "triangle.hh"

class Object
{
    public:
        Object(int vsize, int vnsize, Material m_,
        std::vector<Vector3> v_, std::vector<Vector3> vn_,
        std::vector<Vector3> triangles_, Color color_, Material material_);

        int getVSize();
        int getVnSize();
        Material getM();
        std::vector<Vector3> getV();
        std::vector<Vector3> getVn();
        std::vector<Triangle> getTriangles();
        Color getColor();
        Material getMaterial();

        void setVSize(int vsize);
        void setVnSize(int vnsize);
        void setM(Material m_);
        void setV(std::vector<Vector3> v_);
        void setVn(std::vector<Vector3> vn_);
        void setTriangles(std::vector<Triangle> triangles_);
        void setColor(Color color_);
        void setMaterial(Material materal_);

    protected:
        int v_size;
        int vn_size;
        Material m;
        std::vector<Vector3> v;
        std::vector<Vector3> vn;
        std::vector<Triangle> triangles;
        Color color;
        Material material; 
};