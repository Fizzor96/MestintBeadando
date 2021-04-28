#pragma once
#include <iostream>
#include <vector>
#include "Oszlop.h"
#include "Korong.h"

using namespace std;

class Hanoi
{

public:
	vector<Oszlop> oszlopok;
	vector<Korong> korongok;

public:
	Hanoi()
	{
		this->oszlopok.push_back(Oszlop('A', sf::Vector2f(150.f, 500.f)));
		this->oszlopok.push_back(Oszlop('B', sf::Vector2f(400.f, 500.f)));
		this->oszlopok.push_back(Oszlop('C', sf::Vector2f(650.f, 500.f)));

		this->oszlopok[0].Berak(new Korong(sf::Color::Green, 200.f));
		this->oszlopok[0].Berak(new Korong(sf::Color::Red, 180.f));
		this->oszlopok[0].Berak(new Korong(sf::Color::Green, 160.f));
		this->oszlopok[0].Berak(new Korong(sf::Color::Red, 140.f));
		this->oszlopok[0].Berak(new Korong(sf::Color::Green, 120.f));
		this->oszlopok[0].Berak(new Korong(sf::Color::Red, 100.f));
		this->oszlopok[0].Berak(new Korong(sf::Color::Green, 80.f));
		this->oszlopok[0].Berak(new Korong(sf::Color::Red, 60.f));

		this->oszlopok[1].Berak(new Korong(sf::Color::Red, 200.f));
		this->oszlopok[1].Berak(new Korong(sf::Color::Green, 180.f));
		this->oszlopok[1].Berak(new Korong(sf::Color::Red, 160.f));
		this->oszlopok[1].Berak(new Korong(sf::Color::Green, 140.f));
		this->oszlopok[1].Berak(new Korong(sf::Color::Red, 120.f));
		this->oszlopok[1].Berak(new Korong(sf::Color::Green, 100.f));
		this->oszlopok[1].Berak(new Korong(sf::Color::Red, 80.f));
		this->oszlopok[1].Berak(new Korong(sf::Color::Green, 60.f));

		this->oszlopok[2].Berak(this->oszlopok[1].Kivesz());

		Mozgat('A', 'C');
		Mozgat('A', 'B');
		Mozgat('C', 'A');
		Mozgat('B', 'A');
		
	}

	~Hanoi() {}

	void Draw(sf::RenderWindow& wd)
	{
		//Oszlopok
		for (size_t i = 0; i < oszlopok.size(); i++)
		{
			wd.draw(oszlopok[i].shape);
		}
		
		for (size_t i = 0; i < oszlopok.size(); i++)
		{
			for (size_t j = 0; j < oszlopok[i].korongstack.size(); j++)
			{
				wd.draw(oszlopok[i].korongstack[j]->shape);
			}
		}
	}

	void Mozgat(char honnan, char hova)
	{
		if (honnan != hova)
		{
			Oszlop& s;
			Oszlop& d;

			for (size_t i = 0; i < this->oszlopok.size(); i++)
			{
				if (this->oszlopok[i].nev == honnan)
				{
					s = this->oszlopok[i];
				}
				else
				{
					std::cout << "Nincs ilyen nevu oszlop!" << std::endl;
				}
			}

			for (size_t i = 0; i < this->oszlopok.size(); i++)
			{
				if (this->oszlopok[i].nev == hova)
				{
					d = this->oszlopok[i];
				}
				else
				{
					std::cout << "Nincs ilyen nevu oszlop!" << std::endl;
				}
			}

			if (s.korongstack[s.korongstack.size() - 1]->shape.getTextureRect().width <= d.korongstack[d.korongstack.size() - 1]->shape.getTextureRect().width)
			{
				d.Berak(s.Kivesz());
			}
			
		}
		else
		{
			std::cout << "Ulj le fiam, 1-es!" << std::endl;
		}
	}
};