#include "countingsort.hpp"
#include <iostream>
CountingSort::CountingSort(const unsigned time) {
	sleepTime = time;
	name = "Counting Sort";
}

void CountingSort::sort(std::vector<SortView>& array) {
	unsigned arraySize = array.size();

	SortView max = array[0];

	for (int i = 1; i <arraySize; i++) {

		array[i].highlight(sf::Color::Magenta);
		std::this_thread::sleep_for(std::chrono::milliseconds(sleepTime));
		array[i].highlight();

		if (compare(max, array[i]) == -1) {
			max = array[i];
			
		}
	}

	unsigned maxValue = max.getValue();

	std::vector<int> count(maxValue + 1, 0);

	for (int i = 0; i < arraySize; i++) {
		count[array[i].getValue()]++;
	}

	for (int i = 1; i <= arraySize; i++) {
		count[i] += count[i - 1];
	}
	
	std::vector<SortView> output(arraySize);

	for (int x = 0; x < arraySize; x++) {
		int index = count[array[x].getValue()] - 1;
		output[index] = array[x];
		count[array[x].getValue()]--;
	}

	array = output;


}