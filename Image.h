/*
 * Image.h
 *
 *      Author: Anna Dackiewicz.
 *      Master's thesis: Paralel computations in evolutionary algorithms with
 *                       tiling.
 */

#ifndef IMAGE_H_
#define IMAGE_H_

#include <memory>
#include <vector>

struct Colour;

class Image {
public:
	Image(unsigned _width, unsigned _height);
	virtual ~Image();
	bool loadImage(const char* filename);
	bool saveImage(const char* filename);
	unsigned getWidth();
	unsigned getHeight();

private:
	int id;
	unsigned width;
	unsigned height;

	std::vector<std::auto_ptr<Colour> > image;

	void readVectorToImage(const std::vector<unsigned char>& _image);
	std::vector<unsigned char> readImageToVector() const;
};

#endif /* IMAGE_H_ */
