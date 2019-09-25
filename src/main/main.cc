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

Projectile tick(const Environment& env, const Projectile& proj)
{
    return Projectile(proj._position + proj._velocity,
            proj._velocity + env._gravity + env._wind);
}

int main(void) {
    Projectile p = Projectile(Point(0, 1, 0), Vector(1, 1, 0).normalize());
    Environment e = Environment(Vector(0, -0.1, 0), Vector(-0.01, 0, 0));
    while (p._position.getY() > 0)
        p = tick(e, p);
    return 0;
}
