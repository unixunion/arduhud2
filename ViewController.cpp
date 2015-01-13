/* 
 ViewController library for tv out
*/

//#include "Arduino.h"
#include "ViewController.h"
#include <TVout.h>
#include <fontALL.h>
#include "Drawable.h"

// calls draw on a array of Drawable objects
void ViewController::changeView(Drawable * const drawableObject[], int maxn) {
  contents = drawableObject;
  Serial.println(F("ViewController::changeView() enter"));
  _tv->clear_screen();
  
  //int maxn = numObjects; //size(drawableObject);
//  Serial.print(F("MaxN: "));
//  Serial.println(maxn);
//  delay(500);
  numObjects = maxn;
  
  //for drawable in view[index] call .draw();
  for (int x=0; x<=numObjects; x++) {
//    Serial.print(F("Calling draw on object: "));
//    Serial.println(x);
//    delay(500);

    drawableObject[x]->draw();
  }
//  Serial.println(F("ViewController::changeView() done"));
}

void ViewController::update() {
//  Serial.println(F("ViewController::update() enter"));
//  int maxn = size(contents);
  for (int x=0; x<=numObjects; x++) {
//    Serial.print(F("update x: "));
//    Serial.println(x);
    contents[x]->update();
  }
//  Serial.println(F("ViewController::update() done"));
}

// count objects in a Drawable array
int ViewController::size(Drawable * const b[]) {
    return sizeof b;
}



