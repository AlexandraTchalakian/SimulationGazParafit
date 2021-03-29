#include "GUI.h"

bool GUI::OnInit()
{
  // Crée la fenêtre principale
  Fenetre* f = new Fenetre(wxT("Simulation temps reel"),
                           wxSize(800, 600));
  SetTopWindow(f);
  return (f != 0);
}


