#ifndef RADIXSORT_HPP
#define RADIXSORT_HPP

#include "sortAlgorithm.hpp"

class RadixSort : public SortAlgorithm {
public:
	RadixSort(const unsigned time);
	void sort(std::vector<SortView>& array) override;

private:
	SortView getMax(std::vector<SortView>& array);
	void countingSort(std::vector<SortView>& array, int place);
	void radixSort(std::vector<SortView>& array);

};


#endif