#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "SFML/Graphics.hpp"
#include "Korong.h"

class Oszlop
{
public:
	char nev;
	sf::Vector2f hely;
	sf::RectangleShape shape;
	std::vector<Korong*> korongstack;

public:
	Oszlop(char name, sf::Vector2f location)
	{
		this->nev = name;
		this->hely = location;
		this->shape.setSize(sf::Vector2f(10.f, 350.f));
		this->shape.setFillColor(sf::Color(128, 128, 128, 255));
		this->shape.setOrigin(sf::Vector2f(this->shape.getSize().x / 2, 335.f));
		this->shape.setPosition(location);
	}

	~Oszlop(){}

	void Berak(Korong* korong)
	{
		if (korongstack.size() <= 0)
		{
			korong->shape.setPosition(this->shape.getPosition().x, this->shape.getPosition().y);
		}
		else
		{
			korong->shape.setPosition(this->shape.getPosition().x, (this->korongstack[this->korongstack.size() - 1]->shape.getPosition().y - 30.f));
		}
		this->korongstack.push_back(korong);
		std::cout << "Korong berakva a " << this->nev << " nevu rudra!" << std::endl;

	}

	Korong* Kivesz()
	{
		if (this->korongstack.size() > 0)
		{
			Korong* k = new Korong(*(this->korongstack[this->korongstack.size() - 1]));
			this->korongstack.erase(this->korongstack.end() - 1);
			std::cout << "Korong kiveve a " << this->nev << " nevu rudrol!" << std::endl;
			return k;
		}
		else
		{
			std::cout << "Nincs korong az oszlopon!" << std::endl;
			return nullptr;
		}
	}

};

