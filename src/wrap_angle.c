#include "main.h"

#define TWO_PI 6.28318530718f
/**
 * wrap_angle - Wraps an angle to ensure it is within the range of 0 to 2π
 * @angle: The angle to be wrapped
 * Return: The wrapped angle
 */
float wrap_angle(float angle)
{
	/* Ensure the angle is positive and within the 0 to 2π range */
	while (angle < 0.0f)
		angle += TWO_PI;

	while (angle >= TWO_PI)
		angle -= TWO_PI;

	return (angle);
}
