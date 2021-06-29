#include <iostream>
#include <math.h>
#include <stdlib.h>   
#include "common.h"
using namespace std;
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

		void log(string name, float* mat) {
			cout << "mat " << name << " : \n";
			cout << " " << mat[0] << " " << mat[1] << " " << mat[2] << " " << mat[3] << "\n";
			cout << " " << mat[4] << " " << mat[5] << " " << mat[6] << " " << mat[7] << "\n";
			cout << " " << mat[8] << " " << mat[9] << " " << mat[10] << " " << mat[11] << "\n";
			cout << " " << mat[12] << " " << mat[13] << " " << mat[14] << " " << mat[15] << "\n";
		}

		float* multiply(float* out, float* a, float* b) {
			float a00 = a[0], a01 = a[1], a02 = a[2], a03 = a[3];
			float a10 = a[4], a11 = a[5], a12 = a[6], a13 = a[7];
			float a20 = a[8], a21 = a[9], a22 = a[10], a23 = a[11];
			float a30 = a[12], a31 = a[13], a32 = a[14], a33 = a[15];

			// Cache only the current line of the second matrix
			float b0 = b[0], b1 = b[1], b2 = b[2], b3 = b[3];
			out[0] = b0 * a00 + b1 * a10 + b2 * a20 + b3 * a30;
			out[1] = b0 * a01 + b1 * a11 + b2 * a21 + b3 * a31;
			out[2] = b0 * a02 + b1 * a12 + b2 * a22 + b3 * a32;
			out[3] = b0 * a03 + b1 * a13 + b2 * a23 + b3 * a33;

			b0 = b[4]; b1 = b[5]; b2 = b[6]; b3 = b[7];
			out[4] = b0 * a00 + b1 * a10 + b2 * a20 + b3 * a30;
			out[5] = b0 * a01 + b1 * a11 + b2 * a21 + b3 * a31;
			out[6] = b0 * a02 + b1 * a12 + b2 * a22 + b3 * a32;
			out[7] = b0 * a03 + b1 * a13 + b2 * a23 + b3 * a33;

			b0 = b[8]; b1 = b[9]; b2 = b[10]; b3 = b[11];
			out[8] = b0 * a00 + b1 * a10 + b2 * a20 + b3 * a30;
			out[9] = b0 * a01 + b1 * a11 + b2 * a21 + b3 * a31;
			out[10] = b0 * a02 + b1 * a12 + b2 * a22 + b3 * a32;
			out[11] = b0 * a03 + b1 * a13 + b2 * a23 + b3 * a33;

			b0 = b[12]; b1 = b[13]; b2 = b[14]; b3 = b[15];
			out[12] = b0 * a00 + b1 * a10 + b2 * a20 + b3 * a30;
			out[13] = b0 * a01 + b1 * a11 + b2 * a21 + b3 * a31;
			out[14] = b0 * a02 + b1 * a12 + b2 * a22 + b3 * a32;
			out[15] = b0 * a03 + b1 * a13 + b2 * a23 + b3 * a33;
			return out;
		}

		float* getTranslation(float* out, float* mat) {
			out[0] = mat[12];
			out[1] = mat[13];
			out[2] = mat[14];

			return out;
		};

		float* getScaling(float* out, float* mat) {
			float m11 = mat[0];
			float m12 = mat[1];
			float m13 = mat[2];
			float m21 = mat[4];
			float m22 = mat[5];
			float m23 = mat[6];
			float m31 = mat[8];
			float m32 = mat[9];
			float m33 = mat[10];

			out[0] = sqrtf(m11 * m11 + m12 * m12 + m13 * m13);
			out[1] = sqrtf(m21 * m21 + m22 * m22 + m23 * m23);
			out[2] = sqrtf(m31 * m31 + m32 * m32 + m33 * m33);

			return out;
		}

		float* getRotation(float* out, float* mat) {
			// Algorithm taken from http://www.euclideanspace.com/maths/geometry/rotations/conversions/matrixToQuaternion/index.htm
			float trace = mat[0] + mat[5] + mat[10];
			float S = 0;

			if (trace > 0) {
				S = sqrtf(trace + 1.0f) * 2;
				out[3] = 0.25f * S;
				out[0] = (mat[6] - mat[9]) / S;
				out[1] = (mat[8] - mat[2]) / S;
				out[2] = (mat[1] - mat[4]) / S;
			}
			else if ((mat[0] > mat[5]) & (mat[0] > mat[10])) {
				S = sqrtf(1.0f + mat[0] - mat[5] - mat[10]) * 2;
				out[3] = (mat[6] - mat[9]) / S;
				out[0] = 0.25f * S;
				out[1] = (mat[1] + mat[4]) / S;
				out[2] = (mat[8] + mat[2]) / S;
			}
			else if (mat[5] > mat[10]) {
				S = sqrtf(1.0f + mat[5] - mat[0] - mat[10]) * 2;
				out[3] = (mat[8] - mat[2]) / S;
				out[0] = (mat[1] + mat[4]) / S;
				out[1] = 0.25f * S;
				out[2] = (mat[6] + mat[9]) / S;
			}
			else {
				S = sqrtf(1.0f + mat[10] - mat[0] - mat[5]) * 2;
				out[3] = (mat[1] - mat[4]) / S;
				out[0] = (mat[8] + mat[2]) / S;
				out[1] = (mat[6] + mat[9]) / S;
				out[2] = 0.25f * S;
			}

			return out;
		};

		float* fromScaling(float* out, float* v) {
			out[0] = v[0];
			out[1] = 0;
			out[2] = 0;
			out[3] = 0;
			out[4] = 0;
			out[5] = v[1];
			out[6] = 0;
			out[7] = 0;
			out[8] = 0;
			out[9] = 0;
			out[10] = v[2];
			out[11] = 0;
			out[12] = 0;
			out[13] = 0;
			out[14] = 0;
			out[15] = 1;
			return out;
		};


		float* fromRotationTranslationScale(float* out, float* q, float* v, float* s) {
			// Quaternion math
			float x = q[0], y = q[1], z = q[2], w = q[3];
			float x2 = x + x;
			float y2 = y + y;
			float z2 = z + z;

			float xx = x * x2;
			float xy = x * y2;
			float xz = x * z2;
			float yy = y * y2;
			float yz = y * z2;
			float zz = z * z2;
			float wx = w * x2;
			float wy = w * y2;
			float wz = w * z2;
			float sx = s[0];
			float sy = s[1];
			float sz = s[2];

			out[0] = (1 - (yy + zz)) * sx;
			out[1] = (xy + wz) * sx;
			out[2] = (xz - wy) * sx;
			out[3] = 0;
			out[4] = (xy - wz) * sy;
			out[5] = (1 - (xx + zz)) * sy;
			out[6] = (yz + wx) * sy;
			out[7] = 0;
			out[8] = (xz + wy) * sz;
			out[9] = (yz - wx) * sz;
			out[10] = (1 - (xx + yy)) * sz;
			out[11] = 0;
			out[12] = v[0];
			out[13] = v[1];
			out[14] = v[2];
			out[15] = 1;

			return out;
		};
    }
}