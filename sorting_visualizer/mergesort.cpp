#include "mergesort.hpp"
#include <iostream>

MergeSort::MergeSort(const unsigned delayTime) {
	sleepTime = delayTime;
	name = "Merge Sort";
}


std::vector<SortView> MergeSort::slice(std::vector<SortView>& array, int first, int last) {
	auto start = array.begin() + first;
	auto end = array.begin() + last;

	std::vector<SortView> result(last - first);     // use () to declare size
	copy(start, end, result.begin());
	return result;
}


void MergeSort::mergeSort(std::vector<SortView>& array, int left, int right) {
	if ( (right - left) > 1) {
		int middle = (right - left)/2;
		mergeSort(array, left, left + middle);
		mergeSort(array, left + middle, right);

		merge(array, left, middle, right);
	}
}



void MergeSort::merge(std::vector<SortView>& array, int left, int middle, int right) {
	std::vector<SortView> arr1;
	std::vector<SortView> arr2;

	arr1 = slice(array, left, left + middle);
	arr2 = slice(array, left + middle, right);

	int firstIndex = left;
	int secondIndex = left + middle;

	int firstArrayMax = middle;
	int secondArrayMax = right;

	int i = 0, j = 0;
	int k = left;

	while (i < arr1.size() && j < arr2.size()) {

		array[firstIndex + i].highlight(sf::Color::Magenta);
		array[secondIndex + j].highlight(sf::Color::Magenta);

		std::this_thread::sleep_for(std::chrono::milliseconds(sleepTime));

		array[firstIndex + i].highlight();
		array[secondIndex + j].highlight();

		if (compare(arr1[i], arr2[j]) == -1) {
			array[k] = arr1[i];
			i++;
		}
		else {
			array[k] = arr2[j];
			j++;
		}

		k++;
	}

	while (i < arr1.size()) {        
		array[k] = arr1[i];
		i++;
		k++;
	}

	while (j < arr2.size()) {       
		array[k] = arr2[j];
		j++;
		k++;
	}
}

void MergeSort::sort(std::vector<SortView>& array) {
	mergeSort(array, 0, array.size());
}