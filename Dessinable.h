#ifndef PRJ_DESS_H
#define PRJ_DESS_H


class Dessinable {
public :
	virtual void dessine() const =0;  	//la méthode n'est pas définie pour une dessinable pur, elle donc virtuelle pure
	virtual ~Dessinable() {}		
};

#endif // PRJ_DESS_H
