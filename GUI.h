#ifndef PRJ_GUI_H
#define PRJ_GUI_H
#include "wx/wxprec.h"
#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif
#include "wx/glcanvas.h" // Pour combiner wxWidgets et OpenGL
#include "Fenetre.h"
using namespace std;

class GUI : public wxApp
{
public:
  bool OnInit();
};

#endif // PJR_GUI_H
