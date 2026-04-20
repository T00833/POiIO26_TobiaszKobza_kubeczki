#include <iostream>
#include <algorithm>
#include "TCup.h"
using namespace std;

TCup::TCup(string name, double capacity)
{
    this->name=name;
    this->capacity=capacity;
}

void TCup::add(TSubstance substance, double volume_in_ml)
{       
        unsigned int wyb;
        if(volume_in_ml>capacity)
        {
            cout << "Przekroczyles pojemnosc kubka!\nCzy chcesz nalac do kubka maksymalna objętosc "<< capacity <<"ml?\ntak -> 1\nnie -> 0\n";
            cin >> wyb;
            if(wyb==1) volume_in_ml=capacity;
            else return;
        }

        int count = substances.size();
        bool check=false;

        for(int i=0;i<count;i++)
            {
                if(substance.get_name()==substances[i].get_name())
                    {
                        volumes[i]+=volume_in_ml/1e6;
                        check=true;
                    }
            }

        if(check==0)
            {
                substances.push_back(substance);
                volumes.push_back(volume_in_ml/1e6);
            } 
        
}

void TCup::add(std::string name, double volume_in_ml)
{
    int _id = get_substance_id(name,substancje);
    if(_id >= 0) this->add(substancje[_id],volume_in_ml);
}

void TCup::decant(TCup& cup2, double amount, string type)
{
    unsigned int count = substances.size();
    auto min_vol = min_element(volumes.begin(),volumes.end());
    if(substances.size()==0) cout << "Nie ma co przelać! Kubek jest pusty!\n";
    else if((type!="mass") && (type!="volume")) cout << "Brak metody " << type << " przelania!\n";
    else if(amount<=0) cout << "Podaj liczbe dodatnia (ulamek lub objetosc w ml)!\n";
    else if(amount>*min_vol*1e6) cout << "Przekroczyles objetosc najmniej licznej substancji w kubku!\n"; //problem bo nie ma osobnego przypadku dla masy
    else 
    {
        if(amount<=1) // Przelewanie części kubka (amount to ułamek)
        {
                for(int i=0;i<count;i++)
                {
                    cup2.add(substances[i].get_name(),amount*volumes[i]*1e6);
                    this->add(substances[i].get_name(),-amount*volumes[i]*1e6);
                }
                if(amount==1)
                {    
                this->substances.clear();
                this->volumes.clear();
                }
            cout << amount << " " << name <<" zostala przelane do " << cup2.name << "!\n";
        }
        else
        {
            if(type=="volume") // Przelewanie takiej samej ilosci substancji (amount w ml) do kubka2
            {
                for(int i=0;i<count;i++)
                {
                    cup2.add(substances[i].get_name(),amount);
                    this->add(substances[i].get_name(),-amount);
                    if(volumes[i]==0)
                    {
                        this->substances.erase(substances.begin()+i);
                        this->volumes.erase(volumes.begin()+i);
                    }
                }
                cout << amount << "ml z " << name << " zostalo przelane do " << cup2.name << "!\n";
            }
            else
            {
                for(int i=0;i<count;i++)
                {
                    cup2.add(substances[i].get_name(),amount/substances[i].get_ro()*1000);
                    this->add(substances[i].get_name(),-amount/substances[i].get_ro()*1000);
                    if(volumes[i]==0)
                    {
                        this->substances.erase(substances.begin()+i);
                        this->volumes.erase(volumes.begin()+i);
                    }
                }
                cout << amount << "g z " << name << " zostalo przelane do " << cup2.name << "!\n";
            }
        }
    }
}

void TCup::decant(TCup& cup2, double amount, string type, string substance) 
{
    unsigned int count = substances.size();
    auto min_vol = min_element(volumes.begin(),volumes.end());
    if(substances.size()==0) cout << "Nie ma co przelać! Kubek jest pusty!\n";
    else if((type!="mass") && (type!="volume")) cout << "Brak metody " << type << " przelania!\n";
    else if(amount<=0) cout << "Podaj liczbe dodatnia (ulamek lub objetosc w ml)!\n";
    else if(amount>*min_vol*1e6) cout << "Przekroczyles objetosc najmniej licznej substancji w kubku!\n"; //problem bo nie ma osobnego przypadku dla masy
    else 
    {   
        int id=get_substance_id(substance,substances);
        if(amount<=1) // Przelewanie części kubka (amount to ułamek)
        {
                    cup2.add(substance,amount*volumes[id]*1e6);
                    this->add(substance,-amount*volumes[id]*1e6);
                if(amount==1)
                {    
                this->substances.clear();
                this->volumes.clear();
                }
            cout << amount << " " << name <<" zostala przelane do " << cup2.name << "!\n";
        }
        else
        {
            if(type=="volume") // Przelewanie takiej samej ilosci substancji (amount w ml) do kubka2
            {
                    cup2.add(substance,amount);
                    this->add(substance,-amount);
                    if(volumes[id]==0)
                    {
                        this->substances.erase(substances.begin()+id);
                        this->volumes.erase(volumes.begin()+id);
                    }
                cout << amount << "ml z " << name << " zostalo przelane do " << cup2.name << "!\n";
            }
            else
            {
                    cup2.add(substance,amount/substances[id].get_ro()*1000);
                    this->add(substance,-amount/substances[id].get_ro()*1000);
                    if(volumes[id]==0)
                    {
                        this->substances.erase(substances.begin()+id);
                        this->volumes.erase(volumes.begin()+id);
                    }
                cout << amount << "g z " << name << " zostalo przelane do " << cup2.name << "!\n";
            }
        }
    }
}

