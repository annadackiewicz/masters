/*
 * Utils.cpp
 *
 *      Author: Anna Dackiewicz.
 *      Master's thesis: Paralel computations in evolutionary algorithms with
 *                       tiling.
 */

#include "Utils.h"


int index2Dto1D(int x, int y, int width) {
	return y*width+x;
}

std::pair<int, int> index1Dto2D(int index, int width) {
	return std::make_pair(index%width, (int)(index/width));
}
