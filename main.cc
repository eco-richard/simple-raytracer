#include <iostream>
#include <limits>
#include "R3Vector.h"
#include "Ray.h"
#include "Sphere.h"
#include "Hitable.h"
#include "HitableList.h"

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
  int nx = 1200;
  int ny = 600;

  std::cout << "P3\n" << nx << " " << ny << "\n255\n";

  R3Vector lower_left_corner(-2.0, -1.0, -1.0);
  R3Vector horizontal(4.0, 0.0, 0.0);
  R3Vector vertical(0.0, 2.0, 0.0);
  R3Vector origin(0.0, 0.0, 0.0);

  Hitable* list[2];
  list[0] = new Sphere(R3Vector(0, 0, -1), 0.5);
  list[1] = new Sphere(R3Vector(0, -100.5, -1), 100);

  Hitable* world = new HitableList(list, 2);

  for (int i = ny - 1; i >= 0; i--) {
    for (int j = 0; j < nx; j++) {
      double u = double(j) / double(nx);
      double v = double(i) / double(ny);

      Ray ray(origin, lower_left_corner + horizontal * u + vertical * v);

      R3Vector point = ray.point_at_t(2.0);
      R3Vector colors = color(ray, world);

      int r = int(255.99 * colors[0]);
      int g = int(255.99 * colors[1]);
      int b = int(255.99 * colors[2]);

      std::cout << r << " " << g << " " << b << "\n";
    }
  }

  return 0;
}
