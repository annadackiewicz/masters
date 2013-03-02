/*
 * Gene.h
 *
 *  Created on: Jan 1, 2013
 *      Author: ania
 */

#ifndef UTILS_H_
#define UTILS_H_

#define Uint8 unsigned char

const float max_angle = 2.0;
const float min_angle = 0.0;


struct Colour {
	Uint8 red;
	Uint8 green;
	Uint8 blue;
	Uint8 transparency;
};

struct Size {
	int x;
	int y;
};

struct Scale {
	Uint8 s_x;
	Uint8 s_y;
};

struct Transition {
	int t_x;
	int t_y;
};

typedef struct                       /**** BMP file header structure ****/
{
    unsigned short bfType;           /* Magic number for file */
    unsigned int   bfSize;           /* Size of file */
    unsigned short bfReserved1;      /* Reserved */
    unsigned short bfReserved2;      /* ... */
    unsigned int   bfOffBits;        /* Offset to bitmap data */
} BITMAPFILEHEADER;
#endif /* UTILS_H_ */
