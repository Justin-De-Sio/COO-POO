#include "Duree.h"
#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;
using namespace nsUtil;

void testDuree()
{

    vector<Duree> vDuree;

    UL oneDuree;
    for (cin >> oneDuree; !cin.eof(); cin >> oneDuree)
    {
        vDuree.push_back(oneDuree);
    }
    for (const Duree &duree : vDuree)
    {
        duree.display();
        cout << endl;
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
    testDuree();
    return 0;
}
