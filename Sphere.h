#ifndef SIMPLE_RAYTRACER_SPHERE_H
#define SIMPLE_RAYTRACER_SPHERE_H

#include "Hitable.h"
#include "R3Vector.h"
#include <cmath>

class Sphere : public Hitable {
  public:
    Sphere() {};

    Sphere(R3Vector c, double r) : center(c), radius(r) {}

    virtual bool hit(const Ray& r, double t_min, double t_max, hit_record& rec) const;

  private:
      R3Vector center;
      double radius;
};

bool Sphere::hit(const Ray &r, double t_min, double t_max, hit_record &rec) const {
  R3Vector oc = r.origin() - center;

  double a = dot(r.direction(), r.direction());
  double b = dot(oc, r.direction());
  double c = dot(oc, oc) - radius * radius;

  double discriminant = b*b - a*c;

  if (discriminant > 0) {
    double tmp = (-b - std::sqrt(b*b - a*c)) / a;

    if (tmp < t_max && tmp > t_min) {
      rec.t = tmp;
      rec.p = r.point_at_t(rec.t);
      rec.normal = (rec.p - center) / radius;

      return true;
    }
    tmp = (-b + std::sqrt(b*b - a*c)) / a;
    
    if (tmp < t_max && tmp > t_min) {
      rec.t = tmp;
      rec.p = r.point_at_t(rec.t);
      rec.normal = (rec.p - center) / radius;
      return true;
    }
  }
  return false;
}
#endif // SIMPLE_RAYTRACER_SPHERE_H
