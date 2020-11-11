#include "engine.hpp"
#include <iostream>

Engine::Engine(const std::string& configPath) {
	config.setPath(configPath);
	config.parse();

	windowWidth = config.getOption("WINDOW_WIDTH");
	windowHeight = config.getOption("WINDOW_HEIGHT");
	marginTop = config.getOption("MARGIN_TOP");
	marginBetween = config.getOption("MARGIN_BETWEEN");

	sleepTime = config.getOption("DELAY_TIME_MS");

	window.create(sf::VideoMode(windowWidth, windowHeight), "Sorting Visualizer", sf::Style::Close);
	sortAlgorithm = nullptr;
}

void Engine::start() {
	if (!root.setFont("fonts/Vonique 64 Bold.ttf")) {
		return;
	}



	sortAlgorithm = std::make_unique<HeapSort>(sleepTime);
	root.setCurrentAlgorithm(sortAlgorithm->getAlgorithmName());
	array.clear();

	int count = config.getOption("BARS_COUNT");

	

	float sortviewWidth = windowWidth / float(count) - marginBetween;
	for (unsigned i = 1; i <= count; i++) {
		SortView sortview(i);

		// set height based on value here
		sortview.setSize(sortviewWidth, (i / float(count)) * (windowHeight - marginTop));
		
		array.push_back(sortview);
	}
	


	std::random_shuffle(array.begin(), array.end());

	mainLoop();
}

void Engine::sort() {
	sortAlgorithm->start(array);
}


void Engine::mainLoop() {
	while (window.isOpen()) {
		handleEvents();
		update();
		render();
	}
}

void Engine::handleEvents() {
	sf::Event event;
	while (window.pollEvent(event)) {
		switch (event.type) {

			case sf::Event::Closed:
				window.close();
				break;

			case sf::Event::KeyPressed: {
				switch (event.key.code) {

					case sf::Keyboard::Space:	{
						if (!sortAlgorithm->isRunning()) {
							std::thread(&Engine::sort, this).detach();
						}
						else{
							sortAlgorithm->stop();
							//std::cout << sortAlgorithm->isRunning();
						}
						break;
					}

					case sf::Keyboard::R:{
						if (!sortAlgorithm->isRunning())
						{
							std::random_shuffle(array.begin(), array.end());
							//root.setComparisons(0);
							//root.setSwaps(0);
						}
						break;
					}

				}

				break;
			}
		}
	}
}

void Engine::update() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::B)) {
		if (!sortAlgorithm->isRunning()) {
			sortAlgorithm = std::make_unique<BubbleSort>(sleepTime);
			root.setCurrentAlgorithm(sortAlgorithm->getAlgorithmName());
		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		if (!sortAlgorithm->isRunning()) {
			sortAlgorithm = std::make_unique<SelectionSort>(sleepTime);
			root.setCurrentAlgorithm(sortAlgorithm->getAlgorithmName());
		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::I)) {
		if (!sortAlgorithm->isRunning()) {
			sortAlgorithm = std::make_unique<InsertionSort>(sleepTime);
			root.setCurrentAlgorithm(sortAlgorithm->getAlgorithmName());
		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
		if (!sortAlgorithm->isRunning()) {
			sortAlgorithm = std::make_unique<QuickSort>(sleepTime);
			root.setCurrentAlgorithm(sortAlgorithm->getAlgorithmName());
		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::M)) {
		if (!sortAlgorithm->isRunning()) {
			sortAlgorithm = std::make_unique<MergeSort>(sleepTime);
			root.setCurrentAlgorithm(sortAlgorithm->getAlgorithmName());
		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::C)) {
		if (!sortAlgorithm->isRunning()) {
			sortAlgorithm = std::make_unique<CountingSort>(sleepTime);
			root.setCurrentAlgorithm(sortAlgorithm->getAlgorithmName());
		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::X)) {
		if (!sortAlgorithm->isRunning()) {
			sortAlgorithm = std::make_unique<RadixSort>(sleepTime);
			root.setCurrentAlgorithm(sortAlgorithm->getAlgorithmName());
		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::H)) {
		if (!sortAlgorithm->isRunning()) {
			sortAlgorithm = std::make_unique<HeapSort>(sleepTime);
			root.setCurrentAlgorithm(sortAlgorithm->getAlgorithmName());
		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::L)) {
		if (!sortAlgorithm->isRunning()) {
			sortAlgorithm = std::make_unique<ShellSort>(sleepTime);
			root.setCurrentAlgorithm(sortAlgorithm->getAlgorithmName());
		}
	}
//	if (sortAlgorithm->isRunning()) {
		root.setComparisons(sortAlgorithm->getComparisons());
		root.setSwaps(sortAlgorithm->getSwaps());
//	}
}

void Engine::render() {
	window.clear(sf::Color::Color(255, 153, 255, 255));
	root.render(window);

	float sortviewWidth = windowWidth / (float)array.size();
	for (unsigned x = 0; x < array.size(); x++) {
		array[x].render(window, (x + 1) * sortviewWidth - marginBetween);
	}

	window.display();
}


