#ifndef SORTVIEW_HPP
#define SORTVIEW_HPP

#include <SFML/Graphics.hpp>

class SortView {
public:
	SortView();
	SortView(const unsigned value);
	void setSize(const float width, const float height);
	void render(sf::RenderWindow& window, const float position);
	void highlight();		// reset to no colour
	void highlight(const sf::Color& color);

	bool operator >(const SortView& compare) {
		return view_value > compare.view_value;
	}

	bool operator <(const SortView& compare) {
		return view_value < compare.view_value;
	}

	unsigned getValue();

private:
	unsigned view_value;
	sf::RectangleShape view_shape;
	sf::Color view_color;
};


#endif
