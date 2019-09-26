#include <iostream>
#include <fstream>
#include "canvas.hh"
#include "constants.hh"
#ifdef _TESTS
#include "catch.hpp"
#endif
Canvas::Canvas(int height, int width)
    :_height(height), _width(width) 
{
    _pixels = std::vector(_width * _height, Color(0, 0, 0));
}

Canvas::Canvas(int height, int width, const Color& c)
    :_height(height), _width(width) 
{
    _pixels = std::vector(_width * _height, c);
}

#ifdef _TESTS
TEST_CASE("CANVAS: Write px to canvas", "[multi-file:canvas]")
{
    Canvas canvas = Canvas(10, 20);
    canvas.setPixel(2, 3, Color::red());
    REQUIRE(canvas.getPixel(2, 3) == Color::red());
}
#endif

void Canvas::canvasToPPM(std::string filename)
{
    std::ofstream file(filename);
    file << "P3" << std::endl << _width << ' ' << _height
        << std::endl << 255 << std::endl;
    for (int y = 0; y < _height; y++) {
        for (int x = 0; x < _width; x++) {
            file << getPixel(y, x);
            if (x && !(x % PPM_LINE_SIZE))
                file << std::endl;
            else if (x < _width -1)
                file << ' ';
        }
        file << std::endl;
    }
    file.close();
}

#ifdef _TESTS
TEST_CASE("CANVAS: construct px to canvas", "[multi-file:canvas]") {
    Canvas canvas = Canvas(2, 10, Color(1, 0.8, 0.6));
    canvas.canvasToPPM("/tmp/raytracer_canvas_save_test.ppm");
    std::ifstream file("/tmp/raytracer_canvas_save_test.ppm");
    std::string content( (std::istreambuf_iterator<char>(file) ),
                       (std::istreambuf_iterator<char>()    ) );
    REQUIRE(content == "P3\n10 2\n255\n255 204 153 255 204 153 255 204 153 255 204 153 255 204 153\n255 204 153 255 204 153 255 204 153 255 204 153\n255 204 153\n255 204 153 255 204 153 255 204 153 255 204 153 255 204 153\n255 204 153 255 204 153 255 204 153 255 204 153\n255 204 153\n");
}
#endif
