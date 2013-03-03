/*
 * Genotype.h
 *
 *      Author: Anna Dackiewicz.
 *      Master's thesis: Paralel computations in evolutionary algorithms with
 *                       tiling.
 */

#ifndef GENOTYPE_H_
#define GENOTYPE_H_

#include "Gene.h"

class Genotype {
public:
	Genotype(int number_of_genes, std::auto_ptr<Image> _true_image, std::vector<std::auto_ptr<Image> > _shapes);
	virtual ~Genotype();

	void mutate();

private:
	std::vector<Gene> genes;
	std::auto_ptr<Image> image;
	std::auto_ptr<Image> true_image;
	std::vector<std::auto_ptr<Image> > shapes;
};

#endif /* GENOTYPE_H_ */
