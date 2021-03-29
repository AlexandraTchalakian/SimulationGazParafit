#ifndef PRJ_GLHELIUMBROWNIEN_H
#define PRJ_GLHELIUMBROWNIEN_H
#include "GLHelium.h"
#include "Vecteur2.h"
#include <vector>


class GLHeliumBrownien:public GLHelium{
	public:
		GLHeliumBrownien(double x1, double x2, double x3, double v1, double v2, double v3);
		virtual ~GLHeliumBrownien();
		virtual void dessine() const override;
		virtual void evolue(double dt) override;
		virtual std::unique_ptr<Particule> copie() const override;
		std::unique_ptr<GLHeliumBrownien> clonneMe() const;
	private:
		std::vector<Vecteur> historique;
};
#endif //PRJ_GLHELIUMBROWNIEN_H
