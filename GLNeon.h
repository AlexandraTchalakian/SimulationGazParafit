#ifndef PRJ_GLNEON_H
#define PRJ_GLNEON_H
#include "Vue_OpenGL.h"
#include "Particule.h"
#include "Enceinte.h"

class GLNeon:public Particule{
	public:
		GLNeon(double x1, double x2, double x3, double v1, double v2, double v3);
		GLNeon(Vecteur pos, Vecteur vit);
		~GLNeon();
		virtual void dessine()const override;
		std::unique_ptr<GLNeon> clonneMe() const;
		virtual std::unique_ptr<Particule> copie() const override;
	private:
		static constexpr double masse_spec=20.1797;
		GLUquadric* sphere;
};

#endif // PRJ_GLNEON_H
