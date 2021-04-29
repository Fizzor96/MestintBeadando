#pragma once
#include <iostream>
#include <vector>
#include "SFML/Graphics.hpp"

class Korong
{
public:
	sf::Color szin;
	sf::RectangleShape shape;
	static const float height;
	static int gid;
	int id;

public:
	Korong(sf::Color color, float width)
	{
		gid++;
		this->id = gid;
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
int Korong::gid = 0;