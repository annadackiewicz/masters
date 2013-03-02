/*
 * Image.cpp
 *
 *      Author: Anna Dackiewicz.
 *      Master's thesis: Paralel computations in evolutionary algorithms with
 *                       tiling.
 */

#include "Image.h"


#include <boost/gil/extension/io/jpeg_dynamic_io.hpp>
#include <boost/gil>
#include <cassert>

Image::Image(int _width, int _height) :
	width(_width), height(_height) {
	// TODO Auto-generated constructor stub
	image = new Colour[width * height];
}

Image::~Image() {
	// TODO Auto-generated destructor stub
}


bool Image::loadImage(const char* filename) {
	  std::vector<unsigned char> image; //The raw pixels.
	  unsigned error = lodepng::decode(image, width, height, filename);
	  assert(!error);
}
