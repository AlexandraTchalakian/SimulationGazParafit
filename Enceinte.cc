#include <iostream>
#include "Enceinte.h"
using namespace std;

double Enceinte::get_hauteur() const {
	return hauteur_;
}
		
double Enceinte::get_largeur() const {
	return largeur_;
}

double Enceinte::get_profondeur() const {
	return profondeur_;
}
void Enceinte::dessine() const{
	
glBegin(GL_LINE_STRIP);
glVertex3d(0.0,0.0,0.0);
glVertex3d(0.0,largeur_,0.0);
glVertex3d(hauteur_,largeur_,0.0);
glVertex3d(hauteur_,0.0,0.0);
glVertex3d(0.0,0.0,0.0);
glVertex3d(0.0,0.0,profondeur_);
glVertex3d(0.0,largeur_,profondeur_);
glVertex3d(hauteur_,largeur_,profondeur_);

glVertex3d(hauteur_,0.0,profondeur_);
glVertex3d(0.0,0.0,profondeur_);
glEnd();

glBegin(GL_LINES);
glVertex3d(0.0,largeur_,0.0);
glVertex3d(0.0,largeur_,profondeur_);


glVertex3d(hauteur_,largeur_,0.0);
glVertex3d(hauteur_,largeur_,profondeur_);

glVertex3d(hauteur_,0.0,0.0);
glVertex3d(hauteur_,0.0,profondeur_);
glEnd();
}

ostream& Enceinte::affiche(ostream& sortie) const{
	sortie<<"enceinte: "<<hauteur_<<" "<<largeur_<<" "<<profondeur_;
	return sortie;
}

ostream& operator<<(ostream& sortie, Enceinte const& e){
	e.affiche(sortie);
	return sortie;
}
