#pragma once
int COLOR_RED_1 = 0, COLOR_GREEN_1 = 0, COLOR_BLUE_1 = 0;
int COLOR_RED_2 = 0, COLOR_GREEN_2 = 0, COLOR_BLUE_2 = 0;
int COLOR_RED_3 = 0, COLOR_GREEN_3 = 0, COLOR_BLUE_3 = 0;
string GAME_BACKGROUND = "Images/background_1.png";
bool GAME_SHIELDS = false;
bool GAME_SOUND = false;
string CONTROLS = "";
int setting_wait = 0, change = 0;


string string_to_catch = "";
int backspace = 2;


class Colors_elements
{
public:
	Font font; Text text; int x, y;
	Colors_elements(Font font_c, Text text_c, int x_c, int y_c)
	{
		font = font_c;
		text = text_c;
		x = x_c;
		y = y_c;
	}
	Colors_elements() {}
};

class Colors_sprite
{
public:
	Texture texture; Sprite sprite; int x, y;
	Colors_sprite(Texture texture_c, Sprite sprite_c, int x_c, int y_c)
	{
		texture = texture_c;
		sprite = sprite_c;
		x = x_c;
		y = y_c;
	}
	Colors_sprite() {}
};
void Colors_sprite_parameters(Colors_sprite sprite[3])
{
	sprite[0].texture.loadFromFile("Images/alien_1_1.png");
	sprite[1].texture.loadFromFile("Images/alien_2_1.png");
	sprite[2].texture.loadFromFile("Images/alien_3_1.png");




	for (int i = 0; i < 3; i++)
	{
		sprite[i].y = 200;

		sprite[i].sprite.setTexture(sprite[i].texture);
		sprite[i].sprite.setScale(6.f, 6.f);
		int width = sprite[i].sprite.getLocalBounds().width;
		int b = width / 2;
		sprite[i].x = 320 - b*6;
		if (i == 1)
		{
			sprite[i].x += 320;
		}

		if (i == 2)
		{
			sprite[i].x += 640;
		}
		sprite[i].sprite.setPosition(sprite[i].x, sprite[i].y);
	}
	
}

void Colors_title_parameters(Colors_elements &element)
{
	element.font.loadFromFile("Fonts/joystix monospace.ttf");
	element.text.setFont(element.font);
	element.text.setString("CHOOSE COLORS (RGB)");
	element.text.setCharacterSize(36);
	element.text.setFillColor(Color::White);
	
	int width = element.text.getLocalBounds().width;
	int b = width / 2;
	element.x = 640 - b;
	element.y = 80;
	element.text.setPosition(element.x, element.y);
}

