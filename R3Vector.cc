
#include <cmath>
#include <memory>
#include "R3Vector.h"

R3Vector::R3Vector() {
  data_ = std::make_unique<double[]>(0.0, 0.0, 0.0);
}