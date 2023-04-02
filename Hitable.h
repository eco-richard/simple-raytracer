#ifndef SIMPLE_RAYTRACER_HITABLE_H
#define SIMPLE_RAYTRACER_HITABLE_H

#include "Ray.h"

struct hit_record {
  double t;

  R3Vector p;
  R3Vector normal;
};

class Hitable {
  public:
  virtual bool hit(const Ray& r, double t_min, double t_max, hit_record& rec) const = 0;
};

#endif // SIMPLE_RAYTRACER_HITABLE_H