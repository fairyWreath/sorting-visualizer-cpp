#include "GUI.hpp"

GUI::GUI() {
	textInstructions.setCharacterSize(25);
	textComparisons.setCharacterSize(25);
	textSwaps.setCharacterSize(25);
	availableAlgorithmsFirst.setCharacterSize(25);
	availableAlgorithmsSecond.setCharacterSize(25);
	currentAlgorithmLabel.setCharacterSize(25);
	currentAlgorithm.setCharacterSize(25);

	textInstructions.setPosition(10, 10);
	textComparisons.setPosition(10, 40);
	textSwaps.setPosition(10, 60);
	availableAlgorithmsFirst.setPosition(10, 90);
	availableAlgorithmsSecond.setPosition(10, 120);
	currentAlgorithmLabel.setPosition(10, 150);
	currentAlgorithm.setPosition(300, 150);

	currentAlgorithm.setFillColor(sf::Color::Red);

	textInstructions.setString("[space] -> sort,  [r] -> reshuffle array");
	availableAlgorithmsFirst.setString("[b] Bubble sort --- [s] Selection sort --- [i] Insertion sort --- [m] Merge sort --- [q] Quicksort - [c] Counting sort");
	availableAlgorithmsSecond.setString("[x] Radix sort --- [h] Heap sort --- [l] Shell sort");
	currentAlgorithmLabel.setString("Current algorithm:   ");
	currentAlgorithm.setString("");
}

bool GUI::setFont(const std::string path) {
	if (!defaultFont.loadFromFile(path))
	{
		return false;
	}

	textInstructions.setFont(defaultFont);
	textComparisons.setFont(defaultFont);
	textSwaps.setFont(defaultFont);
	availableAlgorithmsFirst.setFont(defaultFont);
	availableAlgorithmsSecond.setFont(defaultFont);
	currentAlgorithmLabel.setFont(defaultFont);
	currentAlgorithm.setFont(defaultFont);
	return true;
}

void GUI::setComparisons(const unsigned comparisons) {
	textComparisons.setString("Comparisons: " + std::to_string(comparisons));
}

void GUI::setSwaps(const unsigned swaps) {
	textSwaps.setString("Swaps: " + std::to_string(swaps));
}

void GUI::setCurrentAlgorithm(const std::string& name) {
	currentAlgorithm.setString(name);
}

void GUI::render(sf::RenderWindow& window) const {
	window.draw(textInstructions);
	window.draw(textComparisons);
	window.draw(textSwaps);
	window.draw(availableAlgorithmsFirst);
	window.draw(availableAlgorithmsSecond);
	window.draw(currentAlgorithmLabel);
	window.draw(currentAlgorithm);
}