#pragma once

#include "../utils/vector3.hh"

class Ray {

public:
	Ray();
	Ray(const Vector3& o, const Vector3& d);

	inline Vector3 getOrigin() { return origin; }
	inline void setOrigin(const Vector3& o) { origin = o; }

	inline Vector3 getDirection() { return direction; }
	inline Vector3 setDirection(const Vector3& d) { direction = d; }
private:

	Vector3 origin;
	Vector3 direction;
};
