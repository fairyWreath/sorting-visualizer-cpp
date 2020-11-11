#ifndef SORTALGORITHM_HPP
#define SORTALGORITHM_HPP

#include "sortview.hpp"
#include <thread>
#include <vector>
#include <chrono>

class SortAlgorithm {
public:
	SortAlgorithm();
	virtual ~SortAlgorithm() = default;		// destructor, virtual so derived classes can be destructed correctly


	void setSleepTime(const unsigned time);

	void start(std::vector<SortView>& array);
	void stop();
	bool isRunning() const;
	std::string getAlgorithmName() const;
	unsigned getComparisons() const;
	unsigned getSwaps() const;

protected:
	std::string name;
	unsigned sleepTime;
	unsigned comparisons;
	unsigned swaps;
	bool m_isRunning;

	// virtual functions allow derived classes to provide a different version of the base function
	virtual void sort(std::vector<SortView>& array) = 0;
	void swap(SortView& first, SortView& second);
	int compare(SortView& first, SortView& second);
};




#endif