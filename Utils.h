/*
 * Utils.h
 *
 *      Author: Anna Dackiewicz.
 *      Master's thesis: Paralel computations in evolutionary algorithms with
 *                       tiling.
 */

#ifndef UTILS_H_
#define UTILS_H_

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
};

struct Size {
	int x;
	int y;
};

struct Scale {
	float s_x;
	float s_y;
};

struct Transition {
	int t_x;
	int t_y;
};

int index2Dto1D();

std::pair<int, int> index1Dto2D();
