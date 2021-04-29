#pragma once
#include <iostream>
#include <vector>
#include "Hanoi.h"
#include "Allapot.h"
#include "Operator.h"

class Kereso
{
public:
	std::vector<Allapot> utvonal;
	std::vector<Operator> operatorok;


public:
	Kereso()
	{
		OperatorokGeneralasa();
	}
	~Kereso() {}

private:
	void OperatorokGeneralasa()
	{

	}
};