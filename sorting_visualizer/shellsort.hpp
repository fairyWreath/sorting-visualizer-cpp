#ifndef SHELLSORT_HPP
#define SHELLSORT_HPP

#include "sortAlgorithm.hpp"

class ShellSort : public SortAlgorithm {
public:
	ShellSort(const unsigned time);
	void sort(std::vector<SortView>& array) override;
};
#endif