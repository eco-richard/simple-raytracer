#include <iostream>
#include "R3Vector.h"
#include "Ray.h"

R3Vector color(const Ray& r) {
  R3Vector unit_direction = unit_vector(r.direction());
  double t = 0.5 * (unit_direction.y() + 1.0);
  return R3Vector(1.0, 1.0, 1.0) * (1.0 - t) + R3Vector(0.5, 0.7, 1.0) * t;
}

int main() {
  int nx = 600;
  int ny = 300;

  std::cout << "P3\n" << nx << " " << ny << "\n255\n";

  R3Vector lower_left_corner(-2.0, -1.0, -1.0);
  R3Vector horizontal(4.0, 0.0, 0.0);
  R3Vector vertical(0.0, 2.0, 0.0);
  R3Vector origin(0.0, 0.0, 0.0);

  for (int i = ny - 1; i >= 0; i--) {
    for (int j = 0; j < nx; j++) {
      double u = double(j) / double(nx);
      double v = double(i) / double(ny);

      Ray ray(origin, lower_left_corner + horizontal * u + vertical * v);

      R3Vector colors = color(ray);

      int r = int(255.99 * colors[0]);
      int g = int(255.99 * colors[1]);
      int b = int(255.99 * colors[2]);

      std::cout << r << " " << g << " " << b << "\n";
    }
  }
}