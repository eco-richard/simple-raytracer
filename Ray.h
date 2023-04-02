#ifndef SIMPLE_RAYTRACER_RAY_H
#define SIMPLE_RAYTRACER_RAY_H

#include "R3Vector.h"

/*
Equation for a ray is
x(t) = A + Bt
where A, B are points (R3Vectors)
and t is a real number (double)
*/

class Ray {
  public:
    Ray();
    Ray(const R3Vector& a, const R3Vector& b) {
      A = a;
      B = b;
    }

    R3Vector origin() const {
      return A;
    }
    R3Vector direction() const {
      return B;
    }
    R3Vector point_at_t(double t) const {
      return A + B * t;
    }

  private:
    R3Vector A;
    R3Vector B;  
};

#endif // SIMPLE_RAYTRACER_RAY_H