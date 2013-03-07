/*
 * Population.cpp
 *
 *      Author: Anna Dackiewicz.
 *      Master's thesis: Paralel computations in evolutionary algorithms with
 *                       tiling.
 */

#include "Population.h"

#include "Genotype.h"

Population::Population(int number_genotypes, int number_genes,
		std::shared_ptr<Image> _true_image,
		std::vector<std::shared_ptr<Image> > _shapes) :
		true_image(_true_image) {
	for (int i = 0; i < number_genotypes; ++i) {
		std::auto_ptr<Genotype> genotype;
		genotype.reset(new Genotype(number_genes, _true_image, _shapes));
	}

}

Population::~Population() {
	// TODO Auto-generated destructor stub
}

