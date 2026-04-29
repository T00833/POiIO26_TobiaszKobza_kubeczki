#include "WrapperTCup.h"
#include <iostream>
#include <vector>
using namespace std;
WrapperTCup::~WrapperTCup()
{
	delete cup;
	cup = nullptr;
}
void WrapperTCup::add(TSubstance substance, double volume_in_ml)
{
	int status = cup->add(substance, volume_in_ml);
	string name = substance.get_name();
	this->print_add_status(name, status, volume_in_ml);
}

void WrapperTCup::add(std::string name, double volume_in_ml)
{
	int status = cup->add(name, volume_in_ml);
	this->print_add_status(name, status, volume_in_ml);

}
void WrapperTCup::show()
{
	std::vector<TSubstance> substances = cup->get_cup_substances();
	std::vector<double> volumes = cup->get_cup_volumes();
}

void WrapperTCup::print_add_status(string name, int status, double vol)
{
	switch (status)
	{
	case -1:
		cout << "Nieznana substancja: " << name << endl;
		break;
	case 1:
		cout << "Dodano nowa substancje do kubka \"" << name << "\"";
		cout << " w ilosci: " << vol << "ml.\n";
		break;
	case 2:
		cout << "Dolano \"" << name << "\" do kubka";
		cout << " w ilosci: " << vol << "ml.\n";
		break;
	default:
		cout << "Nieznany status funkcji add: " << status << endl;
		break;
	}
}