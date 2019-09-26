#pragma once

#include <vector>
#include <string>

#include "color.hh"

class Canvas {
    public:
        Canvas(int height, int width);
        Canvas(int height, int width, const Color& c);
        
        inline int getWidth(void) const { return _width; }
        inline int getHeight(void) const { return _height; }
        Color getPixel(int y, int x) const;

        inline void setWidth(int width) { _width = width; }
        inline void setHeight(int height) { _height = height; }
        void setPixel(int y, int x, Color c);

        void canvasToPPM(std::string filename);
    private:
        bool isCoordValid(int y, int x) const;

        int _height;
        int _width;
        std::vector<Color> _pixels;
};
