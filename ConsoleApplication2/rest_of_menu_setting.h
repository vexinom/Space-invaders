#pragma once

class Background_sprite
{
public:
	Texture texture;
	Sprite sprite;
	RectangleShape rectangle;
	int x, y;
	Background_sprite(Texture texture_c, Sprite sprite_c, RectangleShape rectangle_c, int x_c, int y_c)
	{
		texture = texture_c;
		x = x_c;
		y = y_c;
		sprite = sprite_c;
		rectangle = rectangle_c;
	}
	Background_sprite() {}
};

class Background_text
{
public:
	Text text;
	Font font;
	int x, y;
	Background_text(Text text_c,Font font_c, int x_c, int y_c)
	{
		text = text_c;
		x = x_c;
		y = y_c;
		font = font_c;
	}
	Background_text() {}
};
void Background_parameters_title(Background_text* title_bc)
{
	title_bc->font.loadFromFile("Fonts/joystix monospace.ttf");
	title_bc->text.setFont(title_bc->font);
	title_bc->text.setCharacterSize(36);
	title_bc->text.setFillColor(Color::White);
	title_bc->text.setString("CHOOSE BACKGROUND");
	int width = title_bc->text.getLocalBounds().width;
	int b = width / 2;
	title_bc->x = 640 -b;
	title_bc->y = 80;
	title_bc->text.setPosition(title_bc->x, title_bc->y);
}

void Background_parameters_elements(Background_text element_bc[2])
{
	element_bc[0].text.setString("EXIT");
	element_bc[1].text.setString("SAVE");

	for (int i = 0; i < 2; i++)
	{
		element_bc[i].font.loadFromFile("Fonts/joystix monospace.ttf");
		element_bc[i].text.setFont(element_bc[i].font);
		element_bc[i].text.setCharacterSize(36);
		element_bc[i].text.setFillColor(Color::White);
		int width = element_bc[i].text.getLocalBounds().width;
		int b = width / 2;
		element_bc[i].x = 427 - b + 427*i;
		element_bc[i].y = 600;
		element_bc[i].text.setPosition(element_bc[i].x, element_bc[i].y);
	}
}

void Background_settings_sprites(Background_sprite** sprite_bc)
{
	sprite_bc[0][0].texture.loadFromFile("Images/background_1.png");
	sprite_bc[0][1].texture.loadFromFile("Images/background_2.png");
	sprite_bc[0][2].texture.loadFromFile("Images/background_3.png");
	sprite_bc[1][0].texture.loadFromFile("Images/background_4.png");
	sprite_bc[1][1].texture.loadFromFile("Images/background_5.png");
	sprite_bc[1][2].texture.loadFromFile("Images/background_2.png");

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			sprite_bc[i][j].sprite.setTexture(sprite_bc[i][j].texture);
			sprite_bc[i][j].sprite.setScale(0.2, 0.2);
			int width = sprite_bc[i][j].sprite.getLocalBounds().width;
			int b = (width / 2) * 0.2;
			if (j == 0)
			{
				sprite_bc[i][j].x = 320 - b;
			}
			if (j == 1)
			{
				sprite_bc[i][j].x = 320 - b + 320;
			}
			if (j == 2)
			{
				sprite_bc[i][j].x = 320 - b + 320 + 320;
			}

			sprite_bc[i][j].y = 175;
			if (i == 1)
			{
				sprite_bc[i][j].y = 365;
			}
			sprite_bc[i][j].rectangle.setSize(Vector2f(256, 144));
			sprite_bc[i][j].rectangle.setOutlineThickness(3);
			sprite_bc[i][j].rectangle.setOutlineColor(sf::Color(255, 255, 255, 30));
			sprite_bc[i][j].sprite.setPosition(sprite_bc[i][j].x, sprite_bc[i][j].y);
			sprite_bc[i][j].rectangle.setPosition(sprite_bc[i][j].x, sprite_bc[i][j].y);
			sprite_bc[i][j].rectangle.setFillColor(sf::Color(0, 0, 0, 0));
		}
	}
}

