#include "Duree.h"
#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;
using namespace nsUtil;

namespace  {

    void fct (Duree durDur)
        {
            cout << "Affichage de durDur : ";
            durDur.display() ;
            cout << '\n';

        } // Fct()

    void testDuree(){


        vector<Duree> vDuree;

        ULL oneDuree;
        for (cin >> oneDuree; ! cin.eof (); cin >> oneDuree)
            {
                vDuree.push_back(oneDuree);
            }
        for(const Duree & duree : vDuree){
            cout << "duree : " ;
            duree.display ();
            cout << endl;
        }

        cout << endl << setfill('-') << setw(50) << '-' << setfill(' ') << endl << endl ;

        Duree d1 (0);
        d1.incr (1);
        cout << "Nbre sec. " << setw (6) << d1.getDuree ()
             << ", soit : ";
        d1.display ();
        cout << '\n';

        d1.decr (1);
        cout << "Nbre sec. " << setw (6) << d1.getDuree ()
             << ", soit : ";
        d1.display ();
        cout << '\n';

        d1.incr (3662);
        cout << "Nbre sec. " << setw (6) << d1.getDuree ()
             << ", soit : ";
        d1.display ();
        cout << '\n';

        d1.decr (10000);
        cout << "Nbre sec. " << setw (6) << d1.getDuree ()
             << ", soit : ";
        d1.display ();
        cout << '\n';
    }

}

int main()
{
    Duree m1 = 59845774847451;
    fct(m1);
    testDuree();
    return 0;
}
