#include "radixsort.hpp"
#include <iostream>

RadixSort::RadixSort(const unsigned time) {
	sleepTime = time;
	name = "Radix sort";
}

SortView RadixSort::getMax(std::vector<SortView>& array) {
	SortView max = array[0];

	for (int i = 1; i < array.size(); i++) {
		array[i].highlight(sf::Color::Magenta);
		std::this_thread::sleep_for(std::chrono::milliseconds(sleepTime));
		array[i].highlight();


		if (compare(max, array[i]) == -1) {
			max = array[i];
		}
	}

	return max;
}


void RadixSort::countingSort(std::vector<SortView>& array, int place) {
	const int max = 10;
	int arraySize = array.size();

	std::vector<SortView> output(arraySize);
	std::vector<int> count(max + 1, 0);

	for (int i = 0; i < arraySize; i++)
		count[(array[i].getValue() / place) % 10]++;

	for (int i = 1; i < max; i++)
		count[i] += count[i - 1];


	for (int i = arraySize - 1; i >= 0; i--) {
		int index = count[(array[i].getValue() / place) % 10] - 1;
		
		array[i].highlight(sf::Color::Green);
		array[index].highlight(sf::Color::Green);
		std::this_thread::sleep_for(std::chrono::milliseconds(sleepTime));
		array[i].highlight();
		array[index].highlight();

		output[index] = array[i];
		count[(array[i].getValue() / place) % 10]--;
	}

	array = output;
}

void RadixSort::radixSort(std::vector<SortView>& array) {
	SortView max = getMax(array);

	std::cout << max.getValue();

	for (int place = 1; max.getValue() / place > 0; place *= 10)
		countingSort(array, place);
}


void RadixSort::sort(std::vector<SortView>& array) {
	radixSort(array);
}