#include "Fenetre.h"
using namespace std;

BEGIN_EVENT_TABLE(Fenetre, wxFrame)
    EVT_MENU( wxID_EXIT, Fenetre::OnExit )
END_EVENT_TABLE()

// ======================================================================
Fenetre::Fenetre( wxString const& titre 
                , wxSize   const& taille
                , wxPoint  const& position
                , long            style
                )
: wxFrame(0, wxID_ANY, titre, position, taille, style)
, fogl(new Vue_OpenGL(this))
{
  // Barre de menu
  wxMenu* winMenu = new wxMenu;
  winMenu->Append(wxID_EXIT, wxT("&Close"));

  wxMenuBar* menuBar = new wxMenuBar;
  menuBar->Append(winMenu, wxT("&Window"));

  SetMenuBar(menuBar);

  //Center(true);
  // Affiche (montre) la fenetre
  Show(true);
  //ShowFullScreen(true);
  // Initialise OpenGL
  fogl->InitOpenGL();
}

/*void Fenetre::rafraichir()
{
   fogl->Refresh(false);
}*/
