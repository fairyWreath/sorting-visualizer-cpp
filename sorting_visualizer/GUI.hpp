#ifndef GUI_HPP
#define GUI_HPP

#include <SFML/Graphics.hpp>

class GUI {
public:
	GUI();
	bool setFont(const std::string path);
	void setComparisons(const unsigned comparisons);
	void setSwaps(const unsigned swaps);
	void setCurrentAlgorithm(const std::string& name);

	void render(sf::RenderWindow& window) const;

private:
	sf::Font defaultFont;
	sf::Text textInstructions;
	sf::Text textComparisons;
	sf::Text textSwaps;
	sf::Text availableAlgorithmsFirst;
	sf::Text availableAlgorithmsSecond;
	sf::Text currentAlgorithmLabel;
	sf::Text currentAlgorithm;
};
#endif 