void Switching_elements(int &active_element_x, int &active_element_y, Clock &c_button_press, Time &t_button_press)
{
	t_button_press = c_button_press.getElapsedTime();
	//t_button_press = c_button_press.restart();

	if (Keyboard::isKeyPressed(Keyboard::Up) && t_button_press.asSeconds() > 0.15)
	{
		active_element_y--;
		switch (active_element_y)
		{
		case -1:
			active_element_y = 2;
			break;
		}
		t_button_press = c_button_press.restart();
	}

	if (Keyboard::isKeyPressed(Keyboard::Down) && t_button_press.asSeconds() > 0.15)
	{
		active_element_y++;
		switch (active_element_y)
		{
		case 3:
			active_element_y = 0;
			break;
		}
		t_button_press = c_button_press.restart();
	}

	if (Keyboard::isKeyPressed(Keyboard::Left) && t_button_press.asSeconds() > 0.15)
	{
		active_element_x--;
		switch (active_element_x)
		{
		case -1:
			active_element_x = 2;
			break;
		}
		t_button_press = c_button_press.restart();
	}

	if (Keyboard::isKeyPressed(Keyboard::Right) && t_button_press.asSeconds() > 0.15)
	{
		active_element_x++;
		switch (active_element_x)
		{
		case 3:
			active_element_x = 0;
			break;
		}
		t_button_press = c_button_press.restart();
	}
	if (active_element_y == 2 && active_element_x == 2)
	{
		active_element_x = 1;
	}
}

void Adjusting_element(int active_element_x, int active_element_y, Background_text* element_bc, Background_sprite** sprite_bc, int active_element_x_bc, int active_element_y_bc)
{

	//if (active_element_y != 2)
	{
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (i == active_element_y && j == active_element_x)
				{
					sprite_bc[i][j].rectangle.setOutlineColor(Color(255, 255, 255, 140));
					sprite_bc[i][j].rectangle.setOutlineThickness(6);

				}
				else
				{
					{
						sprite_bc[i][j].rectangle.setOutlineThickness(3);
						sprite_bc[i][j].rectangle.setOutlineColor(sf::Color(255, 255, 255, 50));
					}
				}
			}
		}
	}
	for (int i = 0; i < 2; i++)
	{
		element_bc[i].text.setCharacterSize(36);
	}

	if (active_element_y == 2)
	{

		switch (active_element_x)
		{
		case 0:
			element_bc[active_element_x].text.setCharacterSize(40);
			break;

		case 1:
			element_bc[active_element_x].text.setCharacterSize(40);
			break;

		}
	}
}

