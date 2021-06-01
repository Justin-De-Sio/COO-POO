#include <iostream>

using namespace std;

class Abonne
{
public:
    Abonne(unsigned id, string nom, string prenom) : myId(id), myNom(nom), myPrenom(prenom){};

    void display();
    int getAbonne() { return this->myId; };
    void setAbonne(unsigned id, string nom, string prenom) { myId = id, myNom = nom, myPrenom = prenom; };

protected:
    unsigned myId;
    string myNom;
    string myPrenom;
};

class AbonneFibre : public Abonne
{
public:
    AbonneFibre(unsigned id, string nom, string prenom) : Abonne(id, nom, prenom){};
};

class AbonneADSL : public Abonne
{
public:
    AbonneADSL(unsigned id, string nom, string prenom) : Abonne(id, nom, prenom){};
};

void Abonne::display()
{
    cout << "Abonné n°" << this->myId << endl;
}

int main()
{
    AbonneFibre a1(506, "Justin", "De Sio");
    a1.setAbonne(10, "Justin", "De Sio");
    cout << a1.getAbonne();

    return 0;
}
