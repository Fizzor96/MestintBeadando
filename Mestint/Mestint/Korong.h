#pragma once
#include <iostream>
#include <vector>
#include "SFML/Graphics.hpp"

class Korong
{
public:
	sf::Color szin;
	sf::RectangleShape shape;

public:
	Korong(sf::Color color, float width)
	{
		this->szin = color;
		this->shape.setFillColor(color);
		this->shape.setSize(sf::Vector2f(width, 30.f));
		this->shape.setOrigin(sf::Vector2f(this->shape.getSize().x / 2, this->shape.getSize().y / 2));
	}
	~Korong() {}

};