#ifndef PRJ_VECTEUR_H
#define PRJ_VECTEUR_H
#include <iostream>

//definition d'une classe vecteur
class Vecteur{
public:
//constructeurs
Vecteur():x_(0.0),y_(0.0), z_(0.0)  {} //constructeur par defaut
Vecteur(double x, double y, double z): x_(x), y_(y), z_(z) {} //constructeur d'initialisation avec des valeur entr��e pas l'utlisateur
//trois methodes qui retournent les coordonnees du vecteur
double  get_x() const;
double  get_y() const;
double  get_z() const;
//operateurs
bool operator==(Vecteur const& v) const; //operateurs de comparaison
bool operator!=(Vecteur const& v) const;
Vecteur& operator+=(Vecteur const& v); //operateur pour l'ajout d'un vecteur a lui meme
Vecteur& operator-=(Vecteur const& v); //operteur de soustraction d'un vecteur a lui meme
Vecteur& operator*=(double const& a); //operateur de multiplication d'un vecteur par un scalaire
Vecteur& operator^=(Vecteur const& v); //operateur de produit vectoriel de deux vecteurs
//autres methodes
std::ostream& afficher(std::ostream& sortie) const; //fonction utilisee pour la surchage de l'operateur d'affichage
double norme() const; //renvoie la norme du vecteur
double norme_carre() const; //renvoie le carre de la norme
void rebond (int face, double taille);  // fait une symmetrie du vecteur pris par rapport a une face de l'enceinte placee a taille de l'origine
double somme() const;  // renvoie la somme de la valeur absolue des composantes 

private:
double x_;
double y_;
double z_;
};
//prototype de fonction
std::ostream& operator<<(std::ostream& sortie, Vecteur const& v); //operateur d'affichage
const Vecteur operator^(Vecteur, Vecteur const&); //operateur produit vectoriel
const double operator*(Vecteur, Vecteur const&); //operateur produit scalaire
const Vecteur operator*(double const& a, Vecteur v); //operateurs pour la multiplication par scalaire
const Vecteur operator*(Vecteur v, double const& a);
const Vecteur operator+(Vecteur un, const Vecteur& autre);   //operateur pour l'addition de deux vecteurs
const Vecteur operator-(Vecteur un, const Vecteur& autre);   //operateur pour la soustraction de deux vecteurs
const Vecteur operator-(Vecteur un); //operateur pour l'oppose d'un vecteur

#endif // PRJ_VECTEUR_H



