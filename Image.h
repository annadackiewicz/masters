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
	Image(int _size_x, int size_y);
	virtual ~Image();

private:
	int id;
	const int size_x;
	const int size_y;

	Colour* image[];

	bool loadImage();
};

#endif /* IMAGE_H_ */
