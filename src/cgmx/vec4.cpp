#include <math.h>
#include <stdlib.h>   
#include "common.h"

namespace cgmx {
    namespace vec4 {
        float*  create() {
            float *out = (float*)malloc(VEC_SIZE_4 * sizeof(*out));
            out[0] = 0;
            out[1] = 0;
            out[2] = 0;
            out[3] = 0;
            return out;
        };
        
        float* fromValues(float x, float y, float z, float w) {
            float *out = (float*)malloc(VEC_SIZE_4 * sizeof(*out));
            out[0] = x;
            out[1] = y;
            out[2] = z;
            out[3] = w;
            return out;
        };

        //https://github.com/ncsoft/Unreal.js/issues/132
        float* fromRotator(float* rotator) {
            const float PI = 3.141592653589793f;
            float degToRad = PI / 180;
            float halfDebToRad = degToRad / 2;
            float sp = sin(rotator[0] * halfDebToRad);
            float cp = cos(rotator[0] * halfDebToRad);

            float sy = sin(rotator[1] * halfDebToRad);
            float cy = cos(rotator[1] * halfDebToRad);

            float sr = sin(rotator[2] * halfDebToRad);
            float cr = cos(rotator[2] * halfDebToRad);

			float* out = (float*)malloc(VEC_SIZE_4 * sizeof(*out));
            out[0] = cr * sp * sy - sr * cp * cy;
            out[1] = -cr * sp * cy - sr * cp * sy;
            out[2] = cr * cp * sy - sr * sp * cy;
            out[3] = cr * cp * cy + sr * sp * sy;
			return out;
        }


    }
}