void Colors_elements_parameters(Colors_elements array[3][3], Colors_elements array_add[2])
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			array[i][j].font.loadFromFile("Fonts/joystix monospace.ttf");
			array[i][j].text.setFont(array[i][j].font);
			array[i][j].text.setCharacterSize(36);
			array[i][j].text.setFillColor(Color::White);
			array[i][j].x = 0;
			array[i][j].y = 350;

			if (i == 0)
				array[i][j].x += 320;
			

			if (i == 1)
				array[i][j].x += 640;

			if (i == 2)
				array[i][j].x += 960;

			if (j == 0)
			{
				array[i][j].text.setString("R: ");
				array[i][j].y += 40;
			}

			if (j == 1)
			{
				array[i][j].text.setString("G: ");
				array[i][j].y += 100;
			}

			if (j == 2)
			{
				array[i][j].text.setString("B: ");
				array[i][j].y += 160;

			}
			array[i][j].x -= 70;
			//array[i][j].y = 340;

			array[i][j].text.setPosition(array[i][j].x, array[i][j].y);
		}
	}
	array_add[0].text.setString("EXIT");
	array_add[1].text.setString("SAVE");

	for (int i = 0; i < 2; i++)
	{
		array_add[i].font.loadFromFile("Fonts/joystix monospace.ttf");
		array_add[i].text.setFont(array_add[i].font);
		array_add[i].text.setCharacterSize(36);
		array_add[i].text.setFillColor(Color::White);
		int width = array_add[i].text.getLocalBounds().width;
		int b = width / 2;
		array_add[i].x = 427 - b + i * 427;
		array_add[i].y = 600;
		array_add[i].text.setPosition(array_add[i].x, array_add[i].y);
	}

}
void Data_to_array()
{
	ifstream plik("parameters.txt");
	
	string dane;


	for (int i = 0; i < 9; i++)
	{
		getline(plik, dane);
		switch (i)
		{
		case 0:
			COLOR_RED_1 = stoi(dane);
			break;
			
		case 1:
			COLOR_GREEN_1 = stoi(dane);
			break;

		case 2:
			COLOR_BLUE_1 = stoi(dane);
			break;

		case 3:
			COLOR_RED_2 = stoi(dane);
			break;

		case 4:
			COLOR_GREEN_2 = stoi(dane);
			break;

		case 5:
			COLOR_BLUE_2 = stoi(dane);
			break;

		case 6:
			COLOR_RED_3 = stoi(dane);
			break;

		case 7:
			COLOR_GREEN_3 = stoi(dane);
			break;

		case 8:
			COLOR_BLUE_3 = stoi(dane);
			break;
		}
	}
	plik.close();
}
void Colors_elements_parameters_actu(Colors_elements array[3][3], Colors_elements array_add[2])
{
	for (int i = 0; i < 9; i++)
	{
		switch (i)
		{
		case 0:
			array[0][0].text.setString("R: "+ to_string(COLOR_RED_1));
			break;

		case 1:
			array[0][1].text.setString("G: " + to_string(COLOR_GREEN_1));
			break;

		case 2:
			array[0][2].text.setString("B: " + to_string(COLOR_BLUE_1));
			break;

		case 3:
			array[1][0].text.setString("R: " + to_string(COLOR_RED_2));
			break;

		case 4:
			array[1][1].text.setString("G: " + to_string(COLOR_GREEN_2));
			break;

		case 5:
			array[1][2].text.setString("B: " + to_string(COLOR_BLUE_2));
			break;

		case 6:
			array[2][0].text.setString("R: " + to_string(COLOR_RED_3));
			break;

		case 7:
			array[2][1].text.setString("G: " + to_string(COLOR_GREEN_3));
			break;

		case 8:
			array[2][2].text.setString("B: " + to_string(COLOR_BLUE_3));
			break;

		}
	
	}
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			array[i][j].text.setFillColor(Color::White);
			array[i][j].text.setCharacterSize(36);
		}
		for (int i = 0; i < 2; i++)
		{
			array_add[i].text.setFillColor(Color::White);
			array_add[i].text.setCharacterSize(36);
		}
		array_add[0].text.setString("EXIT");
		array_add[1].text.setString("SAVE");
	}
}
void Colors_active_element(Colors_elements array[3][3],Colors_elements array_add[2], int& active_x, int& active_y, RenderWindow& window)
{
	window.setFramerateLimit(8);
	if (Keyboard::isKeyPressed(Keyboard::Up))
	{
		active_y -= 1;
		string_to_catch = "";
		switch (active_y)
		{
		case -1:
			active_y = 3;
			break;
		}
	}
	if (Keyboard::isKeyPressed(Keyboard::Down))
	{
		active_y += 1;
		string_to_catch = "";
		switch (active_y)
		{
		case 4:
			active_y = 0;
			break;
		}
		if (active_y == 3 && active_x == 2)
			active_x = 1;
	}

	if (Keyboard::isKeyPressed(Keyboard::Left))
	{
		if (active_y == 3)
		{
			active_x -= 1;
			switch (active_x)
			{
			case -1:
				active_x = 1;
			}
		}
		else
		{
			active_x -= 1;
			string_to_catch = "";

			switch (active_x)
			{
			case -1:
				active_x = 2;
				break;
			}
		}
	}

	if (Keyboard::isKeyPressed(Keyboard::Right))
	{
		if (active_y == 3)
		{
			active_x += 1;

			switch (active_x)
			{
			case 2:
				active_x = 0;
				break;
			case 3:
				active_x = 0;
				break;
			}
		}

		else
		{
			active_x += 1;
			string_to_catch = "";

			switch (active_x)
			{
			case 3:
				active_x = 0;
				break;
			}
		}
	}
	if (active_x < 3 && active_y < 3)
	{
		array[active_x][active_y].text.setFillColor(Color(162, 162, 162));
		array[active_x][active_y].text.setCharacterSize(38);
		int left = array[active_x][active_y].text.getLocalBounds().width;
		int top = array[active_x][active_y].text.getLocalBounds().height;
	}
	
	if (active_y == 3)
	{
		array_add[active_x].text.setFillColor(Color(162, 162, 162));
		array_add[active_x].text.setCharacterSize(38);
	}
		

	
}

