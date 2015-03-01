#include "pgfx.h"

pgfx_HBAR::pgfx_HBAR(int x, int y, int w, int h, char * name, Adafruit_SSD1306 & display)
{
  _x = x;
  _y = y;
  _width = w;
  _height = h;
  _textsize  = 1;
  _textcolor = _textbgcolor = 0xFFFF;
  _display = & display;
  _name = name;
}

void pgfx_HBAR::update(float value, float max)
{
  int fp = (value / max) * (_height-20);
  _display->setTextSize(1);
  _display->setTextColor(WHITE);
  _display->drawRoundRect(_x, _y+16, _width, _height-16, 4, WHITE);
  _display->fillRoundRect(_x+2, _y+18 + ((_height-20) - fp), _width-4, fp, 4, WHITE);
  _display->setCursor(_x,_y);
  _display->println(_name);
}

void pgfx_HBAR::update(float v1, float m1, float v2, float m2)
{
  int fp1 = (v1 / m1) * (_height-20);
  int fp2 = (v2 / m2) * (_height-20);
  _display->setTextSize(1);
  _display->setTextColor(WHITE);
  _display->drawRoundRect(_x, _y+16, _width, _height-16, 4, WHITE);
  _display->fillRoundRect(_x+2, _y+18 + ((_height-20) - fp1), (_width/2)-3, fp1, 4, WHITE);
  _display->fillRoundRect(_x+(_width/2)+1, _y+18 + ((_height-20) - fp2), (_width/2)-3, fp2, 4, WHITE);
  _display->setCursor(_x,_y);
  _display->println(_name);
}
 
