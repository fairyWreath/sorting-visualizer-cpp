#ifndef BUBBLESORT_HPP
#define BUBBLESORT_HPP
#include "sortAlgorithm.hpp"

class BubbleSort : public SortAlgorithm {
public:
	BubbleSort(const unsigned time);
	void sort(std::vector<SortView>& array) override;
};

#endif