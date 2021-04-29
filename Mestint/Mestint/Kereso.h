#pragma once
#include <iostream>
#include <vector>
#include "Hanoi.h"
#include "Allapot.h"
#include "Oprt.h"
#include "Melysegi.h"

class Kereso
{
public:
	std::vector<Allapot> utvonal;
	std::vector<Oprt> operatorok;


public:
	Kereso()
	{
		OperatorokGeneralasa();
	}
	~Kereso() {}

private:
	void OperatorokGeneralasa()
	{
		for (int i = 0; i < Allapot::korongszam; i++)
		{
			for (int j = 0; j < Allapot::oszlopok.size(); j++)
			{
				Oprt ujOperator(i, Allapot::oszlopok[j]);
				operatorok.push_back(ujOperator);
			}
		}
	}
};