#include <iostream>
#include <limits>
#include "R3Vector.h"
#include "Ray.h"
#include "Sphere.h"
#include "Hitable.h"
#include "HitableList.h"
#include "Camera.h"

R3Vector color(const Ray&r, Hitable* world) {
  hit_record record;
  if (world->hit(r, 0.0, std::numeric_limits<double>::max(), record)) {
      return R3Vector(
          record.normal.x() + 1,
          record.normal.y() + 1,
          record.normal.z() + 1
      ) * 0.5;
  } else {
    R3Vector unit_direction = unit_vector(r.direction());
    double t = (unit_direction.y() + 1.0) * 0.5;
    return R3Vector(1.0, 1.0, 1.0) * (1.0 - t) + R3Vector(0.5, 0.7, 1.0) * t;
  }
}

int main() {
  int nx = 400;
  int ny = 200;
  int ns = 100;

  std::cout << "P3\n" << nx << " " << ny << "\n255\n";

  Hitable* list[2];
  list[0] = new Sphere(R3Vector(0, 0, -1), 0.5);
  list[1] = new Sphere(R3Vector(0, -100.5, -1), 100);

  Hitable* world = new HitableList(list, 2);

  Camera cam;

  for (int i = ny - 1; i >= 0; i--) {
    for (int j = 0; j < nx; j++) {
      R3Vector colors(0, 0, 0);
      for (int s = 0; s < ns; s++) {
        double u = double(j + drand48()) / double(nx);
        double v = double(i + drand48()) / double(ny);

        Ray r = cam.get_ray(u, v);
        // R3Vector point = r.point_at_t(2.0);
        colors += color(r, world);
      }
      colors /= float(ns);

      int r = int(255.99 * colors[0]);
      int g = int(255.99 * colors[1]);
      int b = int(255.99 * colors[2]);

      std::cout << r << " " << g << " " << b << "\n";
    }
  }

  return 0;
}
