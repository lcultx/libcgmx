#pragma once

#include <exception>
#include <functional>
#include <vector>

namespace cgmx {
  //float const PI = 3.141592653589793;

  //float const degree = PI / 180.0;

  //float toRadian(float a) {
  //  return a * degree;
  //};

  float const EPSILON = 0.000001;

  // sizes
  int const VEC_SIZE_3 = 3;
  int const VEC_SIZE_4 = 4;
  int const MAT_SIZE_4 = 4 * 4;

  namespace mat4 {
    float* create();
  }
}