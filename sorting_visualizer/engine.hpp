#ifndef ENGINE_HPP
#define ENGINE_HPP

#include "sortAlgorithm.hpp"

#include "bubblesort.hpp"
#include "selectionsort.hpp"
#include "insertionsort.hpp"
#include "quicksort.hpp"
#include "mergesort.hpp"
#include "countingsort.hpp"
#include "radixsort.hpp"
#include "heapsort.hpp"
#include "shellsort.hpp"

#include "GUI.hpp"
#include "config.hpp"

#include <thread>

class Engine {
public:
	Engine(const std::string& configPath);
	void start();

private:
	unsigned windowWidth;
	unsigned windowHeight;
	unsigned marginTop;
	unsigned marginBetween;
	unsigned sleepTime;

	Config config;

	sf::RenderWindow window;
	GUI root;

	std::vector<SortView> array;
	std::unique_ptr<SortAlgorithm> sortAlgorithm;

	void mainLoop();
	void handleEvents();
	void update();
	void render();
	void sort();
};


#endif