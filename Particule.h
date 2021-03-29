#ifndef PRJ_PARTICULE_H
#define PRJ_PARTICULE_H
#include <memory>
#include "Vecteur2.h"
#include "Dessinable.h"


class Particule : public Dessinable {
protected :
	Vecteur position;
	Vecteur vitesse;
	double masse;
	bool choc;
public :
	Particule (Vecteur pos, Vecteur vit, double m) //constructeur prenant des vecteurs déjà construits en argument
	: position(pos), vitesse(vit), masse(m), choc(false){}
	Particule (double x1, double x2, double x3, double v1, double v2, double v3, double m) //constructeur prenant les coordonnées des vecteurs en argument
	: position (Vecteur(x1, x2, x3)), vitesse (Vecteur(v1, v2, v3)), masse(m), choc(false) {}
	std::ostream& affiche(std::ostream& sortie) const; // méthode servant à la surcharge de l'operateur d'affichage
	virtual std::unique_ptr<Particule> copie() const=0;
	virtual ~Particule() {}	
	Vecteur get_vitesse() const;   // getters pour la position et la vitesse
	Vecteur get_position() const;
	double get_masse() const;
	void set_part (double x1, double x2, double x3, double v1, double v2, double v3);
	void collision (Particule& p2, Vecteur vg, Vecteur v0);		// prend en arguments une particule et les vecteurs vg et v0 tels que decrits dans 
																// la description du projet et effectue la collision entre les 2 particules
	void rebond (int face, double taille);						// fait une symmetrie de la position et de la vitesse de la particule par rapport 
																// a une face de l'enceinte placee a taille de l'origine
	virtual void evolue (double dt);									// met a jour la position de la particule en fonction de sa vitesse et du pas de temps
	Vecteur vg (const Particule& p2); 							// retourne le vecteur vg tel que decrit dans la description du projet
	bool check_choc() const;
};

std::ostream& operator<<(std::ostream&  sortie, const Particule& p); //surcharge de l'operateur d'affichage

#endif // PRJ_PARTICULE_H
