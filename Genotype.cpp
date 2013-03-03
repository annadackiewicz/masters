/*
 * Genotype.cpp
 *
 *      Author: Anna Dackiewicz.
 *      Master's thesis: Paralel computations in evolutionary algorithms with
 *                       tiling.
 */

#include "Genotype.h"

Genotype::Genotype(int number_of_genes, std::auto_ptr<Image> _true_image,
		std::vector<std::auto_ptr<Image> > _shapes) :
		shapes(_shapes), true_image (_true_image) {
	for (int i = 0; i < number_of_genes; ++i) {
		Gene* gene = new Gene(shapes[rand() % shapes.size()],
				_true_image->getWidth(), _true_image->getHeight());

	}
}

Genotype::~Genotype() {
	// TODO Auto-generated destructor stub
}

