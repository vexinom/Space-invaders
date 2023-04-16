#pragma once
using namespace std;
using namespace sf;
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

bool evil_enter = false;

class Menu_elements
{
public:

	Font font;
	Text text;
	float width, x, b, y;

	Menu_elements(Text text_c, Font font_c, float width_c, float x_c, float b_c, float y_c)
	{
		text = text_c; font = font_c; width = width_c; x = x_c; b = b_c; y = y_c;
	}
	Menu_elements()
	{}
	~Menu_elements()
	{}
};


