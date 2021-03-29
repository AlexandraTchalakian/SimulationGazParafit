#include "GLArgon.h"
using namespace std;

GLArgon::GLArgon(double x1, double x2, double x3, double v1, double v2, double v3) 
: Particule(x1, x2, x3, v1, v2, v3, masse_spec), sphere(gluNewQuadric())
{}

GLArgon::GLArgon(Vecteur pos, Vecteur vit) 
: Particule (pos, vit, masse_spec), sphere(gluNewQuadric())
{}

GLArgon::~GLArgon(){
	gluDeleteQuadric(sphere);
}

void GLArgon::dessine() const
{
	glPushMatrix();              // Sauvegarder l'endroit où l'on se trouve
	glTranslated((get_position()).get_x(), (get_position()).get_y(), (get_position()).get_z());  	   /* Se positionner à l'endroit où l'on veut
																										* dessiner                                */
	glColor4d(1.0, 0.0, 0.0, 1.0); // rouge
	gluSphere(sphere, 2.5, 30, 30);// Dessiner une sphère
	glPopMatrix();                 // Revenir à l'ancienne position
}

unique_ptr<Particule> GLArgon::copie() const{
	return this->clonneMe();
}
unique_ptr<GLArgon> GLArgon::clonneMe() const{
	return unique_ptr<GLArgon> (new GLArgon(*this));
}

