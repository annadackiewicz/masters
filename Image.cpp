/*
 * Image.cpp
 *
 *      Author: Anna Dackiewicz.
 *      Master's thesis: Paralel computations in evolutionary algorithms with
 *                       tiling.
 */

#include "Image.h"


//#include <boost/gil/extension/io/jpeg_dynamic_io.hpp>
//#include <boost/gil>
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
	  return !error;
}

bool Image::saveImage(const char* filename) {
	std::vector<unsigned char> image = readImageToVector();
	unsigned error = lodepng::encode(filename, image, width, height);
	return !error;
}

void Image::readVectorToImage(const std::vector<unsigned char>& _image) {
	delete[] image;
	image = new Colour[width * height];

	for (int i = 0; i < _image.size(); i += 4) {
		int index = i/4;
		image[index]->r = _image[i];
		image[index]->g = _image[i+1];
		image[index]->b = _image[i+2];
		image[index]->a = _image[i+3];
	}
}

std::vector<unsigned char> Image::readImageToVector() const {
	std::vector<unsigned char> _image;
	for (int i = 0; i < width * height; ++i) {
		_image.push_back(image[i]->r);
		_image.push_back(image[i]->g);
		_image.push_back(image[i]->b);
		_image.push_back(image[i]->a);
	}
	return _image;
}
