#ifndef INSERTIONSORT_HPP
#define INSERTIONSORT_HPP

#include "sortAlgorithm.hpp"

class InsertionSort : public SortAlgorithm {
public:
	InsertionSort(const unsigned delayTime);
	void sort(std::vector<SortView>& array) override;
};

#endif