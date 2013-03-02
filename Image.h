/*
 * Image.h
 *
 *      Author: Anna Dackiewicz.
 *      Master's thesis: Paralel computations in evolutionary algorithms with
 *                       tiling.
 */

#ifndef IMAGE_H_
#define IMAGE_H_

#include "Image.h"

class Image {
public:
	Image(int _width, int _height);
	virtual ~Image();

private:
	int id;
	unsigned width;
	unsigned height;

	Colour* image[];

	bool loadImage(const char* filename);
};

#endif /* IMAGE_H_ */
