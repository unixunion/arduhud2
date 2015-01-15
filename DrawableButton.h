#ifndef DRAWABLEBUTTON_H
#define DRAWABLEBUTTON_H

#include "Drawable.h"
#include <TVout.h>

class DrawableButton : public Drawable 
{	
public:
        DrawableButton(){};
	inline DrawableButton(TVout &tv, int x, int y, int w, int h, char * title) 
        {
          _x = (byte)x;
          _y = (byte)y;
          _w = (byte)w;
          _h = (byte)h;
          _tv = &tv;
          _title = title;
          _change = false;
        }
	virtual void draw();
        void name(char* title);
        virtual void update();
        void toggle();
        int getX();
        int getY();
        int getW();
        int getH();
       	char * _title;
        boolean _change; // if true, change state at next update!
        TVout * _tv;
protected:
        byte _x;
        byte _y;
        byte _w;
        byte _h;
};

int DrawableButton::getX() {
   return (int)_x; 
};

int DrawableButton::getY() {
   return (int)_y; 
};

int DrawableButton::getW() {
   return (int)_w; 
};

int DrawableButton::getH() {
   return (int)_h; 
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
  _tv->print(getX()+2,getY()+2,_title);
  _tv->draw_rect(getX(), getY(), getW(), getH(), WHITE);
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
      _tv->draw_rect(getX(), getY(), getW(), getH(), WHITE, INVERT);
      _change = false;
    }
}

#endif
