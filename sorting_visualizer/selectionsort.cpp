#include "selectionsort.hpp"

SelectionSort::SelectionSort(const unsigned time) {
	sleepTime = time;
	name = "Selection Sort";
}

void SelectionSort::sort(std::vector<SortView>& array) {
	for (unsigned i = 0; i < array.size(); i++) {
		unsigned minimumIndex = i;

		for (unsigned j = i + 1; j < array.size(); j++) {

			if (!m_isRunning) {
				return;
			}

			array[j].highlight(sf::Color::Magenta);
			array[minimumIndex].highlight(sf::Color::Magenta);

			std::this_thread::sleep_for(std::chrono::milliseconds(sleepTime));

			array[j].highlight();
			array[minimumIndex].highlight();

			if (compare(array[minimumIndex], array[j]) == 1) {
				minimumIndex = j;
			}

		}

		array[i].highlight(sf::Color::Green);
		array[minimumIndex].highlight(sf::Color::Green);

		swap(array[minimumIndex], array[i]);

		std::this_thread::sleep_for(std::chrono::milliseconds(sleepTime));

		array[i].highlight();
		array[minimumIndex].highlight();

	}
}