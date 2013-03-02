/*
 * Image.cpp
 *
 *  Created on: Jan 1, 2013
 *      Author: ania
 */

#include "Image.h"

#include <boost/gil/extension/io/jpeg_dynamic_io.hpp>
#include <boost/gil>

Image::Image(int _size_x, int _size_y) :
	size_x(_size_x), size_y(_size_y) {
	// TODO Auto-generated constructor stub
	image = new Colour[size_x * size_y];
}

Image::~Image() {
	// TODO Auto-generated destructor stub
}


bool Image::loadImage() {

}
