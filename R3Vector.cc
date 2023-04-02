
#include <cmath>
#include <exception>
#include <memory>
#include "R3Vector.h"

R3Vector::R3Vector() noexcept {
  data_ = std::make_unique<double[]>(3); 
}

R3Vector::R3Vector(double e1, double e2, double e3) noexcept {
  data_ = std::make_unique<double[]>(0);
  data_[0] = e1;
  data_[1] = e2;
  data_[2] = e3;
}

double R3Vector::x() {
  return data_[0];
}

double R3Vector::y() {
  return data_[1];
}

double R3Vector::z() {
  return data_[2];
}

double R3Vector::r() {
  return data_[0];
}

double R3Vector::g() {
  return data_[1];
}

double R3Vector::b() {
  return data_[2];
}

R3Vector R3Vector::operator-() const {
  return R3Vector(-data_[0], -data_[1], -data_[2]);
}

double R3Vector::operator[](int i) const {
  if (i > 2) {
    throw std::out_of_range("3 dimensional vectors are 3 dimensional");
  }
  return data_[i];
}

double& R3Vector::operator[](int i) {
  if (i > 2) {
    throw std::out_of_range("3 dimensional vectors are 3 dimensional");
  }
  return data_[i];
}

R3Vector R3Vector::operator+(const R3Vector& v) {
  return R3Vector(data_[0] + v[0], data_[1] + v[1], data_[2] + v[2]);
}

R3Vector R3Vector::operator-(const R3Vector& v) {
  return R3Vector(data_[0] - v[0], data_[1] - v[1], data_[2] - v[2]);
}

R3Vector R3Vector::operator*(const R3Vector& v) {
  return R3Vector(data_[0] * v[0], data_[1] * v[1], data_[2] * v[2]);
}

R3Vector R3Vector::operator/(const R3Vector& v) {
  return R3Vector(data_[0] / v[0], data_[1] / v[1], data_[2] / v[2]);
}

R3Vector R3Vector::operator*(const double t) {
  return R3Vector(data_[0] * t, data_[1] * t, data_[2] * t); 
}

R3Vector R3Vector::operator/(const double t) {
  return R3Vector(data_[0] / t, data_[1] / t, data_[2] / t); 
}

R3Vector& R3Vector::operator+=(const R3Vector& v) {
  data_[0] += v[0];
  data_[1] += v[1];
  data_[2] += v[2];
  return *this;
}

R3Vector& R3Vector::operator-=(const R3Vector& v) {
  data_[0] -= v[0];
  data_[1] -= v[1];
  data_[2] -= v[2];
  return *this;
}

R3Vector& R3Vector::operator*=(const R3Vector& v) {
  data_[0] *= v[0];
  data_[1] *= v[1];
  data_[2] *= v[2];
  return *this;
}

R3Vector& R3Vector::operator/=(const R3Vector& v) {
  data_[0] /= v[0];
  data_[1] /= v[1];
  data_[2] /= v[2];
  return *this;
}


R3Vector& R3Vector::operator*=(const double t) {
  data_[0] *= t;
  data_[1] *= t;
  data_[2] *= t;
  return *this;
}

R3Vector& R3Vector::operator/=(const double t) {
  data_[0] /= t;
  data_[1] /= t;
  data_[2] /= t;
  return *this;
}

double R3Vector::length() const {
  return sqrt(
    data_[0] * data_[0] +
    data_[1] * data_[1] +
    data_[2] * data_[2]
  );
}

double R3Vector::squared_length() const {
  return (
    data_[0] * data_[0] +
    data_[1] * data_[1] +
    data_[2] * data_[2]
  );
}

void R3Vector::make_unit_vector() {
  *this /= length();
}

double dot(const R3Vector& v1, const R3Vector& v2) {
  return (v1[0] * v2[0] + v1[1] * v2[1] + v1[2] * v2[2]);
}

R3Vector cross(const R3Vector& v1, const R3Vector& v2) {
  return R3Vector(
    (v1[1] * v2[2]) - (v1[2] * v2[1]),
    (v1[0] * v2[2]) - (v1[2] * v1[0]),
    (v1[0] * v2[1]) - (v1[1] * v2[0])
  );
}

// R3Vector unit_vector(const R3Vector& v) {
//   return v / v.length();
// }