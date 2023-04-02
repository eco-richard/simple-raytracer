#include <iostream>
#include "R3Vector.h"

int main() {
  int nx = 200;
  int ny = 100;

  std::cout << "P3\n" << nx << " " << ny << "\n255\n";

  for (int i = ny - 1; i >= 0; i--) {
    for (int j = 0; j < nx; j++) {
      R3Vector colors(
        double(j) / double(nx),
        double(i) / double(ny),
        0.2
      );

      int r = int(255.99 * colors[0]);
      int g = int(255.99 * colors[1]);
      int b = int(255.99 * colors[2]);

      std::cout << r << " " << g << " " << b << "\n";
    }
  }
}