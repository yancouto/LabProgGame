#ifndef CAMERA_H
#define CAMERA_H

void Camera_Init();

double Camera_GetX();
double Camera_GetY();
double Camera_GetZ();

void Camera_Update(double dt);

#endif