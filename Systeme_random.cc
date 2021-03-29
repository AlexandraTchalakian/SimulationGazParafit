#include "Systeme_random.h"
using namespace std;


Systeme::Systeme() {
	for (int i (0) ; i<25 ; ++i) {
		cout << endl;
	}
	double profondeur (0), largeur (0), hauteur(0);
	cout << "Quelle taille d'enceinte désirez-vous ? " << endl << "profondeur (" << min_taille << "-" << max_taille << ") : ";
	demander_nb(profondeur, min_taille, max_taille);
	cout << "largeur (" << min_taille << "-" << max_taille << ") : ";
	demander_nb(largeur, min_taille, max_taille);
	cout << "hauteur (" << min_taille << "-" << max_taille << ") : ";
	demander_nb(hauteur, min_taille, max_taille);
	
	enceinte=(Enceinte(profondeur, largeur, hauteur));
	
	
	int nb_gaz (0);
	cout << "Combien de gaz voulez-vous mettre dans l'enceinte ? (1-4) ";
	demander_nb(nb_gaz, 1, 4);
	int part_He (0);
	demander_nb_part(part_He, min_part, max_part, "d'helium");
	ajouterGaz(GLHeliumBrownien (0, 0, 0, 0, 0, 0), 1);
	if (part_He>1) {
		ajouterGaz(GLHelium (0, 0, 0, 0, 0, 0), (part_He-1));
	}
	if (nb_gaz>1) {
		int part_Ne (0);
		demander_nb_part(part_Ne, min_part, max_part, "de neon");
		ajouterGaz(GLNeon (0, 0, 0, 0, 0, 0), part_Ne);
		if (nb_gaz>2) {
			int part_Ar (0);
			demander_nb_part(part_Ar, min_part, max_part, "d'argon");
			ajouterGaz(GLArgon (0, 0, 0, 0, 0, 0), part_Ar);
			if (nb_gaz>3) {	
				int part_Kr (0);
				demander_nb_part(part_Kr, min_part, max_part, "de krypton");
				ajouterGaz(GLKrypton (0, 0, 0, 0, 0, 0), part_Kr);
			}
		}
	}
}

void Systeme::dessine() const{	 //methode affichant les particule contenues dans le  gaz 
	enceinte.dessine();
	for(auto const& elem: gaz){ //boucle c++ 2011 pour parcourrir tous les elements du tableau
		elem->dessine(); // appelle la methode dessine propre a l'objet pointe
	}
}


void Systeme::demander_nb(double& nombre, double min, double max) {
	bool premiere_iteration (true);
	do {
		if (!premiere_iteration) cerr << "Un nombre entre " << min << " et " << max << " (inclus) est attendu ici." << endl;
		premiere_iteration=false;
		cin>>nombre;
		if (cin.fail()) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	} while ((nombre<min) or (nombre>max));
}

void Systeme::demander_nb(int& nombre, double min, double max) {
	double tmp;
	demander_nb(tmp, min, max);
	nombre=tmp;
}


void Systeme::demander_nb_part(int& nombre, int min, int max, string nom_gaz) {
	cout << "Combien voulez de particules " << nom_gaz << " (" << min << "-" << max << ") ? ";
	demander_nb(nombre, min, max);	
}

double Systeme::get_largeur_enceinte() {
	return (enceinte.get_largeur());
}

double Systeme::get_profondeur_enceinte() {
	return (enceinte.get_profondeur());
}

double Systeme::get_hauteur_enceinte() {
	return (enceinte.get_hauteur());
}
	
	
//methode permetant d'ajouter une particule
void Systeme::ajouterParticule(Particule const& p ){
		gaz.push_back(p.copie());	//convertion des pointeurs à la c en unique_pt
}

void Systeme::ajouterGaz(Particule const& p, unsigned int const& nb) {
	double cste_spec ((1000*R)/p.get_masse());
	for (size_t i(0) ; i<nb ; i++) {
		ajouterParticule(p);
		(gaz.back())->set_part(
		tirage.uniforme(0.0, enceinte.get_hauteur()),
		tirage.uniforme(0.0,enceinte.get_largeur()),
		tirage.uniforme(0.0, enceinte.get_profondeur()),
		tirage.gaussienne(0.0, sqrt(cste_spec*Temperature)),
		tirage.gaussienne(0.0, sqrt(cste_spec*Temperature)),
		tirage.gaussienne(0.0, sqrt(cste_spec*Temperature)));
	}
}

