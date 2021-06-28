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

    cout << "oldRotate: " << oldRotate[0] << " " << oldRotate[1] << " " << oldRotate[2] << " " << oldRotate[3];
    auto m = mat4::fromRotationTranslationScale(mat4::create(), oldRotate, vec3::fromValues(0,0,0), vec3::fromValues(1,1,1));
    float* flipY =  mat4::fromScaling(mat4::create(), vec3::fromValues(0,-1,0));

    m = mat4::multiply(mat4::create(), flipY, m);
    m = mat4::multiply(mat4::create(), m, flipY);
    auto newRotate = vec4::create();
    mat4::getRotation(newRotate, m);

    cout << "newRotate: " << newRotate[0] << " " << newRotate[1] << " " << newRotate[2] << " " << newRotate[3];
    cout << "done";
}