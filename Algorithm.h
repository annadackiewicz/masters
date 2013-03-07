/*
 * Algorithm.h
 *
 *  Created on: Mar 7, 2013
 *      Author: ania
 */

#ifndef ALGORITHM_H_
#define ALGORITHM_H_

#include "Population.h"

class Algorithm {
public:
	Algorithm();
	virtual ~Algorithm();
private:
	std::auto_ptr<Population> population;
	Image* image;
	std::vector<std::shared_ptr<Image> > shapes;
};

#endif /* ALGORITHM_H_ */
