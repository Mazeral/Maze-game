#include "main.h"
/**
 * updateRayAngle - a function to update the ray angle
 * @keystates: the input from the user
 * Return: Nothing
 */
#include <stdio.h>  // For printf()

// void update_ray_angle(const Uint8* keystates)
// {
//     float rotationSpeed = 0.08f; // Adjust for desired rotation speed
// 	float watcher = 0;
//
//     if (keystates[SDL_SCANCODE_LEFT])
//     {
//         ray_angle -= rotationSpeed;
//         if (ray_angle < 0)
//         {
//             ray_angle += 2 * M_PI; // Wrap around to 360 degrees
// 		if (watcher != ray_angle)
// 		{
// 			watcher = ray_angle;
// 		    printf("Ray Angle (Left Rotation): %f\n", ray_angle); // Debug output
// 		}
//         }
//     }
//     else if (keystates[SDL_SCANCODE_RIGHT])
//     {
//         ray_angle += rotationSpeed;
//         if (ray_angle >= 2 * M_PI)
//         {
//             ray_angle -= 2 * M_PI; // Wrap around to 0 degrees
// 		if (watcher != ray_angle)
// 		{
// 			watcher = ray_angle;
// 		    printf("Ray Angle (right Rotation): %f\n", ray_angle); // Debug output
// 		}
//         }
//     }
// }
//
void update_ray_angle(const Uint8 *keystates, float *ray_angle)
{
    float rotation_speed = 0.05f;  // Adjust rotation speed as needed

    if (keystates[SDL_SCANCODE_LEFT])
    {
        *(ray_angle) -= rotation_speed;
        if (*ray_angle < 0) {
            *ray_angle += 2 * M_PI;  // Wrap around
        }
    }

    if (keystates[SDL_SCANCODE_RIGHT])
    {
        *ray_angle += rotation_speed;
        if (*ray_angle >= 2 * M_PI) {
            *ray_angle -= 2 * M_PI;  // Wrap around
        }
    }
}
