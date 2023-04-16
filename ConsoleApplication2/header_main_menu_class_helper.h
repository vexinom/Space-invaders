#pragma once
#include "header_settings.h"

//Closing window - don't add anything to that
void Closing_window(RenderWindow &window)
{
	Event closing;
	while (window.pollEvent(closing))
	{
		if (closing.type == Event::Closed)
		{
			window.close();
		}
	}
}

//Parameters to game logo
void Logo_class_parameters(Menu_elements &element)
{
	element.font.loadFromFile("Fonts/joystix monospace.ttf");
	element.text.setFont(element.font);
	element.text.setCharacterSize(56);
	element.text.setFillColor(Color::Green);
	element.text.setString("SPACE INVADORS");
	element.width = element.text.getLocalBounds().width;
	element.b = element.width / 2;
	element.x = 640 - element.b;
	element.y = 100;
	element.text.setPosition(element.x, element.y);
	
}
//Names for elements from main menu
void Names_for_main_menu(Menu_elements array_elements[4])
{
	array_elements[0].text.setString("New game");
	array_elements[1].text.setString("Highest scores");
	array_elements[2].text.setString("Settings");
	array_elements[3].text.setString("Exit");
}
//Giving parameters + active element
void Array_class_parameters(Menu_elements array_elements[], int active_element, int main_menu_elements, int initial_height, int spacing)
{

	for (int i = 0; i < main_menu_elements; i++)
	{
		string text, text_2;
		text = array_elements[active_element].text.getString();
		text_2 = ">> " + text + " <<";
		array_elements[i].font.loadFromFile("Fonts/joystix monospace.ttf");
		array_elements[i].text.setFont(array_elements[i].font);

		if (active_element == i)
		{
			array_elements[active_element].text.setCharacterSize(40);
			array_elements[active_element].text.setString(text_2);
			array_elements[active_element].text.setFillColor(Color(162,162,162));
		}
		else
		{
			array_elements[i].text.setCharacterSize(36);
			array_elements[i].text.setFillColor(Color::White);
		}
	}


	for (int i = 0; i < main_menu_elements; i++)
	{
		array_elements[i].width = array_elements[i].text.getLocalBounds().width;
		array_elements[i].b = array_elements[i].width / 2;
		array_elements[i].x = 640 - array_elements[i].b;
		array_elements[i].y = initial_height + spacing * i;
		array_elements[i].text.setPosition(array_elements[i].x, array_elements[i].y);
	}
}
//Drawing elements
void Draw_menu_elements(Menu_elements element, RenderWindow &window)
{
	window.draw(element.text);
}
//Looping menu

//Moving between elements
void Moving_between_elements(int& active_element, Clock &moving_elements_c,  Time moving_elements_t)
{
	moving_elements_t = moving_elements_c.getElapsedTime();
	if (Keyboard::isKeyPressed(Keyboard::Up) || Keyboard::isKeyPressed(Keyboard::W))
	{
		if (moving_elements_t.asSeconds() > 0.15)
		{
			active_element--;
			switch (active_element)
			{
			case -1:
				active_element = 3;
				break;
			}
			moving_elements_t = moving_elements_c.restart();
		}
	}
	else if (Keyboard::isKeyPressed(Keyboard::Down) || Keyboard::isKeyPressed(Keyboard::S))
	{
		if (moving_elements_t.asSeconds() > 0.15)
		{
			active_element++;
			switch (active_element)
			{
			case 4:
				active_element = 0;
				break;
			}
			moving_elements_t = moving_elements_c.restart();
		}
	}
}
void Setting_menu(RenderWindow &window);
void Game_loop(RenderWindow &window);

void Keyboard_main(int active_element, RenderWindow &window, Menu_elements menu_game_logo, Menu_elements menu_elements_array[4], bool &menu_active_bool, Clock &enter_press_c)
{
	Time enter_press_t;
	enter_press_t = enter_press_c.getElapsedTime();

	if (Keyboard::isKeyPressed(Keyboard::Enter) && enter_press_t.asSeconds()>0.15)
	{
		switch (active_element)
		{
		case 0:
			menu_active_bool = false;
			enter_press_c.restart();
			break;

		case 1:
			enter_press_c.restart();
			break;

		case 2:
			//delete menu_elements_array;
			Setting_menu(window);
			enter_press_c.restart();
			break;

		case 3:
			window.close();
			enter_press_c.restart();
			break;

		}
	}

}

