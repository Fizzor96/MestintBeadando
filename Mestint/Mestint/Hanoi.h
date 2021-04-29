#pragma once
#include <iostream>
#include <vector>
#include "Oszlop.h"
#include "Korong.h"

using namespace std;

class Hanoi
{

public:
	vector<Oszlop*> oszlopok;
	unsigned int korongszam;

	char a = 'A';
	char b = 'B';
	char c = 'C';

public:
	Hanoi()
	{
		Init();
		korongszam = GetKorongszam();
		std::cout << "Osszkorongszam = " << korongszam << std::endl;
	}

	~Hanoi() {}

	void Draw(sf::RenderWindow& wd)
	{
		//Oszlopok
		for (size_t i = 0; i < oszlopok.size(); i++)
		{
			wd.draw(oszlopok[i]->shape);
		}
		
		for (size_t i = 0; i < oszlopok.size(); i++)
		{
			for (size_t j = 0; j < oszlopok[i]->korongstack.size(); j++)
			{
				wd.draw(oszlopok[i]->korongstack[j]->shape);
			}
		}
	}

	unsigned int GetKorongszam()
	{
		unsigned int szam = 0;
		for (size_t i = 0; i < oszlopok.size(); i++)
		{
			szam += this->oszlopok[i]->korongstack.size();
		}
		return szam;
	}

	bool Mozgat(char honnan, char hova)
	{
		Oszlop* s = nullptr;
		Oszlop* d = nullptr;
		if (honnan != hova)
		{
			for (size_t i = 0; i < this->oszlopok.size(); i++)
			{
				if (this->oszlopok[i]->nev == honnan)
				{
					s = this->oszlopok[i];
				}
			}

			for (size_t i = 0; i < this->oszlopok.size(); i++)
			{
				if (this->oszlopok[i]->nev == hova && this->oszlopok[i] != nullptr)
				{
					d = this->oszlopok[i];
				}
			}

			if (s != nullptr && d != nullptr)
			{
				if (s->korongstack.size() > 0)
				{
					if (d->korongstack.size() == 0)
					{
						d->Berak(s->Kivesz());
						std::cout << "Korong atrakva: " << s->nev << "-rol " << d->nev << "-re" << std::endl;
						return true;
					}
					else
					{
						if (d->korongstack[d->korongstack.size() - 1]->shape.getSize().x >= s->korongstack[s->korongstack.size() - 1]->shape.getSize().x)
						{
							d->Berak(s->Kivesz());
							std::cout << "Korong atrakva: " << s->nev << "-rol " << d->nev << "-re" << std::endl;
							return true;
						}
						else
						{
							std::cout << "Invalid mozgatas!" << std::endl;
							return false;
						}
					}
				}
				else
				{
					std::cout << "Nincs korong a \'honnan\' rudon!" << std::endl;
					return false;
				}
			}
			else
			{
				std::cout << "A rudak nem lettek megtalalva!" << std::endl;
				return false;
			}
		}
		else
		{
			std::cout << "Ulj le fiam, 1-es!" << std::endl;
			return false;
		}
	}

	void Init()
	{
		//Init oszlopok
		this->oszlopok.push_back(new Oszlop('A', sf::Vector2f(150.f, 500.f)));
		this->oszlopok.push_back(new Oszlop('B', sf::Vector2f(400.f, 500.f)));
		this->oszlopok.push_back(new Oszlop('C', sf::Vector2f(650.f, 500.f)));

		// Int korongok
		this->oszlopok[0]->Berak(new Korong(sf::Color::Green, 200.f));
		this->oszlopok[0]->Berak(new Korong(sf::Color::Red, 180.f));
		this->oszlopok[0]->Berak(new Korong(sf::Color::Green, 160.f));
		this->oszlopok[0]->Berak(new Korong(sf::Color::Red, 140.f));
		this->oszlopok[0]->Berak(new Korong(sf::Color::Green, 120.f));
		this->oszlopok[0]->Berak(new Korong(sf::Color::Red, 100.f));
		this->oszlopok[0]->Berak(new Korong(sf::Color::Green, 80.f));
		this->oszlopok[0]->Berak(new Korong(sf::Color::Red, 60.f));

		this->oszlopok[1]->Berak(new Korong(sf::Color::Red, 200.f));
		this->oszlopok[1]->Berak(new Korong(sf::Color::Green, 180.f));
		this->oszlopok[1]->Berak(new Korong(sf::Color::Red, 160.f));
		this->oszlopok[1]->Berak(new Korong(sf::Color::Green, 140.f));
		this->oszlopok[1]->Berak(new Korong(sf::Color::Red, 120.f));
		this->oszlopok[1]->Berak(new Korong(sf::Color::Green, 100.f));
		this->oszlopok[1]->Berak(new Korong(sf::Color::Red, 80.f));
		this->oszlopok[1]->Berak(new Korong(sf::Color::Green, 60.f));
	}

	void Init2()
	{
		this->oszlopok.push_back(new Oszlop('A', sf::Vector2f(150.f, 600.f)));
		this->oszlopok.push_back(new Oszlop('B', sf::Vector2f(400.f, 600.f)));
		this->oszlopok.push_back(new Oszlop('C', sf::Vector2f(650.f, 600.f)));

		this->oszlopok[2]->Berak(new Korong(sf::Color::Green, 200.f));
		this->oszlopok[2]->Berak(new Korong(sf::Color::Red, 200.f));

		this->oszlopok[2]->Berak(new Korong(sf::Color::Green, 180.f));
		this->oszlopok[2]->Berak(new Korong(sf::Color::Red, 180.f));
		
		this->oszlopok[2]->Berak(new Korong(sf::Color::Green, 160.f));
		this->oszlopok[2]->Berak(new Korong(sf::Color::Red, 160.f));

		this->oszlopok[2]->Berak(new Korong(sf::Color::Green, 140.f));
		this->oszlopok[2]->Berak(new Korong(sf::Color::Red, 140.f));

		this->oszlopok[2]->Berak(new Korong(sf::Color::Green, 120.f));
		this->oszlopok[2]->Berak(new Korong(sf::Color::Red, 120.f));

		this->oszlopok[2]->Berak(new Korong(sf::Color::Green, 100.f));
		this->oszlopok[2]->Berak(new Korong(sf::Color::Red, 100.f));
		
		this->oszlopok[2]->Berak(new Korong(sf::Color::Green, 80.f));
		this->oszlopok[2]->Berak(new Korong(sf::Color::Red, 80.f));

		this->oszlopok[2]->Berak(new Korong(sf::Color::Green, 60.f));
		this->oszlopok[2]->Berak(new Korong(sf::Color::Red, 60.f));	
	}
};