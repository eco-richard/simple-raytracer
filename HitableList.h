#ifndef SIMPLE_RAYTRACER_HITABLE_LIST_H
#define SIMPLE_RAYTRACER_HITABLE_LIST_H

#include "Hitable.h"
#include <memory>

class HitableList : public Hitable {
  public:
    HitableList() {};

    HitableList(Hitable **l, int size) : list(l), list_size(size) {}

    virtual bool hit(const Ray& r, double t_min, double t_max, hit_record& rec) const;

    private:
      Hitable** list;
      int list_size;
};

bool HitableList::hit(const Ray &r, double t_min, double t_max, hit_record &rec) const {
  hit_record tmp_record;

  bool hit_anything = false;

  double closest_so_far = t_max;
  for (int i = 0; i < list_size; i++) {
    if (list[i]->hit(r, t_min, closest_so_far, tmp_record)) {
      hit_anything = true;
      closest_so_far = tmp_record.t;
      rec = tmp_record;
    }
  }
  
  return hit_anything;
}

#endif // SIMPLE_RAYTRACER_HITABLE_LIST_H
