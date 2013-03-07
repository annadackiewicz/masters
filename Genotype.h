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

#include <vector>

class Genotype {
public:
	Genotype(int number_of_genes,
			std::shared_ptr<Image> _true_image,
			std::vector<std::shared_ptr<Image> > _shapes);
	Genotype(std::shared_ptr<Genotype> genotype);
	virtual ~Genotype();

	void mutate();
	void createImage();
	//void

private:
	std::vector<std::shared_ptr<Gene> > genes;
	std::shared_ptr<Image> image;
	std::shared_ptr<Image> true_image;
	std::vector<std::shared_ptr<Image> > shapes;
};

#endif /* GENOTYPE_H_ */
