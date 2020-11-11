#include "sortview.hpp"


SortView::SortView() {};

SortView::SortView(const unsigned value) : view_color(sf::Color::Black) {
	view_value = value;
	view_shape.setFillColor(view_color);
}

void SortView::setSize(const float width, const float height) {
	view_shape.setSize(sf::Vector2f(width, height));
	view_shape.setOrigin(sf::Vector2f(width, height));
}

// get y value from window
void SortView::render(sf::RenderWindow& window, const float position) {
	view_shape.setPosition(position, window.getSize().y);
	window.draw(view_shape);
}

void SortView::highlight() {
	highlight(view_color);
}

unsigned SortView::getValue() {
	return view_value;
}

void SortView::highlight(const sf::Color& color) {
	view_shape.setFillColor(color);
}