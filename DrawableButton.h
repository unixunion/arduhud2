#ifndef DRAWABLEBUTTON_H
#define DRAWABLEBUTTON_H

#include "Drawable.h"
#include <TVout.h>
#include "Arduino.h"

class DrawableButton : public Drawable 
{	
public:
        DrawableButton(){};
	inline DrawableButton(TVout &tv, int x, int y, int w, int h, char * title) 
        {
          _x = x;
          _y = y;
          _w = w;
          _h = h;
          _tv = &tv;
          _title = title;
          _change = false;
        }
	virtual void draw();
        void name(char* title);
        virtual void update();
        void toggle();
       	char * _title;
        boolean _change; // if true, change state at next update!
        TVout * _tv;
protected:
        int _x;
        int _y;
        int _w;
        int _h;
};

// when setting a button, we black out, set the new title and call draw again
void DrawableButton::name(char* title) {
  //_tv.draw_rect(_x, _y, _w, _h, WHITE, BLACK);
  _title = title;
//  Serial.println(F("DrawableButton::set(char* title)"));
  draw();
}



void DrawableButton::draw() 
{
  Serial.println(F("DrawableButton::draw(): "));
  _tv->print(_x+2,_y+2,_title);
  _tv->draw_rect(_x, _y, _w, _h, WHITE);
}

void DrawableButton::toggle()
{
//  Serial.println(F("DrawableButton::toggle()"));
  _change = true;
}

void DrawableButton::update() 
{
//  Serial.println(F("DrawableButton::update()"));
    if (_change) {
      _tv->draw_rect(_x, _y, _w, _h, WHITE, INVERT);
      _change = false;
    }
}

#endif
