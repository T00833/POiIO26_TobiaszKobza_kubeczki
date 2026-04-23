#pragma once
#include <iostream>
#include <vector>

#include "TSubstance.h"

class TCup
{   std::string name;
    double capacity;
    std::vector<TSubstance> substances;
    std::vector<double> volumes;

public:
    TCup(std::string name, double capacity);
    void add(TSubstance substance, double volume_in_ml);
    void add(std::string name, double volume_in_ml);
    void decant(TCup& cup2, double amount, std::string type);
    void decant(TCup& cup2, double amount, std::string type, std::string substance);
    void show();
    void calc_target_coe(double target, std::string type, std::string name);
    std::string info(int _id);

private:
    int get_substance_id(std::string name,std::vector<TSubstance> sub);
    void print_volume_coe();
    void print_mass_coe();
};

extern std::vector<TCup> cups;
extern std::vector<TCup*> cups_pnt;