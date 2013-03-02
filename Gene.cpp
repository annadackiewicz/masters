/*
 * Gene.cpp
 *
 *      Author: Anna Dackiewicz.
 *      Master's thesis: Paralel computations in evolutionary algorithms with
 *                       tiling.
 */

#include "Gene.h"

Gene::Gene() {
	// TODO Auto-generated constructor stub

}

Gene::~Gene() {
	// TODO Auto-generated destructor stub
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
const std::auto_ptr<Image> Gene::getImage() {
  return image_changed;
}



void Gene::mutateTransition(int dt_x, int dt_y) {
  transition.t_x += dt_x;
  if (transition.t_x > size.x) {
    transition.t_x -= size.x;
  }
  transition.t_y += dt_y;
  if (transition.t_y > size.y) {
    transition.t_y -+ size.y;
  }
}

void Gene::mutateScale(Uint8 ds_x, Uint8 ds_y) {
  scale.s_x += ds_x;
  scale.s_y += ds_y;
}

void Gene::mutateColour(Uint8 d_r, Uint8 d_g, Uint8 d_b, Uint8 d_t) {
  colour.red += d_r;
  colour.green += d_g;
  colour.blue += d_b;
  colour.transparency += d_t;
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


