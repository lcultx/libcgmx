#include <math.h>
#include <stdlib.h>   
#include "common.h"

namespace cgmx {
    namespace mat4 {
        float* create() {
			float* out = (float*) malloc(MAT_SIZE_4 * sizeof(*out));
			out[0] = 1;
			out[1] = 0;
			out[2] = 0;
			out[3] = 0;
			out[4] = 0;
			out[5] = 1;
			out[6] = 0;
			out[7] = 0;
			out[8] = 0;
			out[9] = 0;
			out[10] = 1;
			out[11] = 0;
			out[12] = 0;
			out[13] = 0;
			out[14] = 0;
			out[15] = 1;
			return out;
        }

    }
}