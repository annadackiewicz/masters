/*
 * Genotype.cpp
 *
 *      Author: Anna Dackiewicz.
 *      Master's thesis: Paralel computations in evolutionary algorithms with
 *                       tiling.
 */

#include "Genotype.h"

#include <cstdlib>
#include "Gene.h"
#include "Image.h"


Genotype::Genotype(int number_of_genes, std::shared_ptr<Image> _true_image,
		std::vector<std::shared_ptr<Image> > _shapes) :
		shapes(_shapes),
		true_image (_true_image) {
	for (int i = 0; i < number_of_genes; ++i) {
		std::shared_ptr<Gene> gene;
		gene.reset(new Gene(shapes[rand() % shapes.size()],
				_true_image->getWidth(), _true_image->getHeight()));
		genes.push_back(gene);
	}
}

Genotype::Genotype(std::shared_ptr<Genotype> genotype) :
		genes(genotype->genes), image(NULL), true_image(genotype->true_image),
		shapes(genotype->shapes) {
}

Genotype::~Genotype() {
	// TODO Auto-generated destructor stub
}


void Genotype::mutate() {
	for (unsigned i = 0; i < genes.size(); ++i) {
		if (rand() / RAND_MAX > mutate_ratio) {
			genes[i]->mutate(shapes[rand() % shapes.size()]);
		}
	}
}
