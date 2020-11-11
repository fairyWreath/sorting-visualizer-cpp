#include "heapsort.hpp"
#include <iostream>

HeapSort::HeapSort(const unsigned time) {
	sleepTime = time;
	name = "Heap Sort";
}


void HeapSort::heapify(std::vector<SortView>& array, int n, int i) {

	int largest = i;
	int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n) {
        array[left].highlight(sf::Color::Magenta);
        array[largest].highlight(sf::Color::Magenta);
        std::this_thread::sleep_for(std::chrono::milliseconds(sleepTime));
        array[left].highlight();
        array[largest].highlight();
    }
  
    if (left < n && compare(array[left], array[largest]) == 1) {
        largest = left;
    }
    

    if (right < n) {
        array[right].highlight(sf::Color::Magenta);
        array[largest].highlight(sf::Color::Magenta);
        std::this_thread::sleep_for(std::chrono::milliseconds(sleepTime));
        array[right].highlight();
        array[largest].highlight();
    }

    if (right < n && compare(array[right], array[largest]) == 1) {
        largest = right;
    }

    if (largest != i) {
        array[right].highlight(sf::Color::Green);
        array[largest].highlight(sf::Color::Green);
        std::this_thread::sleep_for(std::chrono::milliseconds(sleepTime));
        array[right].highlight();
        array[largest].highlight();

        swap(array[i], array[largest]);
        heapify(array, n, largest);
    }
}

void HeapSort::heapSort(std::vector<SortView>& array) {
    int arraySize = array.size();

    for (int i = arraySize / 2 - 1; i >= 0; i--)
        heapify(array, arraySize, i);

 
    for (int i = arraySize - 1; i >= 0; i--) {
        array[0].highlight(sf::Color::Green);
        array[i].highlight(sf::Color::Green);
        std::this_thread::sleep_for(std::chrono::milliseconds(sleepTime));
        array[0].highlight();
        array[i].highlight();

        swap(array[0], array[i]);

        heapify(array, i, 0);
    }
}

void HeapSort::sort(std::vector<SortView>& array) {
    heapSort(array);
}