int TCup::get_substance_id(std::string name,std::vector<TSubstance> sub)
{
    int count = sub.size();
    int _id = -1;
    bool run = true;

    while(run)
    {
        _id += 1;
        string sub_name = sub[_id].get_name();

        if(sub_name == name) run = false;

        if((_id + 1 == count) && (run == true))
        {
            cout << "Nie znaleziono plynu o podanej nazwie: \"" << name << "\"!\n";
            run = false;
            _id = -1;
        }
    }

    return _id;
}

void TCup::show()
{   
    if(substances.size()==0) cout << "Kubek jest pusty!\n";
    else 
    {
    int count = substances.size();
    cout << "Substances in "<< name <<":\n";
    for (int i=0; i < count; i++)
    {
        double mass = substances[i].get_ro() * volumes[i]*1000; // grams
        cout << substances[i].get_name()
            << "; volume: " << volumes[i] * 1e6 << " ml"
            << "; mass: " << mass << " g" << endl;
    }
    cout << endl;
    print_volume_coe();
    print_mass_coe();
    cout << endl;
    }
}

void TCup::calc_target_coe(double target, std::string type, std::string name)
{
    if(substances.size()==0) cout << "Kubek jest pusty!\n";
        else if((type!="mass") && (type!="volume")) cout << "Brak metody " << type << " coe!\n";
        else
        {

        double sum_vol=0;
        double sum_mass, mass_coe;
        double vol_coe;
        int id;
        int wyb;

            for(int i=0; i < substances.size(); i++)
            {
                if(type=="mass") sum_mass += substances[i].get_ro() * volumes[i]*1000; // grams;
                sum_vol += volumes[i];
                if(name==substances[i].get_name()) id=i;
            }

                if(type=="mass") 
                {
                    mass_coe = (substances[id].get_ro() * volumes[id]*1000)/sum_mass;

                    double t_mass_g = target*((sum_mass - substances[id].get_ro() * volumes[id]*1000))/(1-target)-substances[id].get_ro() * volumes[id]*1000;
                    cout << "Aktualne mass coe: " << mass_coe*100 << "%\n";
                    cout << "Porzadane mass coe: " << target*100 << "%\n";
                    
                    if(t_mass_g>0) 
                    {
                        cout << "Trzeba dolac " << t_mass_g <<"g " << substances[id].get_name() << endl;
                        cout << "Czy chcesz dolac " << t_mass_g << "g :\ntak -> 1\nnie -> 0\n";
                    }
                    else
                    {
                        cout << "Trzeba odlac " << -t_mass_g <<"g " << substances[id].get_name() << endl;
                        cout << "Czy chcesz odlac " << -t_mass_g << "g :\ntak -> 1\nnie -> 0\n";
                    }

                    cin >> wyb;
                    if(wyb==1) add(name,(t_mass_g/(1e3*substances[id].get_ro()))*1e6);
                }
                else
                {
                    vol_coe = volumes[id]/sum_vol;

                    double t_vol_ml = target*((sum_vol-volumes[id])*1e6)/(1-target)-volumes[id]*1e6;

                    cout << "Aktualne volume coe: " << vol_coe*100 << "%\n";
                    cout << "Porzadane volume coe: " << target*100 << "%\n";

                    if(t_vol_ml>0) 
                    {
                        cout << "Trzeba dolac " << t_vol_ml <<"ml " << substances[id].get_name() << endl;
                        cout << "Czy chcesz dolac " << t_vol_ml << "ml :\ntak -> 1\nnie -> 0\n";
                    }
                    else
                    {
                        cout << "Trzeba odlac " << -t_vol_ml <<"ml " << substances[id].get_name() << endl;
                        cout << "Czy chcesz odlac " << -t_vol_ml << "ml :\ntak -> 1\nnie -> 0\n";
                    }

                    cin >> wyb;
                    if(wyb==1) add(name,t_vol_ml);
                }
        }
}

void TCup::print_volume_coe()
{
    double sum_vol=0;
    double vol_coe=0;

    for(int i=0; i < substances.size(); i++)
    {
        sum_vol += volumes[i];
    }

    cout << "Volume coe: ";

    for(int i=0; i < substances.size(); i++)
    {
        vol_coe = (volumes[i]/sum_vol)*100;
        cout << vol_coe << "% - ";
    }

    cout << endl;
}

void TCup::print_mass_coe()
{
    double sum_mass=0;
    double mass_coe=0;

    for(int i=0; i < substances.size(); i++)
    {
        sum_mass += substances[i].get_ro() * volumes[i]*1000; // grams;
    }

    cout << "Mass coe: ";

    for(int i=0; i < substances.size(); i++)
    {
        mass_coe = ((substances[i].get_ro() * volumes[i]*1000)/sum_mass)*100;
        cout << mass_coe << "% - ";
    }

    cout << endl;
}