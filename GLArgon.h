#ifndef PRJ_GLARGON_H
#define PRJ_GLARGON_H
#include "Vue_OpenGL.h"
#include "Particule.h"
#include "Enceinte.h"

class GLArgon:public Particule{
	public:
		GLArgon(double x1, double x2, double x3, double v1, double v2, double v3);
		GLArgon(Vecteur pos, Vecteur vit);
		~GLArgon();
		virtual void dessine()const override;
		virtual std::unique_ptr<Particule> copie() const override;
		std::unique_ptr<GLArgon> clonneMe() const;
	private:
		static constexpr double masse_spec=39.948;
		GLUquadric* sphere;
};
#endif // PRJ_GLARGON_H
