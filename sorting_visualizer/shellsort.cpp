#include "shellsort.hpp"

ShellSort::ShellSort(const unsigned time){
	sleepTime = time;
	name = "Shell Sort";
}

void ShellSort::sort(std::vector<SortView>& array) {

	for (int interval = array.size() / 2; interval > 0; interval /= 2) {
		for (int i = interval; i < array.size(); i += 1) {
			SortView temp = array[i];
			
			array[i].highlight(sf::Color::Magenta);
			std::this_thread::sleep_for(std::chrono::milliseconds(sleepTime));
			array[i].highlight();

			int j;
			for (j = i; j >= interval && array[j - interval] > temp; j -= interval) {
				array[j] = array[j - interval];

				array[j].highlight(sf::Color::Magenta);
				std::this_thread::sleep_for(std::chrono::milliseconds(sleepTime));
				array[j].highlight();
			}
			array[j] = temp;
		}
	}
}