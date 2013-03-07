/*
 * Image.cpp
 *
 *      Author: Anna Dackiewicz.
 *      Master's thesis: Paralel computations in evolutionary algorithms with
 *                       tiling.
 */

#include "Image.h"

//#include <boost/gil>
#include "Utils.h"
#include "lodepng.h"
#include <cassert>

Image::Image(unsigned _width, unsigned _height) :
		width(_width), height(_height) {
	image.resize(width * height);
}

Image::~Image() {

}

bool Image::loadImage(const char* filename) {
	  std::vector<unsigned char> _image; //The raw pixels.
	  unsigned error = lodepng::decode(_image, width, height, filename);
	  readVectorToImage(_image);
	  return !error;
}

bool Image::saveImage(const char* filename) {
	std::vector<unsigned char> image = readImageToVector();
	unsigned error = lodepng::encode(filename, image, width, height);
	return !error;
}

unsigned Image::getWidth() {
	return width;
}

unsigned Image::getHeight() {
	return height;
}

void Image::readVectorToImage(const std::vector<unsigned char>& _image) {
	image.resize(width * height);
	for (unsigned i = 0; i < _image.size(); i += 4) {
		unsigned index = i/4;
		image[index]->r = _image[i];
		image[index]->g = _image[i+1];
		image[index]->b = _image[i+2];
		image[index]->a = _image[i+3];
	}
}

std::vector<unsigned char> Image::readImageToVector() const {
	std::vector<unsigned char> _image;
	for (unsigned i = 0; i < width * height; ++i) {
		_image.push_back(image[i]->r);
		_image.push_back(image[i]->g);
		_image.push_back(image[i]->b);
		_image.push_back(image[i]->a);
	}
	return _image;
}
