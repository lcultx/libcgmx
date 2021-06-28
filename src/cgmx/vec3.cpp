#include <math.h>
#include <stdlib.h>   
#include "common.h"

namespace cgmx {
    namespace vec3 {
        float* create(){
            float *out = (float*) malloc(VEC_SIZE_3 * sizeof(*out));
            out[0] = 0;
            out[1] = 0;
            out[2] = 0;
            return out;
        };

         float* fromValues(float x, float y, float z) {
            float *out = (float*) malloc(VEC_SIZE_3 * sizeof(*out));
            out[0] = x;
            out[1] = y;
            out[2] = z;
            return out;
        };
    }
}