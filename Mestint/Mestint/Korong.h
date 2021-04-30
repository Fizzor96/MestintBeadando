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
	static int kid;
	static float gwidth;
	int id;
	float width;
	std::string oszlopid;

public:
	Korong(sf::Color color, std::string oszlopid)
	{
		kid++;
		this->id = kid;
		if (kid >= 2 && kid % 2 == 0)
		{
			gwidth -= 20.f;
			this->width = gwidth;
		}
		else
		{
			this->width = gwidth;
		}
		this->szin = color;
		this->shape.setFillColor(color);
		this->shape.setSize(sf::Vector2f(width, height));
		this->shape.setOrigin(sf::Vector2f(this->shape.getSize().x / 2, this->shape.getSize().y / 2));
		this->shape.setOutlineColor(sf::Color::Black);
		this->shape.setOutlineThickness(1.f);
		this->oszlopid = oszlopid;
	}

	//Korong(sf::Color color, float widthh)
	//{
	//	kid++;
	//	this->id = kid;
	//	this->szin = color;
	//	this->shape.setFillColor(color);
	//	this->shape.setSize(sf::Vector2f(widthh, height));
	//	this->shape.setOrigin(sf::Vector2f(this->shape.getSize().x / 2, this->shape.getSize().y / 2));
	//	this->shape.setOutlineColor(sf::Color::Black);
	//	this->shape.setOutlineThickness(1.f);
	//}
	~Korong() {}

	bool Equals(const Korong& other)
	{
		if (this == &other)
		{
			return true;
		}
		return false;
	}

};