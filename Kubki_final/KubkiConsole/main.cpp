#include <iostream>
#include <vector>
#include "TSubstance.h"
#include "TCup.h"
using namespace std;

int main()
{
    TCup kubek1("kubek1",250);
    TCup kubek2("kubek2",350.43);
    kubek1.add(substancje[0], 300);
    //kubek1.show();
    kubek1.add(substancje[1], 50);
    kubek1.add("woda",30);
    kubek1.add("kwas", 1);
    kubek1.add(substancje[0], 100);
    //kubek1.show();
    //kubek1.calc_target_coe(0.5,"volume","woda");
    //kubek1.show();
    //kubek1.decant(kubek2,1,"volume");
    //kubek2.show();
    //kubek1.show();
}