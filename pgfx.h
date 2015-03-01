#ifndef _PSIMAX_GFX_H
#define _PSIMAX_GFX_H

#include <Adafruit_SSD1306.h>

class pgfx_HBAR {
public:
	pgfx_HBAR(int x, int y, int w, int h, char * name, Adafruit_SSD1306 &display); // Constructor

	void
		update(float value, float max),
		update(float v1, float m1, float v2, float m2);

private:
	int
		_width, _height,
		_textsize, _textcolor, _textbgcolor,
		_x, _y, _shift, _header;
	Adafruit_SSD1306 * _display;
	char * _name;

};

#endif