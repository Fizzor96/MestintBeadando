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

	const sf::Color c1 = sf::Color::Green;
	const sf::Color c2 = sf::Color::Blue;

public:
	Hanoi()
	{
		//Init oszlopok
		this->oszlopok.push_back(new Oszlop('A', 150.f));
		this->oszlopok.push_back(new Oszlop('B', 500.f));
		this->oszlopok.push_back(new Oszlop('C', 850.f));

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
		
		for (size_t i = 0; i < this->oszlopok.size(); i++)
		{
			this->oszlopok[i]->DrawKorongok(wd);
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
							//std::cout << "Invalid mozgatas!" << std::endl;
							return false;
						}
					}
				}
				else
				{
					//std::cout << "Nincs korong a \'honnan\' rudon!" << std::endl;
					return false;
				}
			}
			else
			{
				//std::cout << "A rudak nem lettek megtalalva!" << std::endl;
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
		// Int korongok
		this->oszlopok[0]->Berak(new Korong(c1, 200.f));
		this->oszlopok[0]->Berak(new Korong(c2, 180.f));
		this->oszlopok[0]->Berak(new Korong(c1, 160.f));
		//this->oszlopok[0]->Berak(new Korong(c2, 140.f));
		//this->oszlopok[0]->Berak(new Korong(c1, 120.f));
		//this->oszlopok[0]->Berak(new Korong(c2, 100.f));
		//this->oszlopok[0]->Berak(new Korong(c1, 80.f));
		//this->oszlopok[0]->Berak(new Korong(c2, 60.f));

		this->oszlopok[1]->Berak(new Korong(c2, 200.f));
		this->oszlopok[1]->Berak(new Korong(c1, 180.f));
		this->oszlopok[1]->Berak(new Korong(c2, 160.f));
		//this->oszlopok[1]->Berak(new Korong(c2, 140.f));
		//this->oszlopok[1]->Berak(new Korong(c1, 120.f));
		//this->oszlopok[1]->Berak(new Korong(c2, 100.f));
		//this->oszlopok[1]->Berak(new Korong(c1, 80.f));
		//this->oszlopok[1]->Berak(new Korong(c2, 60.f));
	}

	void Reset()
	{
		for (size_t i = 0; i < this->oszlopok.size(); i++)
		{
			this->oszlopok[i]->korongstack.clear();
		}
		Init();
	}
};