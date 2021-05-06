#pragma once

#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
#include "Oszlop.h"
#include "Korong.h"
#include "Melysegi.h"
#include "Allapot.h"
#include "Backtrack.h"
#include "ProbaHibaRandom.h"

using namespace std::chrono_literals;

class Hanoi
{

public:
	std::chrono::milliseconds delay = std::chrono::milliseconds(5);

	std::vector<Oszlop*> oszlopok;
	std::vector<Korong*> korongok;
	unsigned int korongszam;
	Melysegi m;
	Backtrack back;
	ProbaHiba ph;
	std::vector<std::vector<std::string>> states;

	std::string a = "A";
	std::string b = "B";
	std::string c = "C";

	const sf::Color c1 = sf::Color::Green;
	const sf::Color c2 = sf::Color::Blue;

public:
	Hanoi()
	{
		//Init oszlopok
		this->oszlopok.push_back(new Oszlop("A", 150.f));
		this->oszlopok.push_back(new Oszlop("B", 500.f));
		this->oszlopok.push_back(new Oszlop("C", 850.f));

		Default();
	}

	~Hanoi() {}

	void DepthSearch()
	{
		m.Start();

		this->states.empty();
		for (size_t i = 0; i < m.utvonal.size(); i++)
		{
			this->states.push_back(m.utvonal[i].korongok);
		}

		m.utvonal.clear();
		m.operatorok.clear();

		InitKorongok(states);

		std::this_thread::sleep_for(3000ms);
		Reset();
		Default();
	}

	void BackTrack()
	{
		back.Start();

		this->states.empty();
		for (size_t i = 0; i < back.utvonal.size(); i++)
		{
			this->states.push_back(back.utvonal[i].korongok);
		}

		back.utvonal.clear();
		back.operatorok.clear();

		InitKorongok(states);

		std::this_thread::sleep_for(3000ms);
		Reset();
		Default();
	}

	void ProbaHiba()
	{
		ph.Start();

		this->states.empty();
		for (size_t i = 0; i < ph.utvonal.size(); i++)
		{
			this->states.push_back(ph.utvonal[i].korongok);
		}

		ph.utvonal.clear();
		ph.operatorok.clear();

		InitKorongok(states);

		std::this_thread::sleep_for(3000ms);
		Reset();
		Default();
	}

	void InitKorongok(std::vector<std::vector<std::string>> utvonal)
	{
		for (size_t i = 0; i < utvonal.size(); i++)
		{
			Reset();
			for (size_t j = 0; j < utvonal[i].size(); j++)
			{
				if (utvonal[i][j] == "A")
				{
					this->oszlopok[0]->Berak(new Korong());
				}
				if (utvonal[i][j] == "B")
				{
					this->oszlopok[1]->Berak(new Korong());
				}
				if (utvonal[i][j] == "C")
				{
					this->oszlopok[2]->Berak(new Korong());
				}
			}
			std::this_thread::sleep_for(delay);
		}
	}

	void Reset()
	{
		for (size_t i = 0; i < this->oszlopok.size(); i++)
		{
			this->oszlopok[i]->korongstack.clear();
		}
		Korong::refcounter = 0;
		//Init();
	}

	void Default()
	{
		this->oszlopok[0]->Berak(new Korong());
		this->oszlopok[0]->Berak(new Korong());
		this->oszlopok[0]->Berak(new Korong());
		this->oszlopok[1]->Berak(new Korong());
		this->oszlopok[1]->Berak(new Korong());
		this->oszlopok[1]->Berak(new Korong());
	}

	void Draw(sf::RenderWindow& wd)
	{
		//Oszlopok drawCall
		for (size_t i = 0; i < oszlopok.size(); i++)
		{
			wd.draw(oszlopok[i]->shape);
		}
		
		//Korongok drawCall
		for (size_t i = 0; i < this->oszlopok.size(); i++)
		{
			this->oszlopok[i]->DrawKorongok(wd);
		}
	}

	/*
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
						//std::cout << "Korong atrakva: " << s->nev << "-rol " << d->nev << "-re" << std::endl;
						return true;
					}
					else
					{
						if (d->korongstack[d->korongstack.size() - 1]->shape.getSize().x >= s->korongstack[s->korongstack.size() - 1]->shape.getSize().x)
						{
							d->Berak(s->Kivesz());
							//std::cout << "Korong atrakva: " << s->nev << "-rol " << d->nev << "-re" << std::endl;
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
	*/

	/*
	void Init()
	{
		//Int korongok
		this->oszlopok[0]->Berak(new Korong(c1, 200.f));
		this->oszlopok[0]->Berak(new Korong(c2, 180.f));
		this->oszlopok[0]->Berak(new Korong(c1, 160.f));
		this->oszlopok[0]->Berak(new Korong(c2, 140.f));
		this->oszlopok[0]->Berak(new Korong(c1, 120.f));
		this->oszlopok[0]->Berak(new Korong(c2, 100.f));
		this->oszlopok[0]->Berak(new Korong(c1, 80.f));
		this->oszlopok[0]->Berak(new Korong(c2, 60.f));

		this->oszlopok[1]->Berak(new Korong(c2, 200.f));
		this->oszlopok[1]->Berak(new Korong(c1, 180.f));
		this->oszlopok[1]->Berak(new Korong(c2, 160.f));
		this->oszlopok[1]->Berak(new Korong(c2, 140.f));
		this->oszlopok[1]->Berak(new Korong(c1, 120.f));
		this->oszlopok[1]->Berak(new Korong(c2, 100.f));
		this->oszlopok[1]->Berak(new Korong(c1, 80.f));
		this->oszlopok[1]->Berak(new Korong(c2, 60.f));
	}
	*/


};