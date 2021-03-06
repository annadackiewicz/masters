/*
 * Gene.h
 *
 *      Author: Anna Dackiewicz.
 *      Master's thesis: Paralel computations in evolutionary algorithms with
 *                       tiling.
 */

#ifndef GENE_H_
#define GENE_H_

#include <memory>

#include "Utils.h"

class Image;

class Gene {
public:
	Gene(std::shared_ptr<Image> _shape, int _width, int _height);
	~Gene();

	const Transition getConstTransition();
	const Scale getConstScale();
	const Colour getConstColour();
	double getAngle();

	const std::shared_ptr<Image> getImage();

	void mutate(std::shared_ptr<Image> _shape);

	void mutateTransition(int dt_x, int dt_y);
	void mutateScale(float ds_x, float ds_y);
	void mutateColour(Uint8 d_r, Uint8 d_g, Uint8 d_b, Uint8 d_a);
	void mutateAngle(float d_angle);

private:
	// The size of the image we want to cover.
	Size size;
	// The colour of the shape.
	Colour colour;
	// The transition from the left upper corner of the
	Transition transition;
	// The scale of the shape.
	Scale scale;
	// The
	float angle;

	std::shared_ptr<Image> shape;
	std::shared_ptr<Image> image_changed;
};

#endif /* GENE_H_ */
