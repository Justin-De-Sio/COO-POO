#include <iostream>
#include <vector>
using namespace std;
class Pneu
{
private:
   std::string marque;
   std::string type;

public:
   Pneu(const std::string &marque, const std::string &type) : marque(marque), type(type){};
}; // class Pneu

class Roue
{
private:
   int diametre;
   int largeur;
   Pneu *pneu;

public:
   Roue(int diametre, int largeur) : diametre(diametre), largeur(largeur){};
}; // class Roue

class Chassis
{
private:
   int annee;

public:
   Chassis(int annee) : annee(annee){};
}; // class Chassis

class Voiture
{
private:
   std::string plaque;
   std::string marque;

   std::vector<Roue *> roues;
   Chassis chassis;

public:
   Voiture(std::string plaque, std::string marque, Chassis chassis) : plaque(plaque), marque(marque), chassis(chassis){};

   void afficher();

   void ajouterRoue(Roue roue);
   void supprimerRoue(Roue roue);
}; // class Voiture

class Conducteur
{
private:
   std::string nom;
   std::string prenom;

   std::vector<Voiture *> voitures;

public:
   Conducteur(std::string nom, std::string prenom) : nom(nom), prenom(prenom){};

   void afficherVoitures();
}; // class Conducteur

void Voiture::afficher()
{
   std::cout << "Voiture " << this->plaque << std::endl;
} // void Voiture::afficher()

void Voiture::ajouterRoue(Roue roue)
{
   roues.insert(roues.begin(), &roue);
} // void Voiture::ajouterRoue(Roue roue)

void Voiture::supprimerRoue(Roue roue)
{
   roues.erase(find(roues.begin(), roues.end(), &roue));
} // void Voiture::supprimerRoue(Roue roue)

void Conducteur::afficherVoitures()
{
   for (vector<Voiture *>::iterator it = voitures.begin(); it < voitures.end(); ++it)
      (*it)->afficher();
} // void Conducteur::afficherVoitures()


int main()
{
   /* code */
   return 0;
}
