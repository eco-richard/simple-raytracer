#ifndef SIMPLE_RAYTRACER_R3_VECTOR_H
#define SIMPLE_RAYTRACER_R3_VECTOR_H

#include <cmath>
#include <exception>
#include <memory>

class R3Vector {
public:
  R3Vector() {
    data_[0] = 0.0;
    data_[1] = 0.0;
    data_[2] = 0.0;
  };

  R3Vector(double e1, double e2, double e3) {
    data_[0] = e1;
    data_[1] = e2;
    data_[2] = e3;
  }

  R3Vector(const R3Vector &rhs) = default;
  R3Vector(R3Vector &&rhs) = default;
  R3Vector &operator=(const R3Vector &rhs) = default;
  R3Vector &operator=(R3Vector &&rhs) = default;

  double x() { return data_[0]; }

  double y() { return data_[1]; }

  double z() { return data_[2]; }

  double r() { return data_[0]; }

  double g() { return data_[1]; }

  double b() { return data_[2]; }

  R3Vector operator-() const {
    return R3Vector(-data_[0], -data_[1], -data_[2]);
  }

  double operator[](int i) const {
    if (i > 2) {
      throw std::out_of_range("3 dimensional vectors are 3 dimensional");
    }
    return data_[i];
  }

  double &operator[](int i) {
    if (i > 2) {
      throw std::out_of_range("3 dimensional vectors are 3 dimensional");
    }
    return data_[i];
  }

  R3Vector operator+(const R3Vector &v) const {
    return R3Vector(data_[0] + v[0], data_[1] + v[1], data_[2] + v[2]);
  }

  R3Vector operator-(const R3Vector &v) const {
    return R3Vector(data_[0] - v[0], data_[1] - v[1], data_[2] - v[2]);
  }

  R3Vector operator*(const R3Vector &v) const {
    return R3Vector(data_[0] * v[0], data_[1] * v[1], data_[2] * v[2]);
  }

  R3Vector operator/(const R3Vector &v) {
    return R3Vector(data_[0] / v[0], data_[1] / v[1], data_[2] / v[2]);
  }

  R3Vector operator*(const double t) const {
    return R3Vector(data_[0] * t, data_[1] * t, data_[2] * t);
  }

  R3Vector operator/(const double t) const {
    return R3Vector(data_[0] / t, data_[1] / t, data_[2] / t);
  }

  R3Vector &operator+=(const R3Vector &v) {
    data_[0] += v[0];
    data_[1] += v[1];
    data_[2] += v[2];
    return *this;
  }

  R3Vector &operator-=(const R3Vector &v) {
    data_[0] -= v[0];
    data_[1] -= v[1];
    data_[2] -= v[2];
    return *this;
  }

  R3Vector &operator*=(const R3Vector &v) {
    data_[0] *= v[0];
    data_[1] *= v[1];
    data_[2] *= v[2];
    return *this;
  }

  R3Vector &operator/=(const R3Vector &v) {
    data_[0] /= v[0];
    data_[1] /= v[1];
    data_[2] /= v[2];
    return *this;
  }

  R3Vector &operator*=(const double t) {
    data_[0] *= t;
    data_[1] *= t;
    data_[2] *= t;
    return *this;
  }

  R3Vector &operator/=(const double t) {
    data_[0] /= t;
    data_[1] /= t;
    data_[2] /= t;
    return *this;
  }

  double length() const {
    return sqrt(data_[0] * data_[0] + data_[1] * data_[1] +
                data_[2] * data_[2]);
  }

  double squared_length() const {
    return (data_[0] * data_[0] + data_[1] * data_[1] + data_[2] * data_[2]);
  }

  void make_unit_vector() { *this /= length(); }

private:
  double data_[3];
};

// Vector Functions

double dot(const R3Vector &v1, const R3Vector &v2) {
  return (v1[0] * v2[0] + v1[1] * v2[1] + v1[2] * v2[2]);
}

R3Vector cross(const R3Vector &v1, const R3Vector &v2) {
  return R3Vector((v1[1] * v2[2]) - (v1[2] * v2[1]),
                  (v1[0] * v2[2]) - (v1[2] * v1[0]),
                  (v1[0] * v2[1]) - (v1[1] * v2[0]));
}

R3Vector unit_vector(const R3Vector &v) { return v / v.length(); }

#endif // SIMPLE_RAYTRACER_R3_VECTOR_H