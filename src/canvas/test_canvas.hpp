#ifdef _TESTS

#include "canvas.hh"
#include "catch.hpp"

TEST_CASE("CANVAS: Write px to canvas", "[multi-file:canvas]")
{
    Canvas canvas = Canvas(10, 20);
    canvas.setPixel(2, 3, Color::red());
    REQUIRE(canvas.getPixel(2, 3) == Color::red());
}

TEST_CASE("CANVAS: construct px to canvas", "[multi-file:canvas]") {
    Canvas canvas = Canvas(2, 10, Color(1, 0.8, 0.6));
    canvas.canvasToPPM("/tmp/raytracer_canvas_save_test.ppm");
    std::ifstream file("/tmp/raytracer_canvas_save_test.ppm");
    std::string content( (std::istreambuf_iterator<char>(file) ),
                       (std::istreambuf_iterator<char>()    ) );
    REQUIRE(content == "P3\n10 2\n255\n255 204 153 255 204 153 255 204 153 255 204 153 255 204 153\n255 204 153 255 204 153 255 204 153 255 204 153\n255 204 153\n255 204 153 255 204 153 255 204 153 255 204 153 255 204 153\n255 204 153 255 204 153 255 204 153 255 204 153\n255 204 153\n");
}

#endif
