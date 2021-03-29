#include "Particule.h"
using namespace std;

Vecteur Particule::get_vitesse() const {
	return vitesse;
}

Vecteur Particule::get_position() const {
	return position;
}

double Particule::get_masse() const {
	return masse;
}

void Particule::set_part (double x1, double x2, double x3, double v1, double v2, double v3) {
	(this->position)= (Vecteur(x1, x2, x3));
	(this->vitesse)=(Vecteur(v1, v2, v3));
}


void Particule::collision (Particule& p2, Vecteur vg, Vecteur v0) {
	vitesse=vg+v0;
	p2.vitesse=(vg-((masse/p2.masse)*v0));
	choc=true;
	p2.choc=true;
} 

void Particule::rebond (int face, double taille) {
	position.rebond(face, taille);				// appelle la méthode rebond de la classe vecteur
	vitesse.rebond(face, 0);
}

void Particule::evolue (double dt) {
	position+=(dt*vitesse);
	choc=false;
} 

Vecteur Particule::vg (const Particule& p2) {
	return ((p2.masse/(masse+p2.masse))*(p2.vitesse)+((masse/(masse+p2.masse))*vitesse));
}

bool Particule::check_choc() const {
	return choc;
}
	


ostream& Particule::affiche(ostream& sortie) const {
	sortie << "pos : " << position << " ; v : " << vitesse << " ; m : " << masse;
	return sortie;
}

ostream& operator<<(ostream& sortie, const Particule& p) {
	return (p.affiche(sortie));
}


