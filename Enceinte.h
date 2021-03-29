#ifndef PRJ_ENCEINTE_H
#define PRJ_ENCEINTE_H
#include <iostream>
#include <cmath>
#include "Vue_OpenGL.h"

//declaration d'une classe enceinte
class Enceinte{
	public:
		Enceinte(): hauteur_(200.0), largeur_(200.0), profondeur_(200.0) {} //constructeur par defaut
		Enceinte(double hauteur, double largeur, double profondeur)		//constructeur initialisant une enceite avec 3 double	
		:hauteur_(fabs(hauteur)), largeur_(fabs(largeur)), profondeur_(fabs(profondeur)) {}	
		std::ostream& affiche(std::ostream& sortie) const;	//methode permettant la suchage de l'operateur d'affichage
		double get_hauteur() const;
		double get_largeur() const;
		double get_profondeur() const;
		void dessine() const;
	protected:
		double hauteur_;
		double largeur_;
		double profondeur_;	
};

std::ostream& operator<<(std::ostream& sortie, Enceinte const& e);	//surcharge de l'operateur d'affichage

#endif // PRJ_ENCEINTE_H