void Choosing_background(int active_element_x, int active_element_y)
{
	if (Keyboard::isKeyPressed(Keyboard::Enter))
	{
		if (active_element_x == 0 && active_element_y == 0)
		{
			GAME_BACKGROUND = "Images/background_1.png";
		}

		if (active_element_x == 1 && active_element_y == 0)
		{
			GAME_BACKGROUND = "Images/background_2.png";
		}

		if (active_element_x == 2 && active_element_y == 0)
		{
			GAME_BACKGROUND = "Images/background_3.png";
			cout << "ba" << endl;
		}

		if (active_element_x == 0 && active_element_y == 1)
		{
			GAME_BACKGROUND = "Images/background_4.png";
		}

		if (active_element_x == 1 && active_element_y == 1)
		{
			GAME_BACKGROUND = "Images/background_5.png";
		}

		if (active_element_x == 2 && active_element_y == 1)
		{
			GAME_BACKGROUND = "Images/background_1.png";
		}
	}
}
void Color_of_chosen_background(Background_sprite** bc_sprite, int& active_element_x_bc, int& active_element_y_bc, int active_element_x, int active_element_y)
{
	if (GAME_BACKGROUND == "Images/background_1.png")
	{
		bc_sprite[0][0].rectangle.setOutlineColor(Color(0, 255, 0, 100));
		bc_sprite[0][0].rectangle.setOutlineThickness(6);
		active_element_x_bc = 0;
		active_element_y_bc = 0;
	}

	if (GAME_BACKGROUND == "Images/background_2.png")
	{
		bc_sprite[0][1].rectangle.setOutlineColor(Color(0, 255, 0, 100));
		bc_sprite[0][1].rectangle.setOutlineThickness(6);
		active_element_x_bc = 1;
		active_element_y_bc = 0;
	}

	if (GAME_BACKGROUND == "Images/background_3.png")
	{
		bc_sprite[0][2].rectangle.setOutlineColor(Color(0, 255, 0, 100));
		bc_sprite[0][2].rectangle.setOutlineThickness(6);
		active_element_x_bc = 2;
		active_element_y_bc = 0;
	}

	if (GAME_BACKGROUND == "Images/background_4.png")
	{
		bc_sprite[1][0].rectangle.setOutlineColor(Color(0, 255, 0, 100));
		bc_sprite[1][0].rectangle.setOutlineThickness(6);
		active_element_x_bc = 0;
		active_element_y_bc = 1;
	}

	if (GAME_BACKGROUND == "Images/background_5.png")
	{
		bc_sprite[1][1].rectangle.setOutlineColor(Color(0, 255, 0, 100));
		bc_sprite[1][1].rectangle.setOutlineThickness(6);
		active_element_x_bc = 1;
		active_element_y_bc = 1;
	}

	//if (GAME_BACKGROUND == "Images/background_6.png")
	{
		//bc_sprite[0][0].rectangle.setOutlineColor(Color(0, 255, 0, 100));
		//active_element_x_bc = 2;
		//active_element_y_bc = 1;
	}
	if (active_element_x == active_element_x_bc && active_element_y == active_element_y_bc)
	{
		bc_sprite[active_element_y][active_element_x].rectangle.setOutlineColor(Color(153, 255, 151, 150));
		bc_sprite[active_element_y][active_element_x].rectangle.setOutlineThickness(6);
	}
}
void setting_background(RenderWindow &window)
{
	window.setFramerateLimit(60);
	Clock c_button_press;
	Time t_button_press = c_button_press.getElapsedTime();

	bool menu_background = true;
	Background_text* title_bc = new Background_text;
	Background_text* element_bc = new Background_text[2];

	Background_sprite** sprite_bc = new Background_sprite*[2];
	for (int i = 0; i < 2; i++)
	{
		sprite_bc[i] = new Background_sprite[3];
	}

	int active_element_x = 0, active_element_y = 0, last_x = 0, last_y = 0;
	int active_element_x_bc = 0, active_element_y_bc = 0;
	void Closing_window(RenderWindow &window);
	Background_parameters_title(title_bc);
	Background_parameters_elements(element_bc);
	Background_settings_sprites(sprite_bc);
	Clock escape_press_c;
	Time escape_press_t;

	while (window.isOpen() && menu_background == true)
	{
		window.clear(Color::Black);
		Closing_window(window);

		window.draw(title_bc->text);

		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				window.draw(sprite_bc[i][j].sprite);
				window.draw(sprite_bc[i][j].rectangle);
			}
		}
		window.draw(element_bc[0].text);
		window.draw(element_bc[1].text);
		window.display();
		Switching_elements(active_element_x, active_element_y, c_button_press, t_button_press);
		Choosing_background(active_element_x, active_element_y);
		Adjusting_element(active_element_x, active_element_y, element_bc, sprite_bc, active_element_x_bc, active_element_y_bc);
		Color_of_chosen_background(sprite_bc, active_element_x_bc, active_element_y_bc, active_element_x, active_element_y);

		escape_press_t = escape_press_c.getElapsedTime();
		if (Keyboard::isKeyPressed(Keyboard::Escape) && escape_press_t.asSeconds() > 0.2)
		{
			menu_background = false;
			escape_press_c.restart();
		}
	}
	delete [] sprite_bc;
	delete [] element_bc;
	delete title_bc;
}