#include "Duree.h"
#include <iostream>
#include <iomanip>
using namespace nsUtil;
using namespace std;

#define DUREE nsUtil::Duree

DUREE::Duree(const ULL duree ) :  myDuree(duree)
{
    normaliser();
}

DUREE::~Duree()
{
        cout << "duree détruite : ";
        display ();
        cout << endl;
}

void DUREE::display(void) const{
    cout << '['
         << setw (10) << myDays    << ':'
         << setfill ('0')
         << setw (2)  << myHours   << ':'
         << setw (2)  << myMinutes << ':'
         << setw (2)  << mySeconds << ':'
         << setfill (' ')
         << ']';
}

void DUREE::normaliser(void){

    myDays = myDuree / 86400;
    myHours = (myDuree % 86400) / 3600;
    myMinutes = (myDuree % 3600) / 60;
    mySeconds = myDuree % 60;

}

ULL DUREE::getDuree() const{
    return myDuree;
}

void DUREE::incr(ULL delta )
{
    myDuree += delta;
    normaliser();
}

void Duree::decr(ULL delta){
    myDuree -= delta;
    normaliser();

}
