#ifndef SECTION_H
#define SECTION_H

typedef struct {
	double x;			
	double y;
	double z;

	double width;
	double length;
	double height;

	List* entities;
} Section;

/* Constructor de Section. */
Section* Section_new(double x, double y, double z, 
	double width, double length, double height, int enemies);

#endif