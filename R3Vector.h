#ifndef SIMPLE_RAYTRACER_R3_VECTOR_H
#define SIMPLE_RAYTRACER_R3_VECTOR_H

#include <memory>

class R3Vector {
  public:
    R3Vector();
    R3Vector(double e1, double e2, double e3);

    double x();
    double y();
    double z();

    double r();
    double g();
    double b();

    R3Vector& operator+(const R3Vector& v) const;
    R3Vector operator-() const;
    double operator[](int i) const;
    double& operator[](int i);

    R3Vector& operator+=(const R3Vector& v);
    R3Vector& operator-=(const R3Vector& v);
    R3Vector& operator*=(const R3Vector& v);
    R3Vector& operator/=(const R3Vector& v);
    R3Vector& operator*=(const double t);
    R3Vector& operator/=(const double t);

    double length() const;
    double squared_length() const;
    void make_unit_vector();

  private:
    std::unique_ptr<double[]> data_;
};

#endif // SIMPLE_RAYTRACER_R3_VECTOR_H