#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "SFML/Graphics.hpp"

class Korong
{
public:
	sf::Color szin;
	sf::RectangleShape shape;
	static const float height;
	std::string oszlopid;

public:
	Korong(sf::Color color, float width)
	{
		this->szin = color;
		this->shape.setFillColor(color);
		this->shape.setSize(sf::Vector2f(width, height));
		this->shape.setOrigin(sf::Vector2f(this->shape.getSize().x / 2, this->shape.getSize().y / 2));
		this->shape.setOutlineColor(sf::Color::Black);
		this->shape.setOutlineThickness(1.f);
	}
	~Korong() {}

};

const float Korong::height = 25.f;