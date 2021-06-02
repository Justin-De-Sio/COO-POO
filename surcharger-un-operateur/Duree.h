#ifndef DUREE_H
#define DUREE_H
#include <iostream>
class Duree
{
public:
   Duree(int heures = 0, int minutes = 0, int secondes = 0); //constructeur durée
   void display(void);                                       // Affiche la durée
   bool estEgal(Duree const &b) const;                       //revoit vrai si b en paramètre vaut a
   bool estPlusPetitQue(Duree const &b) const;
   Duree &operator+=(const Duree &a);
   Duree &operator+=(int secondes);
   void afficher(std::ostream &flux) const;

private:
   int m_heures;
   int m_minutes;
   int m_secondes;
};

bool operator==(Duree const &a, Duree const &b);
bool operator!=(Duree const &a, Duree const &b);
bool operator<(Duree const &a, Duree const &b);
bool operator>(Duree const &a, Duree const &b);
bool operator<=(Duree const &a, Duree const &b);
bool operator>=(Duree const &a, Duree const &b);
Duree operator+(Duree const &a, Duree const &b);
Duree operator+(Duree const &duree, int secondes);
std::ostream &operator<<( std::ostream &flux, Duree const& duree);

#endif
