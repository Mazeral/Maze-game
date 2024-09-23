#include "main.h"

#define TWO_PI 6.28318530718f

float wrapAngle(float angle) {
    while (angle < 0.0f) angle += TWO_PI;
    while (angle >= TWO_PI) angle -= TWO_PI;
    return angle;
}
