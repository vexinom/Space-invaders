#pragma once
#include "header_main_menu_class_helper.h"


void Names_for_setting_menu(Menu_elements array[7])
{
	array[0].text.setString("COLORS"); //colors of aliens and 
	array[1].text.setString("BACKGROUND");
	array[2].text.setString("SHIELDS");
	array[3].text.setString("SOUND");
	array[4].text.setString("CONTROLS");
	array[5].text.setString("RESET TO DEFAULT SETTINGS");
	array[6].text.setString("BACK TO MAIN MENU");
}
void Moving_between_elements_setting( int& active_element, Clock &setting_menu_c)
{
	Time setting_menu_t = setting_menu_c.getElapsedTime();

	if (Keyboard::isKeyPressed(Keyboard::Up) || Keyboard::isKeyPressed(Keyboard::W))
	{
		if (setting_menu_t.asSeconds() > 0.15)
		{
			active_element--;
			switch (active_element)
			{
			case -1:
				active_element = 6;
				break;
			}
			setting_menu_c.restart();
		}
	}
	else if (Keyboard::isKeyPressed(Keyboard::Down) || Keyboard::isKeyPressed(Keyboard::S))
	{
		if (setting_menu_t.asSeconds() > 0.15)
		{
			active_element++;
			switch (active_element)
			{
			case 7:
				active_element = 0;
				break;
			}
			setting_menu_c.restart();
		}
	}
}

void Keyboard_main_settings(int active_element, RenderWindow &window, bool & return_to_main_menu, Clock &enter_press_c, Clock &escape_press_c)
{
	Time enter_press_t = enter_press_c.getElapsedTime();
	if (Keyboard::isKeyPressed(Keyboard::Enter) && enter_press_t.asSeconds()>0.15)
	{
		setting_wait++;
		if (setting_wait == 2)
		{
			setting_wait = 0;
			switch (active_element)
			{
			case 0:
				Colors(window);
				enter_press_c.restart();
				escape_press_c.restart();
				break;

			case 1:
				setting_background(window);
				enter_press_c.restart();
				escape_press_c.restart();
				break;

			case 2:
				enter_press_c.restart();
				escape_press_c.restart();
				break;

			case 3:
				enter_press_c.restart();
				escape_press_c.restart();
				break;

			case 4:
				enter_press_c.restart();
				escape_press_c.restart();
				break;

			case 5:
				enter_press_c.restart();
				escape_press_c.restart();
				break;

			case 6:
				return_to_main_menu = false;
				enter_press_c.restart();
				escape_press_c.restart();
				break;


			}
		}
	}

}

void Setting_menu(RenderWindow &window)
{
	window.setFramerateLimit(60);
	const int setting_menu_elements = 7;
	Menu_elements array[setting_menu_elements];

	Clock setting_menu_c, enter_press_c, escape_press_c;
	Time escape_press_t;
	int active_elemeny_setting = 0, initial_height = 100, spacing = 75;
	bool return_to_main_menu = true;
	while (window.isOpen() && return_to_main_menu == true)
	{
		Names_for_setting_menu(array);
		Moving_between_elements_setting(active_elemeny_setting, setting_menu_c);
		Array_class_parameters(array, active_elemeny_setting, setting_menu_elements, initial_height, spacing);
		window.clear(Color::Black);
		for (int i = 0; i < 7; i++)
		{
			Draw_menu_elements(array[i], window);
			window.draw(array[i].text);
		}
		escape_press_t = escape_press_c.getElapsedTime();
		if (Keyboard::isKeyPressed(Keyboard::Escape) && escape_press_t.asSeconds() > 0.2)
		{
			return_to_main_menu = false;
			escape_press_c.restart();
		}

		Keyboard_main_settings(active_elemeny_setting, window, return_to_main_menu, enter_press_c, escape_press_c);
		Closing_window(window);
		window.display();
		//break;
	}
}
