#ifndef PRJ_SYSTEME_H
#define PRJ_SYSTEME_H
#include <iostream>
#include <vector>
#include <memory>
#include "GLHelium.h"
#include "GLNeon.h"
#include "GLArgon.h"
#include "GLKrypton.h"
#include "GLHeliumBrownien.h"
#include "Enceinte.h"
#include "GenerateurAleatoire.h"
#include <array>

//declaration d'une classe systeme qui represente un gaz contenu dans une enceinte, cette classe hertie de la classe dessinables
class Systeme: public Dessinable{
	public:
		Systeme();
		Systeme(double x, double y, double z) : Systeme() {		// constructeur initialisant l'enceinte avec les valeurs en arguments 
			Enceinte(x,y,z);
		}
		virtual void dessine() const override;	// methode heritee de classe dessine
		void ajouterParticule(Particule const& p);	// permet d'ajouter une particule a gaz
		void ajouterGaz(Particule const& p, unsigned int const& nb);
		void evolue (double dt);				// met a jour la position de toutes les particules du systeme apres un temps dt
		double get_largeur_enceinte();
		double get_profondeur_enceinte();
		double get_hauteur_enceinte();
	private:
		Enceinte enceinte;	//enceinte contenant le gaz
		std::vector<std::unique_ptr<Particule>> gaz;	//ensemble de pointeurs sur les particules contenues dans le systeme
		std::vector<std::array<size_t, 2>> choc;		// permet de stocker des doublets contenant la position dans gaz de deux particules pouvant entrer en collision 
		std::vector<int> candidat;		//permet de stocker la poisiont dans gaz +1 de toutes les particules 
									// pouvant entrer en collision avec une particule donnee
		GenerateurAleatoire tirage; //pour les tirages au sort
		static int constexpr EPSILON=1.28;   // pas d'espace
		static constexpr double Temperature=298; //temperature dans l'enceinte
		static constexpr double R=8.314472; //constante des gaz parfaits
		static double constexpr min_taille=10;
		static double constexpr max_taille=350;
		static int constexpr min_part=1;
		static int constexpr max_part=700;
		void demander_nb(double& nombre, double min, double max);
		void demander_nb(int& nombre, double min, double max);
		void demander_nb_part(int& nombre, int min, int max, std::string nom_gaz);
		
};

#endif // PRJ_SYSTEME_H
