#include "bubblesort.hpp"

BubbleSort::BubbleSort(const unsigned time) {
	sleepTime = time;
	name = "Bubble Sort";
}

void BubbleSort::sort(std::vector<SortView>& array) {
	for (unsigned x = 0; x < array.size(); x++) {
		bool hasSwapped = false;
		for (unsigned y = 0; y < array.size() - x - 1; y++) {
			
			if (!m_isRunning) {
				return;
			}
			
			// ----- for visual ----- //

			// highlight objects that will be compared
			array[y].highlight(sf::Color::Magenta);
			array[y + 1].highlight(sf::Color::Magenta);

			// use thread to sleep
			std::this_thread::sleep_for(std::chrono::milliseconds(sleepTime));

			// reset to normal
			array[y].highlight();
			array[y + 1].highlight();

			// ----- end visual ----- //

			// 1  means first is greater than second
			if (compare(array[y], array[y + 1]) == 1) {
				array[y].highlight(sf::Color::Green);
				array[y+1].highlight(sf::Color::Green);
				
				swap(array[y], array[y + 1]);
				hasSwapped = true;

				std::this_thread::sleep_for(std::chrono::milliseconds(sleepTime));

				array[y].highlight();
				array[y + 1].highlight();
			}

		}

		// if no swaps are made, array already sorted
		if (!hasSwapped) {
			break;
		}
	}
}