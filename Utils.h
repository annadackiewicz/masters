/*
 * Utils.h
 *
 *      Author: Anna Dackiewicz.
 *      Master's thesis: Paralel computations in evolutionary algorithms with
 *                       tiling.
 */

#ifndef UTILS_H_
#define UTILS_H_

#include <utility>

#define Uint8 unsigned char

const float max_angle = 2.0;
const float min_angle = 0.0;

const float scale_diff_from_one = 0.1;
const int scale_divide_by = 20;

const float mutate_ratio = 0.2;


struct Colour {
	Uint8 r;
	Uint8 g;
	Uint8 b;
	Uint8 a;
	Colour(Uint8 _r, Uint8 _g, Uint8 _b, Uint8 _a) :
		r(_r), g(_g), b(_b), a(_a) {}
	Colour() : r(0), g(0), b(0), a(0) {}
};

struct Size {
	int x;
	int y;
	Size(int _x, int _y) : x(_x), y(_y) {}
	Size() : x(0), y(0) {}
};

struct Scale {
	float s_x;
	float s_y;
	Scale(float _s_x, float _s_y) : s_x(_s_x), s_y(_s_y) {}
	Scale() : s_x(0), s_y(0) {}
};

struct Transition {
	int t_x;
	int t_y;
	Transition(int _t_x, int _t_y) : t_x(_t_x), t_y(_t_y) {}
	Transition() : t_x(0), t_y(0) {}
};

int index2Dto1D();

std::pair<int, int> index1Dto2D();

#endif /* UTILS_H_ */
