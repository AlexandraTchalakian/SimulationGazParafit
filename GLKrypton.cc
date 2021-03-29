#include "GLKrypton.h"
using namespace std;

GLKrypton::GLKrypton(double x1, double x2, double x3, double v1, double v2, double v3) 
: Particule(x1, x2, x3, v1, v2, v3, masse_spec), sphere(gluNewQuadric())
{}

GLKrypton::GLKrypton(Vecteur pos, Vecteur vit) 
: Particule (pos, vit, masse_spec), sphere(gluNewQuadric())
{}

GLKrypton::~GLKrypton(){
	gluDeleteQuadric(sphere);
}

void GLKrypton::dessine() const
{
	glPushMatrix();              // Sauvegarder l'endroit où l'on se trouve
	glTranslated((get_position()).get_x(), (get_position()).get_y(), (get_position()).get_z());  	   /* Se positionner à l'endroit où l'on veut
																										* dessiner                                */
	glColor4d(0.0, 1.0, 1.0, 1.0); // turquoise
	gluSphere(sphere, 3.0, 30, 30);// Dessiner une sphère
	glPopMatrix();                 // Revenir à l'ancienne position
}

unique_ptr<Particule> GLKrypton::copie() const{
	return this->clonneMe();
}
unique_ptr<GLKrypton> GLKrypton::clonneMe() const{
	return unique_ptr<GLKrypton> (new GLKrypton(*this));
}

