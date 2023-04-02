#include <iostream>

int main() {
  int nx = 200;
  int ny = 100;

  std::cout << "P3\n" << nx << " " << ny << "\n255\n";

  for (int i = ny - 1; i >= 0; i--) {
    for (int j = 0; j < nx; j++) {
      double red = double(j) / double(nx);
      double green = double(i) / double(ny);
      double blue = 0.2;

      int r = int(255.99 * red);
      int g = int(255.99 * green);
      int b = int(255.99 * blue);

      std::cout << r << " " << g << " " << b << "\n";
    }
  }
}