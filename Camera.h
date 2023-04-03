#ifndef SIMPLE_RAYTRACER_CAMERA_H
#define SIMPLE_RAYTRACER_CAMERA_H

#include "Ray.h"

class Camera {
  public:
  Camera() {
    lower_left_corner = R3Vector(-2.0, -1.0, -1.0);
    horizontal = R3Vector(4.0, 0.0, 0.0);
    vertical = R3Vector(0.0, 2.0, 0.0);
    origin = R3Vector(0.0, 0.0, 0.0);
  }

  Ray get_ray(double u, double v) {
    return Ray(origin, lower_left_corner + horizontal * u + vertical * v - origin);
  }

  private:
  R3Vector lower_left_corner;
  R3Vector origin;
  R3Vector horizontal;
  R3Vector vertical;
};

#endif // SIMPLE_RAYTRACER_CAMERA_H