#ifndef PRJ_GLHELIUM_H
#define PRJ_GLHELIUM_H
#include "Vue_OpenGL.h"
#include "Particule.h"
#include "Enceinte.h"

class GLHelium:public Particule{
	public:
		GLHelium(double x1, double x2, double x3, double v1, double v2, double v3);
		GLHelium(Vecteur pos, Vecteur vit);
		~GLHelium();
		virtual void dessine()const override;
		virtual std::unique_ptr<Particule> copie() const override;
		std::unique_ptr<GLHelium> clonneMe() const;
	protected:
		static constexpr double masse_spec=4.002602;
		GLUquadric* sphere;
};
#endif // PRJ_GLHELIUM_H
