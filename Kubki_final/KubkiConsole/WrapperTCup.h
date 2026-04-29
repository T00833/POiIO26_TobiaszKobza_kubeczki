#pragma once
#include "TCup.h"
class WrapperTCup
{
	TCup* cup = new TCup("Cup",250);
public:
	~WrapperTCup();
	void add(TSubstance substance, double volume_in_ml);
	void add(std::string name, double volume_in_ml);
	void show();
private:
	void print_add_status(std::string name, int status, double volume);
};