void Drawing_elements(RenderWindow &window,Colors_elements array[3][3], Colors_elements array_add[2], int active_x, int active_y)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if(i != active_x || j != active_y)
				window.draw(array[i][j].text);

			if (i == active_x && j == active_y)
			{
				string text = array[active_x][active_y].text.getString();
				string text_2 = ">" + text;
				array[active_x][active_y].x -= 33;
				array[active_x][active_y].text.setString(text_2);
				array[active_x][active_y].text.setPosition(array[active_x][active_y].x, array[active_x][active_y].y);
				window.draw(array[i][j].text);
			}
		}
	}
	if (active_y == 3 && active_x == 0)
	{
		string bufor = array_add[0].text.getString();
		array_add[0].text.setString(">" + bufor);
		array_add[0].x -= 30;
		array_add[0].text.setPosition(array_add[0].x, array_add[0].y);
	}

	if (active_y == 3 && active_x == 1)
	{
		string bufor = array_add[1].text.getString();
		array_add[1].text.setString(">" + bufor);
		array_add[1].x -= 30;
		array_add[1].text.setPosition(array_add[1].x, array_add[1].y);
	}

	for (int i = 0; i < 2; i++)
	{
		window.draw(array_add[i].text);
	}
}

void Colors_changing_value_active_element_co_worker(RenderWindow &window,Colors_elements array[3][3], int &color_rgb, Event& event_2)
{

	int input = 0;
	string string_array[3];
	Text text;
	Font font;
	font.loadFromFile("Fonts/joystix monospace.ttf");
	bool loop = true;

	int size = 0;
	size = string_to_catch.size();

		if (event_2.type == Event::TextEntered && string_to_catch.size() < 3)
		{
			if (string_to_catch == "0")
			{
				string_to_catch = "";
			}
			string_array[size] = event_2.text.unicode;
			const char* char_catch = string_array[size].c_str();
			if (*char_catch < 48 || *char_catch > 57)
			{
				if (!Keyboard::isKeyPressed(Keyboard::Enter))
				{
					evil_enter = true;
				}
				else
				{
					string_array[size] = "0";
				}

			}
			if (evil_enter != true)
			{
				string_to_catch += string_array[size];
				size = string_to_catch.size();

				if (Keyboard::isKeyPressed(Keyboard::BackSpace))
				{
					int a = 0;
					string_to_catch = to_string(a);

				}
			}

		
	}
	


	if (evil_enter != true)
	{
		if (string_to_catch.size() > 0 && string_to_catch != "")
		{
			if (stoi(string_to_catch) > 255)
			{
				color_rgb = 255;
			}

			else if (stoi(string_to_catch) < 0)
			{
				color_rgb = 0;
			}
			else
			{
				color_rgb = atoi(string_to_catch.c_str()); //bo stoi() pizga jakimiœ dziwnymi wyj¹tkami
			}
		}
	}


}

