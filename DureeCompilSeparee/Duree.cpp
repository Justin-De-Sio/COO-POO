#include "Duree.h"
#include <iostream>
#include <iomanip>
using namespace nsUtil;
using namespace std;

#define DUREE nsUtil::Duree

DUREE::Duree(const UL duree) :  myDuree(duree)
{
    normaliser();
}

void DUREE::display(void) const{
    cout << myDays << "j " << setw(4) << myHours << "h "<< myMinutes << "min " << setw(4) << mySeconds << "sec" << endl;
}

void DUREE::normaliser(void){

    myDays = myDuree / 86400;
    myHours = (myDuree % 86400) / 3600;
    myMinutes = (myDuree % 3600) / 60;
    mySeconds = myDuree % 60;

}

UL DUREE::getDuree() const{
    return myDuree;
}

void DUREE::incr(UL delta)
{
    myDuree += delta;
    normaliser();
}

void Duree::decr(UL delta){
    myDuree -= delta;
    normaliser();

}
