#include "sortAlgorithm.hpp"

SortAlgorithm::SortAlgorithm() {
	sleepTime = 0;
	comparisons = 0;
	swaps = 0;
	m_isRunning = false;
}

void SortAlgorithm::start(std::vector<SortView>& array) {
	comparisons = 0;
	swaps = 0;
	m_isRunning = true;
	sort(array);
	m_isRunning = false;
}

void SortAlgorithm::stop() {
	comparisons = 0;
	swaps = 0;
	m_isRunning = false;
}

void SortAlgorithm::setSleepTime(const unsigned time) {
	sleepTime = time;
}

bool SortAlgorithm::isRunning() const {
	return m_isRunning;
}

std::string SortAlgorithm::getAlgorithmName() const {
	return name;
}


unsigned SortAlgorithm::getComparisons() const {
	return comparisons;
}

unsigned SortAlgorithm::getSwaps() const {
	return swaps;
}

void SortAlgorithm::swap(SortView& first, SortView& second) {
	SortView temp = first;
	first = second;
	second = temp;

	swaps++;
}

int SortAlgorithm::compare(SortView& first, SortView& second) {
	comparisons++;
	// conditional ternary operator
	// if first < second -> -1
	// if first > second -> 1
	// if equal -> 0
	return (first < second ? -1 : (first > second ? 1 : 0));
}