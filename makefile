CXX=g++-4.7
CXXFLAGS = `wx-config --cxxflags` -std=c++11
CXXFLAGS += -pedantic -Wall
LDLIBS   = `wx-config --libs gl,core,base` -lGL -lGLU
 

 
all:: projet

Enceinte.o: Enceinte.cc Enceinte.h  Vue_OpenGL.h 
Vecteur2.o: Vecteur2.cc Vecteur2.h
Particule.o: Particule.cc Particule.h Vecteur2.h 
GLArgon.o: GLArgon.h GLArgon.cc Particule.h
GLNeon.o: GLNeon.h GLNeon.cc Particule.h
GLHelium.o: GLHelium.h GLHelium.cc Particule.h
GLKrypton.o: GLKrypton.h GLKrypton.cc Particule.h
GLHeliumBrownien.o: GLHeliumBrownien.h GLHeliumBrownien.cc GLHelium.h
Vue_OpenGL.o: Vue_OpenGL.h Vue_OpenGL.cc Systeme_random.h
Fenetre.o: Fenetre.h Fenetre.cc Vue_OpenGL.h
GUI.o:GUI.h GUI.cc
Systeme_random.o: Systeme_random.h Systeme_random.cc GLHeliumBrownien.h GLHelium.h GLKrypton.h GLNeon.h GLArgon.h Enceinte.h GenerateurAleatoire.h
projet.o: projet.cc

projet: Fenetre.o Vue_OpenGL.o GUI.o Enceinte.o Vecteur2.o Particule.o projet.o GLHeliumBrownien.o GLKrypton.o GLHelium.o GLNeon.o GLArgon.o Systeme_random.o

new: mrproper all
 
mrproper: clean
	@-/bin/rm -fr 
 
clean:
	@-/bin/rm -f *.o


