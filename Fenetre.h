#ifndef PRJ_FENETRE_H
#define PRJ_FENETRE_H
#include "wx/wxprec.h"
#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif
#include "wx/glcanvas.h" // Pour combiner wxWidgets et OpenGL
#include "Vue_OpenGL.h"


// fenetre(s) principale(s)
class Fenetre: public wxFrame
{
public:
  Fenetre( wxString const& titre 
         , wxSize   const& taille   = wxDefaultSize
         , wxPoint  const& position = wxDefaultPosition
         , long            style    = wxDEFAULT_FRAME_STYLE
         );

  virtual ~Fenetre() {}
    void rafraichir();

protected:
  void OnExit(wxCommandEvent& event) { Close(true); }
	
  Vue_OpenGL* fogl;

DECLARE_EVENT_TABLE()
};

#endif //PJR_FENETRE_H
