// ConsoleApplication2.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <fstream>
#include <string>
#include <time.h>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "header_menu_class.h"
#include "header_colors.h"
#include "rest_of_menu_setting.h"
#include "header_settings.h"
#include "header_main_menu_class_helper.h"
#include "header_game_2.h"
#include "header_game_loop.h"

using namespace std;
using namespace sf;


void Main_menu_loop(RenderWindow &window)
{
	
	void Data_to_array();
	Data_to_array();
	int active_element = 0;
	const int main_menu_elements = 4;

	Menu_elements menu_game_logo; //logo of game
	Logo_class_parameters(menu_game_logo);

	Menu_elements menu_elements_array[main_menu_elements]; //array of menu elements
	Clock moving_elements_c; 
	Clock enter_press_c;
	Time moving_elements_t = moving_elements_c.getElapsedTime();

	int initial_height = 250, spacing = 100;
	bool menu_active_bool = true;
	while (window.isOpen() && menu_active_bool == true)
	{
		Draw_menu_elements(menu_game_logo, window);
		Moving_between_elements(active_element, moving_elements_c, moving_elements_t);
		Names_for_main_menu(menu_elements_array);
		Array_class_parameters(menu_elements_array, active_element, main_menu_elements, initial_height, spacing);
		for (int i = 0; i < 4; i++)
		{
			Draw_menu_elements(menu_elements_array[i], window);
			window.draw(menu_elements_array[i].text);
		}
		Keyboard_main(active_element, window, menu_game_logo, menu_elements_array, menu_active_bool, enter_press_c);
		window.display();
		Closing_window(window);
		window.clear(Color::Black);
	}
}


int main()
{

	RenderWindow window(VideoMode(1280,720), "Space Invadors");
	window.setFramerateLimit(60);
	Main_menu_loop(window); //main menu loop
	Game_loop(window);
	

	cout << "Zamknieto okno" << endl;
	return 2137;
	//Main jest tylko i wyłącznie po to żeby był :)
}

// Uruchomienie programu: Ctrl + F5 lub menu Debugowanie > Uruchom bez debugowania
// Debugowanie programu: F5 lub menu Debugowanie > Rozpocznij debugowanie

// Porady dotyczące rozpoczynania pracy:
//   1. Użyj okna Eksploratora rozwiązań, aby dodać pliki i zarządzać nimi
//   2. Użyj okna programu Team Explorer, aby nawiązać połączenie z kontrolą źródła
//   3. Użyj okna Dane wyjściowe, aby sprawdzić dane wyjściowe kompilacji i inne komunikaty
//   4. Użyj okna Lista błędów, aby zobaczyć błędy
//   5. Wybierz pozycję Projekt > Dodaj nowy element, aby utworzyć nowe pliki kodu, lub wybierz pozycję Projekt > Dodaj istniejący element, aby dodać istniejące pliku kodu do projektu
//   6. Aby w przyszłości ponownie otworzyć ten projekt, przejdź do pozycji Plik > Otwórz > Projekt i wybierz plik sln
