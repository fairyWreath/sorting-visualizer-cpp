#ifndef HEAPSORT_HPP
#define HEAPSORT_HPP

#include "sortAlgorithm.hpp"

class HeapSort : public SortAlgorithm {
public:
	HeapSort(const unsigned time);
	void sort(std::vector<SortView>& array) override;

private:
	void heapSort(std::vector<SortView>& array);
	void heapify(std::vector<SortView>& array, int n, int i);

};

#endif