void Colors_changing_value_active_element(RenderWindow &window,Colors_elements array[3][3], int active_x, int active_y, Event &event_2)
{

	if (active_x == 0 && active_y == 0)
		Colors_changing_value_active_element_co_worker(window, array, COLOR_RED_1, event_2);
	else if (active_x == 0 && active_y == 1)
		Colors_changing_value_active_element_co_worker(window, array, COLOR_GREEN_1, event_2);
	else if (active_x == 0 && active_y == 2)
		Colors_changing_value_active_element_co_worker(window, array, COLOR_BLUE_1, event_2);

	else if (active_x == 1 && active_y == 0)
		Colors_changing_value_active_element_co_worker(window, array, COLOR_RED_2, event_2);
	else if (active_x == 1 && active_y == 1)
		Colors_changing_value_active_element_co_worker(window, array, COLOR_GREEN_2, event_2);
	else if (active_x == 1 && active_y == 2)
		Colors_changing_value_active_element_co_worker(window, array, COLOR_BLUE_2, event_2);

	else if (active_x == 2 && active_y == 0)
		Colors_changing_value_active_element_co_worker(window, array, COLOR_RED_3, event_2);
	else if (active_x == 2 && active_y == 1)
		Colors_changing_value_active_element_co_worker(window, array, COLOR_GREEN_3, event_2);
	else if (active_x == 2 && active_y == 2)
		Colors_changing_value_active_element_co_worker(window, array, COLOR_BLUE_3, event_2);
	
	
}
void Saving_to_file(bool &menu_loop)
{
	
	
		ofstream plik("parameters.txt");

		string dane;


		for (int i = 0; i < 9; i++)
		{
			switch (i)
			{
			case 0:
				plik << COLOR_RED_1 << endl;
				break;

			case 1:
				plik << COLOR_GREEN_1 << endl;
				break;

			case 2:
				plik << COLOR_BLUE_1 << endl;
				break;

			case 3:
				plik << COLOR_RED_2 << endl;
				break;

			case 4:
				plik << COLOR_GREEN_2 << endl;
				break;

			case 5:
				plik << COLOR_BLUE_2 << endl;
				break;

			case 6:
				plik << COLOR_RED_3 << endl;
				break;

			case 7:
				plik << COLOR_GREEN_3 << endl;
				break;

			case 8:
				plik << COLOR_BLUE_3 << endl;
				break;
			}
		}
		plik.close();
		string_to_catch = to_string(COLOR_RED_1);
		menu_loop = false;
	
}

void Menu_colors_2_last_options(int active_x, int active_y, bool &menu_loop)
{
	if (Keyboard::isKeyPressed(Keyboard::Enter))
	{
		if (active_x == 0 && active_y == 3)
		{
			Data_to_array();
			menu_loop = false;
		}

		if (active_x == 1 && active_y == 3)
		{
			Saving_to_file(menu_loop);
			menu_loop = false;
		}
	}
}

void Colors(RenderWindow &window)
{
	bool menu_loop = true;

	void Closing_window(RenderWindow & window);
	Colors_sprite colors_sprite[3];

	Colors_elements title, array_elements[3][3], array_elements_add[2];

	int active_x = 0, active_y = 0;
	Colors_title_parameters(title);
	Colors_sprite_parameters(colors_sprite);
	Data_to_array();

	Colors_elements_parameters(array_elements, array_elements_add);
	Event event_2;
	Clock escape_press_c, enter_press_c;
	Time escape_press_t, enter_press_t;

	while (menu_loop != false && window.isOpen())
	{
		//Saving_to_file(menu_loop);
		window.clear(Color::Black);
		window.draw(title.text);
		colors_sprite[0].sprite.setColor(Color(COLOR_RED_1, COLOR_GREEN_1, COLOR_BLUE_1, 255));
		colors_sprite[1].sprite.setColor(Color(COLOR_RED_2, COLOR_GREEN_2, COLOR_BLUE_2, 255));
		colors_sprite[2].sprite.setColor(Color(COLOR_RED_3, COLOR_GREEN_3, COLOR_BLUE_3, 255));

		window.draw(colors_sprite[0].sprite);
		window.draw(colors_sprite[1].sprite);
		window.draw(colors_sprite[2].sprite);

		Colors_elements_parameters(array_elements, array_elements_add);
		Colors_elements_parameters_actu(array_elements, array_elements_add);
		Colors_active_element(array_elements,array_elements_add ,active_x, active_y, window);
		Menu_colors_2_last_options(active_x, active_y, menu_loop);
		Colors_changing_value_active_element(window, array_elements, active_x, active_y, event_2);
		Drawing_elements(window, array_elements, array_elements_add ,active_x, active_y);
		window.display();
		escape_press_t = escape_press_c.getElapsedTime();
		if (Keyboard::isKeyPressed(Keyboard::Escape) && escape_press_t.asSeconds() > 0.12)
		{
			Data_to_array();
			menu_loop = false;
			escape_press_c.restart();
		}
		Closing_window(window);
		evil_enter = false;
	}
}