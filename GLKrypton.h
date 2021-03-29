#ifndef PRJ_GLKRYPTON_H
#define PRJ_GLKRYPTON_H
#include "Vue_OpenGL.h"
#include "Particule.h"
#include "Enceinte.h"

class GLKrypton:public Particule{
	public:
		GLKrypton(double x1, double x2, double x3, double v1, double v2, double v3);
		GLKrypton(Vecteur pos, Vecteur vit);
		~GLKrypton();
		virtual void dessine()const override;
		virtual std::unique_ptr<Particule> copie() const override;
		std::unique_ptr<GLKrypton> clonneMe() const;
	private:
		static constexpr double masse_spec=83.798;
		GLUquadric* sphere;
};
#endif // PRJ_GLKRYPTON_H
