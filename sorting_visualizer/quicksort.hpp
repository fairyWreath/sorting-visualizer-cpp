#ifndef QUICKSORT_HPP
#define QUICKSORT_HPP

#include "sortAlgorithm.hpp"

class QuickSort : public SortAlgorithm {
public:
	QuickSort(const unsigned delayTime);

	void sort(std::vector<SortView>& array) override;

private:
	void quickSort(std::vector<SortView>& array, int leftMost, int rightMost);
	int partition(std::vector<SortView>& array, int leftMost, int rightMost);
};

#endif
