#include <iostream>
#include <cmath>

#include "point.hh"
#include "vector.hh"
#include "canvas.hh"

class Projectile {
    public:
        Projectile(Point position, Vector velocity)
            : _position(position), _velocity(velocity)
        {}
        Point _position;
        Vector _velocity;
};

class Environment {
    public:
        Environment(Vector gravity, Vector wind)
            : _gravity(gravity), _wind(wind)
        {}
        Vector _gravity;
        Vector _wind;
};

Projectile tick(Environment env, Projectile proj)
{
    Tuple t1 = proj._position + proj._velocity;
    Tuple t2 = proj._velocity + env._gravity + env._wind;
    return Projectile(Point(t1.getX(), t1.getY(), t1.getZ()),
            Vector(t2.getX(), t2.getY(), t2.getZ()));
}

void printPos(Canvas &c, int y, int x)
{
    for (int i = y - 1; i < y + 2; i++)
    {
        for (int j = x - 1; j < x + 2; j++)
        {
            c.setPixel(c.getHeight() - i, j, Color::red());
        }
    }
}

int main(void) {
    Environment e = Environment(Vector(0, -0.1, 0), Vector(-0.01, 0, 0));
    Point start = Point(0, 1, 0);
    Vector velocity = Vector(1, 1.8, 0).normalize() * 11.25f;
    Projectile p = Projectile(start, velocity);
    
    Canvas c = Canvas(500, 900);

    while (p._position.getY() > 0)
    {
        p = tick(e, p);
        printPos(c, std::round(p._position.getY()), std::round(p._position.getX()));
    }
    c.canvasToPPM("/tmp/test.ppm");
    return 0;
}
