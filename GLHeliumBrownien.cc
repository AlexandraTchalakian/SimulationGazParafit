#include "GLHeliumBrownien.h"
using namespace std;

GLHeliumBrownien::GLHeliumBrownien(double x1, double x2, double x3, double v1, double v2, double v3)
:GLHelium(x1,x2,x3,v1,v2,v3)
{}

GLHeliumBrownien::~GLHeliumBrownien(){}

void GLHeliumBrownien::dessine() const{
	GLHelium::dessine();
	glBegin(GL_LINE_STRIP);
    for (size_t i(0); i < historique.size(); ++i) {
		glVertex3f(historique[i].get_x(), historique[i].get_y(), historique[i].get_z());
    }
    glEnd();

}

void GLHeliumBrownien::evolue(double dt){
	if (historique.size()<100) {
		historique.push_back(position);
	}
	Particule::evolue(dt);
}

unique_ptr<Particule> GLHeliumBrownien::copie() const{
	return this->clonneMe();
}
unique_ptr<GLHeliumBrownien> GLHeliumBrownien::clonneMe() const{
	return unique_ptr<GLHeliumBrownien> (new GLHeliumBrownien(*this));
}
