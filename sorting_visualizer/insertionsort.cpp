#include "insertionsort.hpp"
#include <iostream>

InsertionSort::InsertionSort(const unsigned delayTime) {
	sleepTime = delayTime;
	name = "Insertion Sort";
}

void InsertionSort::sort(std::vector<SortView>& array) {
	for (signed i = 1; i < array.size(); i++) {
		SortView key = array[i];
		signed j = i - 1;

		while (compare(array[j], key) == 1  && j >= 0) {

			array[j + 1].highlight(sf::Color::Magenta);
			array[j].highlight(sf::Color::Magenta);

			std::this_thread::sleep_for(std::chrono::milliseconds(sleepTime));

			array[j + 1].highlight();
			array[j].highlight();

			array[j + 1] = array[j];

			j--;
			if (j < 0)
				break;
		}

		array[j + 1] = key;
	}
}