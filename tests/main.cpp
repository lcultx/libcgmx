#include <iostream>
#include "cgmx/common.h"

using namespace std;
using namespace cgmx;

int main()
{
    // int a;
    // long int b;
    // cin >> a;
    // b = (a * 1000 + a) / 7 / 11 / 13;
    // cout << b;

    auto oldRotate = vec4::fromRotator(vec3::fromValues(0,0,90));

    vec4::log("oldRotate", oldRotate);

    
    auto m = mat4::fromRotationTranslationScale(mat4::create(), oldRotate, vec3::fromValues(0,0,0), vec3::fromValues(1,1,1));

    mat4::log("m", m);
	float* flipY = mat4::fromScaling(mat4::create(), vec3::fromValues(1, -1, 1));

	m = mat4::multiply(mat4::create(), flipY, m);
	mat4::log("m", m);
	m = mat4::multiply(mat4::create(), m, flipY);
	mat4::log("m", m);
    auto newRotate = vec4::create();
    mat4::getRotation(newRotate, m);

    vec4::log("newRotate", newRotate);

    cout << "done";
}