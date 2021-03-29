#include "GLNeon.h"
using namespace std;


GLNeon::GLNeon(double x1, double x2, double x3, double v1, double v2, double v3) 
: Particule(x1, x2, x3, v1, v2, v3, masse_spec),sphere(gluNewQuadric())
{}

GLNeon::GLNeon(Vecteur pos, Vecteur vit) 
: Particule (pos, vit, masse_spec), sphere(gluNewQuadric())
{}

GLNeon::~GLNeon(){
	gluDeleteQuadric(sphere);
}

void GLNeon::dessine() const
{
	glPushMatrix();             // Sauvegarder l'endroit où l'on se trouve
	glTranslated((get_position()).get_x(), (get_position()).get_y(), (get_position()).get_z());  /* Se positionner à l'endroit où l'on veut
																								  * dessiner                                */
	glColor4d(0.0, 0.0, 1.0, 1.0); // Choisir la couleur (bleu ici)
	gluSphere(sphere, 1.5, 30, 30);// Dessiner une sphère
	glPopMatrix();                 // Revenir à l'ancienne position
}
unique_ptr<Particule> GLNeon::copie() const{
	return this->clonneMe();
}
unique_ptr<GLNeon> GLNeon::clonneMe() const{
	return unique_ptr<GLNeon> (new GLNeon(*this));
}
