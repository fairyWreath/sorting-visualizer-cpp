#ifndef COUNTINGSORT_HPP
#define COUNTINGSORT_HPP

#include "sortAlgorithm.hpp"

class CountingSort : public SortAlgorithm {
public:
	CountingSort(const unsigned time);
	void sort(std::vector<SortView>& array) override;
};

#endif