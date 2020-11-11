#ifndef MERGESORT_HPP
#define MERGESORT_HPP

#include "sortAlgorithm.hpp"

class MergeSort : public SortAlgorithm {
public:
	MergeSort(const unsigned delayTime);
	void sort(std::vector<SortView>& array) override;

private:
	void mergeSort(std::vector<SortView>& array, int left, int right);
	void merge(std::vector<SortView>& array, int left, int middle, int right);
	std::vector<SortView> slice(std::vector<SortView>& array, int first, int last);
};

#endif
