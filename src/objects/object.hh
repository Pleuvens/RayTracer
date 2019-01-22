#pragma once

#include <vector>

#include "../utils/color.hh"
#include "../utils/vector3.hh"
#include "../material/material.hh"
#include "triangle.hh"

class Object
{
    public:
        Object();
        Object(int vsize, int vnsize, Material m_,
        std::vector<Vector3> vertex_, std::vector<Vector3> vertex_normal_,
        std::vector<Triangle> triangles_, Color color_, Material material_);

        int getVSize() const;
        int getVnSize() const;
        std::vector<Vector3> getVertex() const;
        std::vector<Vector3> getVertexNormal() const;
        std::vector<Triangle> getTriangles() const;
        Color getColor() const;
        Material getMaterial() const;

        void setVSize(const int& vsize);
        void setVnSize(const int& vnsize);
        void setVertex(const std::vector<Vector3>& vertex_);
        void setVertexNormal(const std::vector<Vector3>& vertex_normal_);
        void setTriangles(const std::vector<Triangle>& triangles_);
        void setColor(const Color& color_);
        void setMaterial(const Material& material_);

    protected:
        int v_size;
        int vn_size;
        std::vector<Vector3> vertex;
        std::vector<Vector3> vertex_normal;
        std::vector<Triangle> triangles;
        Color color;
        Material material; 
};