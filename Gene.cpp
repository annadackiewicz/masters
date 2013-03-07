/*
 * Gene.cpp
 *
 *      Author: Anna Dackiewicz.
 *      Master's thesis: Paralel computations in evolutionary algorithms with
 *                       tiling.
 */

#include "Gene.h"

#include <cstdlib>

Gene::Gene(std::shared_ptr<Image> _shape, int _width, int _height) {
	shape = _shape;
	size = Size(_width, _height);
	colour = Colour(rand() % 255, rand() % 255, rand() % 255, rand() % 255);
	transition = Transition(rand() % _width, rand() % _height);
	int rand_sc_x = rand() / RAND_MAX / scale_divide_by
			- scale_diff_from_one + 1;
	int rand_sc_y = rand() / RAND_MAX / scale_divide_by
			- scale_diff_from_one + 1;
	scale = Scale(rand_sc_x, rand_sc_y);
}

Gene::~Gene() {

}

const Transition Gene::getConstTransition() {
  return transition;
}

const Scale Gene::getConstScale() {
  return scale;
}
const Colour Gene::getConstColour() {
  return colour;
}
double Gene::getAngle() {
  return angle;
}
const std::shared_ptr<Image> Gene::getImage() {
  return image_changed;
}

void Gene::mutate(std::shared_ptr<Image> _shape) {
	shape = _shape;
	mutateTransition(rand() % size.x, rand() % size.y);
	mutateScale(rand() / RAND_MAX / 10, rand() / RAND_MAX / 10);
	mutateColour(rand() % 255, rand() % 255, rand() % 255, rand() % 255);
	mutateAngle(rand() / RAND_MAX / 10);
}

void Gene::mutateTransition(int dt_x, int dt_y) {
  transition.t_x += dt_x;
  if (transition.t_x > size.x) {
    transition.t_x -= size.x;
  }
  transition.t_y += dt_y;
  if (transition.t_y > size.y) {
	transition.t_y -= size.y;
  }
}

void Gene::mutateScale(float ds_x, float ds_y) {
  scale.s_x += ds_x;
  scale.s_y += ds_y;
}

void Gene::mutateColour(Uint8 d_r, Uint8 d_g, Uint8 d_b, Uint8 d_a) {
  colour.r += d_r;
  colour.g += d_g;
  colour.b += d_b;
  colour.a += d_a;
}

void Gene::mutateAngle(float d_angle) {
  angle += d_angle;
  while (angle > max_angle) {
    angle -= max_angle;
  }
  while (angle < min_angle) {
    angle += max_angle;
  }
}

