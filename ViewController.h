/*
  multiple view controller, home of the TVOUT
*/

#ifndef VIEWCONTROLLER_H
#define VIEWCONTROLLER_H

//#include "Arduino.h"
#include <TVout.h>
#include <fontALL.h>
#include "Drawable.h"

class ViewController
{
  public:
    ViewController(){};
    inline ViewController(TVout &tv){
      _tv = &tv;
//      _tv.select_font(font4x6); 
    }
    void changeView(Drawable * const drawableObject[], int maxn);
    void draw();
    void update();
    int currentView;
    int numObjects;
    Drawable * const * contents;
    int size(Drawable * const b[]);
    TVout * _tv;
};

#endif
