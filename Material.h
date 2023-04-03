#ifndef SIMPLE_RAYTRACER_MATERIAL_H
#define SIMPLE_RAYTRACER_MATERIAL_H

#include "Hitable.h"
#include "R3Vector.h"
#include "Ray.h"

R3Vector random_in_unit_sphere() {
  R3Vector point;

  do {
    point = R3Vector(drand48(), drand48(), drand48()) * 2.0 -
            R3Vector(1.0, 1.0, 1.0);
  } while (dot(point, point) >= 1.0);
  return point;
}

class Material {
public:
  virtual bool scatter(const Ray &r_in, const hit_record &rec,
                       R3Vector &attenuation, Ray &scattered) const = 0;
};

class Lambertian : public Material {
public:
  Lambertian(const R3Vector &a) : albedo(a){};
  virtual bool scatter(const Ray &r_in, const hit_record &rec,
                       R3Vector &attenuation, Ray &scattered) const {
    R3Vector target = rec.p + rec.normal + random_in_unit_sphere();
    scattered = Ray(rec.p, target - rec.p);
    attenuation = albedo;
    return true;
  }

private:
  R3Vector albedo;
};

R3Vector reflect(const R3Vector &v, const R3Vector &normal) {
  return v - normal * dot(v, normal) * 2;
}

class Metal : public Material {
public:
  Metal(const R3Vector &a) : albedo(a){};

  virtual bool scatter(const Ray &r_in, const hit_record &rec,
                       R3Vector &attenuation, Ray &scattered) const {
    R3Vector reflected = reflect(unit_vector(r_in.direction()), rec.normal);
    scattered = Ray(rec.p, reflected);
    attenuation = albedo;
    return (dot(scattered.direction(), rec.normal) > 0);
  }

private:
  R3Vector albedo;
};

#endif // !SIMPLE_RAYTRACER_MATERIAL_H
