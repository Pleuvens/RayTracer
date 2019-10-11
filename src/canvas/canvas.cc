#include <iostream>
#include <fstream>
#include "canvas.hh"
#include "constants.hh"
#include "test_canvas.hpp"

Canvas::Canvas(int height, int width)
    :_height(height), _width(width) 
{
    _pixels = std::vector<Color>(_width * _height, Color(0, 0, 0));
}

Canvas::Canvas(int height, int width, const Color& c)
    :_height(height), _width(width) 
{
    _pixels = std::vector<Color>(_width * _height, c);
}

bool Canvas::isCoordValid(int y, int x) const
{
    return y >= 0 && y < _height && x >= 0 && x < _width;
}

Color Canvas::getPixel(int y, int x) const 
{
    if (!isCoordValid(y, x))
        throw "Invalid coordinates";
    return _pixels[y * _width + x]; 
}

void Canvas::setPixel(int y, int x, Color c) 
{
    if (!isCoordValid(y, x))
        throw "Invalid coordinates";
    _pixels[y * _width + x] = c; 
}

void Canvas::canvasToPPM(std::string filename)
{
    std::ofstream file(filename);
    file << "P3" << '\n' << _width << ' ' << _height
        << '\n' << 255 << '\n';
    for (int y = 0; y < _height; y++) {
        for (int x = 0; x < _width; x++) {
            file << getPixel(y, x);
            if (x && !(x % PPM_LINE_SIZE))
                file << '\n';
            else if (x < _width -1)
                file << ' ';
        }
        file << '\n';
    }
    file.close();
}
