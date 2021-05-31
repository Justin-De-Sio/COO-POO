#include <iostream>
#include <iomanip>
using namespace std;
typedef unsigned short US;
typedef unsigned long UL;

class Duree
{

public:
    Duree(const UL duree);
    void display(void) const;
    UL getDuree(void) const;
    void incr(const UL delta = UL(0));
    void decr(const UL delta = UL(0));

private:
    void normaliser(void);

    UL myDuree;
    US mySeconds;
    US myMinutes;
    US myHours;
    UL myDays;
};

Duree::Duree(const UL duree) : myDuree(duree)
{
    normaliser();
}

void Duree::display(void) const
{
    cout << myDays << "j " << setw(4) << myHours << "h " << myMinutes << "min " << setw(4) << mySeconds << "sec" << endl;
}

void Duree::normaliser(void)
{

    myDays = myDuree / 86400;
    myHours = (myDuree % 86400) / 3600;
    myMinutes = (myDuree % 3600) / 60;
    mySeconds = myDuree % 60;
}

UL Duree::getDuree() const
{
    return myDuree;
}

void Duree::incr(UL delta)
{
    myDuree += delta;
    normaliser();
}

void Duree::decr(UL delta)
{
    myDuree -= (delta > myDuree) ? myDuree : delta;
    normaliser();
}

void testDureeDeBase()
{

    UL oneDuree;
    for (cin >> oneDuree; !cin.eof(); cin >> oneDuree)
    {
        Duree duree(oneDuree);
        duree.display();
    }

    //    Duree d1 (0);
    //    d1.incr (1);
    //    cout << "Nbre sec. " << setw (6) << d1.getDuree ()
    //         << ", soit : ";
    //    d1.display ();
    //    cout << '\n';

    //    d1.decr (1);
    //    cout << "Nbre sec. " << setw (6) << d1.getDuree ()
    //         << ", soit : ";
    //    d1.display ();
    //    cout << '\n';

    //    d1.incr (3662);
    //    cout << "Nbre sec. " << setw (6) << d1.getDuree ()
    //         << ", soit : ";
    //    d1.display ();
    //    cout << '\n';

    //    d1.decr (10000);
    //    cout << "Nbre sec. " << setw (6) << d1.getDuree ()
    //         << ", soit : ";
    //    d1.display ();
    //    cout << '\n';
}

int main()
{
    testDureeDeBase();
    return 0;
}