void Systeme::evolue (double dt) {
	choc.clear();
	for (size_t i (0); i<gaz.size() ; i++) {
		(gaz[i])->evolue(dt); 					// evolution de la position des particules
		// debut de la partie de gestion des rebonds contre les parois
		bool test (false);
		do {										//la boucle permet d'être sur qu'aucun choc avec une paroi ne soit neglige, car le programme n'en sort 
			test=false;								//qu'une fois qu'un passage a ete effecute sans qu'une paroi n'ait ete touchee
			if ((((gaz[i])->get_position()).get_x())<0) {								// un des coin de l'enceinte etant place au 0, 0, 0 ; pour verifier 
				test=true;																// si une particule sort de l'enceinte, il suffit de verifier si une
				cout << "La particule " << i+1 << " rebondit sur la face 1" << endl;	// des coordonnees de sa position est negative ou plus grande que 
				(gaz[i])->rebond(1, 0);													// la taille de l'enceinte dans cette direction.
			} else if ((((gaz[i])->get_position()).get_x())>enceinte.get_hauteur()) {	// le cas echeant, on appelle la methode rebond de particule avec la face
				test=true;																// rencontree et la distance entre l'origine et cette face
				cout << "La particule " << i+1 << " rebondit sur la face 6" << endl;
				(gaz[i])->rebond(6, enceinte.get_hauteur());
			}
			if ((((gaz[i])->get_position()).get_y())<0) {
				test=true;
				cout << "La particule " << i+1 << " rebondit sur la face 2" << endl;
				(gaz[i])->rebond(2, 0);
			} else if ((((gaz[i])->get_position()).get_y())>enceinte.get_largeur()) {
				test=true;
				cout << "La particule " << i+1 << " rebondit sur la face 5" << endl;
				(gaz[i])->rebond(5, enceinte.get_largeur());
			}
			if ((((gaz[i])->get_position()).get_z())<0) {
				test=true;
				cout << "La particule " << i+1 << " rebondit sur la face 3" << endl;
				(gaz[i])->rebond(3, 0);
			} else if ((((gaz[i])->get_position()).get_z())>enceinte.get_profondeur()) {
				test=true;
				cout << "La particule " << i+1 << " rebondit sur la face 4" << endl;
				(gaz[i])->rebond(4, enceinte.get_profondeur());
			}
		} while (test==true);
		// fin de la partie de gestion des rebonds contre les parois
		
		// debut de la gestion des collisions		
		for (size_t j (0) ; j<i ; j++) {							// Cette boucle permet de tester si des particules dont la position a deja ete actualisee
			Vecteur tmp ((gaz[i])->get_position());					// se trouvent dans le meme pavage d'espace que la particule etudiee.
			
			tmp-=((gaz[j])->get_position());						// a ce point la, le vecteur tmp contient le vecteur de la difference entre la
																	// position des deux particules
																	
			//if (tmp.norme_carre()<(pow(EPSILON, 2))) {			//pavage spherique de l'espace
			if (tmp.somme()<EPSILON) {								//pavage cubique de l'espace
				array<size_t, 2>  temporaire = {{i+1, j+1}};
				choc.push_back(temporaire);		//si une collision est possible, on stocke un doublet contenant la position dans
			}														//le vecteur gaz des deux particules
		}
	}



	for (size_t i (0) ; i<choc.size() ; i++) {		// permet de parcourir tous les doublets
		for (int a (0) ; a<2 ; a++) {				// permet de parcourir les deux particules d'un doublet
			
			/*for (auto doublet : choc) {			// section de debugage permettant d'afficher le contenu de choc
				for (int m (0) ; m<2 ; m++) {
					cout << doublet[m] << " ";
				}
				cout << endl;
			}
			cout << "fin" << endl; */
			
			candidat.clear();
			if (choc[i][a]>0) {			// permet de ne plus prendre en compte les doublets dont au moins une des particule a deja subi un choc
				size_t  max (choc[i][(a+1)%2]), min (choc[i][(a+1)%2]), mem1 (choc[i][a]), mem2 (choc[i][(a+1)%2]); // mem1 stocke la position +1 dans gaz de
																		// la particule qui va entrer en collision, mem2 stocke la position +1 dans gaz de son
																		// binome de doublet, min et max seront repsectivement les valeurs minimales
																		// et maximales des positions +1 dans gaz des particules pouvant entrer en collision
																		// avec notre particule (mem1) ;  (a+1)%2 permet de renvoyer le binome de doublet
																		// car il vaut 1 quand a vaut 0 et 0 quand a vaut 1.
																		
																		
				for (size_t j (i+1) ; j<choc.size() ; j++) {			// parcourt toutes les particules de tous les autres doublets, et, si une des particules
					for (int k (0); k<2 ; k++ ){						// d'un autre doublet et notre particule (mem1) sont les memes, on stocke son binome 
																		// de doublet dans le vecteur candidat
						if (mem1==choc[j][k]) {					
							candidat.push_back(choc[j][(k+1)%2]);
							if ((choc[j][(k+1)%2])<min) min=(choc[j][(k+1)%2]); //si la position +1 dans gaz du binome de doublet est plus grande resp. plus
							if ((choc[j][(k+1)%2])>max) max=(choc[j][(k+1)%2]);	// petite que la valeur actuelle de max, alors on affecte cette valeur
																				// a max resp. min
						}
					}
				}
				double rand (tirage.uniforme(min, max)); 			// tirage au sort d'un double aleatoire entre min et max
				for (auto elem : candidat) {
					if ((abs(rand-elem))<(abs(rand-mem2))) mem2=elem;	// on prend la particule candidate dont la position +1 dans gaz est la plus proche  
																		// du nombre tire au sort
				}
				// maintenant qu'on sait quelles particules vont entrer en collision, on peut s'occuper du choc a proprement parler
				
				// version avec selection aleatoire des vitesses resultantes
				double phi (tirage.uniforme(0, (2*M_PI)));				
				Vecteur vg (((gaz[mem1-1])->vg(*(gaz[mem2-1]))));
				double L (((gaz[mem1-1])->get_vitesse()-vg).norme());
				double z (tirage.uniforme(-L, L));
				
				// version en forcant le zenith et l'azimuth a valoir respectivement pi/2 et pi/3 pour le programme de test
				/*double phi (M_PI/3);									
				Vecteur vg (((gaz[mem1-1])->vg(*(gaz[mem2-1]))));
				double L (((gaz[mem1-1])->get_vitesse()-vg).norme());	
				double z (0);*/
				
				double r (sqrt(pow(L, 2)-pow(z, 2)));
				Vecteur v0 (r*cos(phi), r*sin(phi), z);
				cout << "La particule " << mem1 << " entre en collision avec une autre particule (la particule " << mem2 << ")." << endl;
				cout << " avant le choc :" << endl;
				cout  << "   part. " << mem1 << " : : pos : " << (gaz[mem1-1])->get_position() << " ; v : " << (gaz[mem1-1])->get_vitesse() << endl;
				cout << "   autre : : pos : " << (gaz[mem2-1])->get_position() << " ; v : " << (gaz[mem2-1])->get_vitesse() << endl;
				
				(gaz[mem1-1])->collision((*(gaz[mem2-1])), vg, v0); 	// effectue la collision en tant que tel
				
				cout << " apres le choc :" << endl ;
				cout  << "   part. " << mem1 << " : : pos : " << (gaz[mem1-1])->get_position() << " ; v : " << (gaz[mem1-1])->get_vitesse() << endl;
				cout << "   autre : : pos : " << (gaz[mem2-1])->get_position() << " ; v : " << (gaz[mem2-1])->get_vitesse() << endl;
				for (size_t l (0); l<choc.size() ; l++) {				// parcourt le vecteur choc et met a 0 la position des particules ayant deja subi un choc
					if ((choc[l][0]==mem1) or (choc[l][1]==mem1) or (choc[l][0]==mem2) or (choc[l][1]==mem2)) {
						choc[l][0]=(0);
						choc[l][1]=(0);
					}
				}
			}
		}
	}
	// fin de la partie gestion des collisions	
	
	
	
	
}
	
	

 
