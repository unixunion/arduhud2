/*

Drawable object base class

*/

#ifndef DRAWABLE_H
#define DRAWABLE_H

#import "Arduino.h"

class Drawable
{
  public:
    virtual void draw(){}; // draw of UI elements of an object
    virtual void update(){}; // self update of a object
    virtual void toggle(){};
};

#endif
