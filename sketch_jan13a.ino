#include <MemoryFree.h>
#include <TVout.h>
#include <fontALL.h>
#import "Drawable.h"
#import "DrawableButton.h"
#import "ViewController.h"


static TVout tv;
//TVout & _tv = tv;

DrawableButton b1;
DrawableButton b2;
DrawableButton b3;
DrawableButton b4;
DrawableButton b5;
DrawableButton b6;
DrawableButton b7;
DrawableButton b8;

ViewController vc;

Drawable * const v1contents[] = {&b1, &b2, &b3, &b4, &b5, &b6, &b7, &b8};
int v1_size = 7;


void setup() {
  // put your setup code here, to run once:
//  Serial.begin(9600);
  tv.begin(NTSC,96,64);
  tv.select_font(font4x6);
  tv.clear_screen();
  
  // Create the View Controller
  vc = ViewController(_tv);
  
  // Create some objects
  b1 = DrawableButton(&tv, 0, 0,24, 8,"Test1");
  b2 = DrawableButton(&tv, 0,12,24, 8,"Test2");
  b3 = DrawableButton(&tv, 0,24,24, 8,"Test3");
  b4 = DrawableButton(&tv, 0,36,24, 8,"Test4");
  b5 = DrawableButton(&tv, tv.hres()-25,0,24, 8,"Test5");
  b6 = DrawableButton(&tv, tv.hres()-25,12,24, 8,"Test6");
  b7 = DrawableButton(&tv, tv.hres()-25,24,24, 8,"Test7");
  b8 = DrawableButton(&tv, tv.hres()-25,36,24, 8,"Test8");

 
  // Create a collection of some objects
//  Drawable * const v1contents[] = {&b1, &b2, &b3};
  
//  Drawable * const * currentView = v1contents;
 
  // Change the view to the collection
  vc.changeView(v1contents, v1_size);

//  Drawable * d = &button1;
//  d->draw();
  delay(1000);
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(250);
 
  for (int x = 0; x<=v1_size; x++) {
     int f = random(1, 5);
     if (f==1) {
        v1contents[x]->toggle();
     } 
  }
  vc.update();
  
  tv.draw_rect(tv.hres()/2, 0, 20, 6, BLACK);
  tv.print(tv.hres()/2, 0, freeMemory());
  
}


int size(Drawable * const b[]) {
    return sizeof *b;
}
