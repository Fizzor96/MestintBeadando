#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "SFML/Graphics.hpp"
#include "Korong.h"
#include "Globals.h"

class Oszlop
{
public:
	std::string nev;
	sf::Vector2f hely;
	sf::RectangleShape shape;
	std::vector<Korong*> korongstack;

public:
	//Oszlop(std::string name, sf::Vector2f location)
	//{
	//	this->nev = name;
	//	this->hely = location;
	//	this->shape.setSize(sf::Vector2f(10.f, 500.f));
	//	this->shape.setFillColor(sf::Color::White);
	//	this->shape.setOutlineColor(sf::Color::Black);
	//	this->shape.setOutlineThickness(1.f);
	//	this->shape.setOrigin(sf::Vector2f(this->shape.getSize().x / 2, this->shape.getSize().y - Korong::height / 2));
	//	this->shape.setPosition(location);
	//}

	Oszlop(std::string name, float xlocation)
	{
		this->nev = name;
		this->shape.setSize(sf::Vector2f(10.f, 500.f));
		this->shape.setFillColor(sf::Color::White);
		this->shape.setOutlineColor(sf::Color::Black);
		this->shape.setOutlineThickness(1.f);
		this->shape.setOrigin(sf::Vector2f(this->shape.getSize().x / 2, this->shape.getSize().y - Korong::height / 2));
		this->shape.setPosition(sf::Vector2f(xlocation, (Global::Height - Korong::height)));
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
			korong->shape.setPosition(this->shape.getPosition().x, (this->korongstack[this->korongstack.size() - 1]->shape.getPosition().y - Korong::height));
		}
		this->korongstack.push_back(korong);
		//std::cout << "Korong berakva a " << this->nev << " nevu rudra!" << std::endl;

	}

	Korong* Kivesz()
	{
		if (this->korongstack.size() > 0)
		{
			Korong* k = new Korong(*(this->korongstack[this->korongstack.size() - 1]));
			this->korongstack.erase(this->korongstack.end() - 1);
			//std::cout << "Korong kiveve a " << this->nev << " nevu rudrol!" << std::endl;
			return k;
		}
		else
		{
			//std::cout << "Nincs korong az oszlopon!" << std::endl;
			return nullptr;
		}
	}

	void Urit()
	{
		this->korongstack.clear();
	}

	void DrawKorongok(sf::RenderWindow& wd)
	{
		if (this->korongstack.size() > 0)
		{
			for (size_t i = 0; i < this->korongstack.size(); i++)
			{
				wd.draw(this->korongstack[i]->shape);
			}
		}
	}

};

