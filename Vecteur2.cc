#include "Vecteur2.h"
#include <cmath>
using namespace std;

	// corps de methodes
	
	double Vecteur::get_x() const{
		return x_;
	}
	double Vecteur::get_y() const{
		return y_;
	}
	double Vecteur::get_z() const{
		return z_;
	}

	bool Vecteur::operator==(Vecteur const& v) const{
		// comparaison des composantes
		if(x_==v.x_ and y_==v.y_ and z_==v.z_){
			return true;
		}else{
			return false;
		}
	}
	
	bool Vecteur:: operator!=(Vecteur const& v) const {
		return (!((*this)==v));
	}
	
	Vecteur& Vecteur::operator +=(Vecteur const& v){
		x_=x_+v.get_x();
		y_=y_+v.get_y();
		z_=z_+v.get_z();
		return *this;
		/*avec cet operateur on modifie les composantes du vecteur appelant la fonction
		 d'ou le pointeur sur celui-ci*/
	}
	Vecteur& Vecteur::operator -=(Vecteur const& v){
		x_=x_-v.get_x();
		y_=y_-v.get_y();
		z_=z_-v.get_z();
		return *this;
		// voir operateur+=
	}
	Vecteur& Vecteur::operator*=(double const& a){
		x_*=a;
		y_*=a;
		z_*=a;
		return *this;
	}
	Vecteur& Vecteur::operator^=(Vecteur const& v){
		double x(x_), y(y_);
		x_=y_*v.z_-z_*v.y_;
		y_=y_*v.x_-x*v.y_;
		z_=x*v.y_-y*v.x_;
		return *this;
	}
	ostream& Vecteur::afficher(ostream& sortie) const{	//sert a la surcharge de l'operateur d'affichage
		sortie <<x_<<" "<<y_<<" "<<z_;
		return sortie;
	}
	double Vecteur::norme() const {
	return sqrt(this->norme_carre()); // appelle la fonction norme au carre de la classe vecteur
	} // et renvoie la racine du resultat

	double Vecteur::norme_carre() const {
	return (x_*x_+y_*y_+z_*z_);
	}
	
	//coprs des fonctions 
	
	
	//definition de l'operateur produit vectoriel
	const Vecteur operator^(Vecteur v1, Vecteur const& v2){
		v1^=v2;
		return v1;	
		//appelle anonyment le construteur avec une donnee transitoire pour que celui si cree un nouveau vecteur
	}
	const double operator*(Vecteur v1, Vecteur const& v2){
		return v1.get_x()*v2.get_x() + v1.get_y()*v2.get_y() + v1.get_z()*v2.get_z();
		// produit scalaire=somme du produit des composantes
	}
	//definition de l'operateur d'affichage
	ostream& operator <<(ostream& sortie, Vecteur const& v){
		v.afficher(sortie);// appel de la methode afficher
		return sortie;
	}
	const Vecteur operator*(double const& a, Vecteur v){
		v*=a;
		return v;
	}
	const Vecteur operator*(Vecteur v, double const& a){
		v*=a;
		return v;
	}
	const Vecteur operator+(Vecteur un, const Vecteur& deux) {
		un+=deux;
		return un;
	}
	
	const Vecteur operator-(Vecteur un, const Vecteur& deux) {
		un-=deux;
		return un;
	}
	
	const Vecteur operator-(Vecteur un) {
		un-=(2*un);
		return un;
	}
	
	void Vecteur::rebond (int face, double taille) {
		if ((face==1) or (face==6)) x_=2*taille-x_;				// determine quelle composante doit etre changee suivant la face rencontree puis fait une 
		else if ((face==2) or (face==5)) y_=2*taille-y_;		// symmetrie de cette composante par rapport a taille
		else if ((face==3) or (face==4)) z_=2*taille-z_;
	}

	double Vecteur::somme() const {
		return abs(x_)+abs(y_)+abs(z_);
	}
		
