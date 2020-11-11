#ifndef SELECTIONSORT_HPP
#define SELECTIONSORT_HPP

#include "sortAlgorithm.hpp"

class SelectionSort : public SortAlgorithm {
public:
	SelectionSort(const unsigned time);
	void sort(std::vector<SortView>& array) override;
};


#endif