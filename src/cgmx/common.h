#pragma once

#include <exception>
#include <functional>
#include <vector>
#include <string>
using namespace std;
namespace cgmx {


  //float const degree = PI / 180.0;

  //float toRadian(float a) {
  //  return a * degree;
  //};


  // sizes
  int const VEC_SIZE_3 = 3;
  int const VEC_SIZE_4 = 4;
  int const MAT_SIZE_4 = 4 * 4;

  namespace mat4 {
    float* create();
    float* multiply(float* out, float* a, float* b);
    float* getTranslation(float* out, float* mat);
    float* getScaling(float* out, float* mat);
    float* getRotation(float* out, float* mat);
    float* fromScaling(float* out, float* v);
    float* fromRotationTranslationScale(float* out, float* q, float* v, float* s);
    void log(string name, float* v);
  }

  namespace vec3 {
    float* create();
    float* fromValues(float x, float y, float z) ;
    void log(string name, float* v);
  }

  namespace vec4 {
	  float* create();
	  float* fromValues(float x, float y, float z, float w);
      float* fromRotator(float* rotator);
      void log(string name, float* v);
  }
}
