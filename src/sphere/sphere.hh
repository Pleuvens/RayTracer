#pragma once

class Sphere {
    public:
        Sphere();

        bool operator==(const Sphere& s) const { (void)s; return true; }
    private:
        int _something;
};
