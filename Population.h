/*
 * Population.h
 *
 *      Author: Anna Dackiewicz.
 *      Master's thesis: Paralel computations in evolutionary algorithms with
 *                       tiling.
 */

#ifndef POPULATION_H_
#define POPULATION_H_

#include <memory>
#include <vector>

class Genotype;
class Image;

class Population {
public:
	Population(int number_genotypes, int number_genes,
			std::shared_ptr<Image> _true_image,
			std::vector<std::shared_ptr<Image> > _shapes);
	virtual ~Population();
private:
	std::vector<std::auto_ptr<Genotype> > genotypes;
	std::shared_ptr<Image> true_image;
	std::vector<std::shared_ptr<Image> > shapes;
};

#endif /* POPULATION_H_ */


