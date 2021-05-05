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

	float szelesseg;
	static float originalWidth;
	static int refcounter;
	int id;
	
	const sf::Color c1 = sf::Color::Green;
	const sf::Color c2 = sf::Color::Blue;

public:
	Korong()
	{
		this->id = refcounter;
		refcounter++;
		if (id % 2 == 0)
		{
			this->szin = c1;
		}
		else
		{
			this->szin = c2;
		}

		this->szelesseg = originalWidth - (refcounter % 7) * 20.f;

		this->shape.setFillColor(szin);
		this->shape.setSize(sf::Vector2f(szelesseg, height));
		this->shape.setOrigin(sf::Vector2f(this->shape.getSize().x / 2, this->shape.getSize().y / 2));
		this->shape.setOutlineColor(sf::Color::Black);
		this->shape.setOutlineThickness(1.f);
		//std::cout << this->id << std::endl;
	}

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
int Korong::refcounter = 0;
float Korong::originalWidth = 200.f;