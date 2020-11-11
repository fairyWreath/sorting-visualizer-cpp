#include "quicksort.hpp"
#include <iostream>

QuickSort::QuickSort(const unsigned delayTime) {
	sleepTime = delayTime;
	name = "Quick Sort";
}

int QuickSort::partition(std::vector<SortView>& array, int leftMost, int rightMost) {
	int pivotIndex = rightMost;
	int storeIndex = leftMost - 1;
	for (int i = leftMost; i < rightMost; i++) {

		array[i].highlight(sf::Color::Magenta);
		array[pivotIndex].highlight(sf::Color::Magenta);
		
		std::this_thread::sleep_for(std::chrono::milliseconds(sleepTime));

		array[i].highlight();
		array[pivotIndex].highlight();
		
		if (compare(array[i], array[pivotIndex]) == -1) {
			storeIndex++;
			swap(array[i], array[storeIndex]);

			array[i].highlight(sf::Color::Green);
			array[pivotIndex].highlight(sf::Color::Green);

			std::this_thread::sleep_for(std::chrono::milliseconds(sleepTime));

			array[i].highlight();
			array[pivotIndex].highlight();
		}
	}
	swap(array[storeIndex + 1], array[rightMost]);
	return storeIndex + 1;
}

void QuickSort::quickSort(std::vector<SortView>& array, int leftMost, int rightMost) {
	if (leftMost < rightMost) {
		int pivotIndex = partition(array, leftMost, rightMost);
		quickSort(array, leftMost, pivotIndex - 1);
		quickSort(array, pivotIndex + 1, rightMost);
	}
}

void QuickSort::sort(std::vector<SortView>& array) {
	int left = 0;
	int right = array.size() - 1;
	quickSort(array, left, right);
}