#ifndef CAMERA_H
#define CAMERA_H

void Camera_Init();

double Camera_GetX();
double Camera_GetY();
double Camera_GetZ();

double Camera_GetToX();
double Camera_GetToY();
double Camera_GetToZ();

void Camera_Update(double dt);

#endif