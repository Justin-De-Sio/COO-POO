#include <iostream>

using namespace std;

class Abonne
{
protected:
    unsigned myId;
    string myNom;
    string myPrenom;

public:
    Abonne(unsigned id, string nom, string prenom) : myId(id), myNom(nom), myPrenom(prenom){};

    void display();
    int getAbonne() { return myId; };
    void setAbonne(unsigned id, string nom, string prenom);
};

class AbonneFibre : public Abonne
{
private:
    int tarif;

public:
    AbonneFibre(unsigned id, string nom, string prenom, int tarif) : Abonne(id, nom, prenom), tarif(tarif){};
};

class AbonneADSL : public Abonne
{
private:
    int trame;
public:
    AbonneADSL(unsigned id, string nom, string prenom, int trame) : Abonne(id, nom, prenom), trame(trame){};
};

void Abonne::display()
{
    cout << "Abonné n°" << myId << endl;
}

void Abonne::setAbonne(unsigned id, string nom, string prenom)
{
    myId = id;
    myNom = nom;
    myPrenom = prenom;
};

int main()
{
    AbonneFibre a1(500,"De Sio", "Justin", 10);
    cout << a1.getAbonne();
    return 0;
}
