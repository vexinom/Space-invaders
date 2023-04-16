#pragma once
bool change_down_global = false;
int score = 0;




void Collision(Aliens* wsk[], Bullet* wsk_bullet)
{
	for (int i = 0; i < 55; i++)
	{
		if (wsk[i] != nullptr)
		{
			if (wsk_bullet->x_pos >= wsk[i]->x_pos && wsk_bullet->x_pos <= wsk[i]->x_pos + 60 && wsk_bullet->y_pos <= wsk[i]->y_pos + 44 && wsk_bullet->y_pos >= wsk[i]->y_pos)
			{
				wsk_bullet->x_pos = -40;
				wsk_bullet->y_pos = -40;
				wsk_bullet->rectangle.setPosition(wsk_bullet->x_pos, wsk_bullet->y_pos);
				score = score + wsk[i]->score;
				delete wsk[i];
				wsk[i] = nullptr;

			}
		}
	}
}
void Check_if_winning(Aliens* wsk[56], bool &game_loop)
{
	int j = 0;
	for (int i = 0; i < 55; i++)
	{
		if (wsk[i] == nullptr)
		{
			j++;
			continue;
		}
	}
	if (j == 55)
	{
		game_loop = false;
		cout << "Wygrana czy cos tam" << endl;
	}
}
void Losing_touching_by_alien(Aliens *wsk[55], bool &game_loop)
{
	for (int i = 0; i < 55; i++)
	{
		if (wsk[i] != nullptr)
		{
			if (wsk[i]->y_pos + 60 > 620)
			{
				game_loop = false;
				cout << "Przegrana" << endl;
				break;
			}
		}
	}
}

void Set_pointer_with_objects(Aliens* wsk[55])
{
	for (int i = 0; i < 55; i++)
	{
		wsk[i] = new Aliens;
	}
}

void Set_pointer_to_object(Bullet* bullet)
{
	RectangleShape rectangle;
	bullet = new Bullet(rectangle, 6, 20, 0, 0);
}

void Text_setting( Text &text)
{
	text.setCharacterSize(40);
	text.setString("SCORE");
	text.setPosition(10, 0);
	text.setFillColor(Color::White);
}

void Text_life(Text& text)
{
	int b = life;
	string str = to_string(b);
	text.setCharacterSize(40);
	text.setString("LIFE " + str);
	text.setPosition(1000, 0);
	text.setFillColor(Color::White);

}

void Converting_score_to_string(RenderWindow &window, Text &text_score)
{
	int a = score;
	string str = to_string(a);
	text_score.setString("SCORE " + str);
	window.draw(text_score);
}
void Changing_speed_of_aliens(Aliens * array[], int &sub_alien_move, int speed)
{
	int c = 0;
	for (int i = 0; i < 55; i++)
	{
		if (array[i] == nullptr)
		{
			c++;
		}
	}
	if (c > 10)
	{
		sub_alien_move = 29;
		speed = 1;
	}
	if (c > 17)
	{
		sub_alien_move = 26;
		speed = 3;
	}
	if (c > 25)
	{
		sub_alien_move = 21;
		speed = 9;
	}
	if (c > 35)
	{
		sub_alien_move = 17;
		speed = 13;
	}
	if (c > 45)
	{
		sub_alien_move = 13;
		speed = 17;
	}
	if (c > 52)
	{
		sub_alien_move = 9;
		speed = 23;
	}
}

void Game_loop(RenderWindow& window)
{
	//additional element in array to manage it
	window.setFramerateLimit(60);

	Aliens* wsk[56];
	int magnitude_x = 1;
	Set_pointer_with_objects(wsk);
	wsk[55]->Data_to_RectangleShape(wsk);
	wsk[55]->Array_parameters(wsk);

	Texture texture_11, texture_12, texture_21, texture_22, texture_31, texture_32, texture_background;
	Sprite sprite_background;
	texture_background.loadFromFile(GAME_BACKGROUND);
	sprite_background.setTexture(texture_background);
	sprite_background.setPosition(0, 0);
	sprite_background.setColor(Color(150,150,150));
	texture_11.loadFromFile("Images/alien_1_1.png");

	texture_12.loadFromFile("Images/alien_1_2.png");
	texture_21.loadFromFile("Images/alien_2_1.png");
	texture_22.loadFromFile("Images/alien_2_2.png");
	texture_31.loadFromFile("Images/alien_3_1.png");
	texture_32.loadFromFile("Images/alien_3_2.png");
	
	wsk[55]->Sprite_setting(wsk, texture_11, texture_21, texture_31);
	

	Bullet* bullet = new Bullet;
	//Set_pointer_to_object(bullet);
	bullet->Bullet_parameters(bullet);

	Player player;
	player.Setting_parameters(player);

	Font font;
	font.loadFromFile("Fonts/joystix monospace.ttf");

	Text text_score;
	Text text_life;
	text_score.setFont(font);
	text_life.setFont(font);
	Text_setting(text_score);
	


	bool game_loop = true;
	int change_texture = 0;
	int movement_of_aliens = 0;
	int sub_alien_move = 34, speed = 0;

	wsk[55]->Positioning_array(wsk, magnitude_x, speed);

	vector <Alien_bullets> array_alien_bullets;

	while (window.isOpen() && game_loop == true)
	{

		Check_if_winning(wsk, game_loop);
		Losing_touching_by_alien(wsk, game_loop);
		window.clear(Color::Black);
		window.draw(sprite_background);
		Text_life(text_life);
		window.draw(text_life);
		Converting_score_to_string(window, text_score);
		Closing_window(window);
		Changing_speed_of_aliens(wsk, sub_alien_move, speed);

		if (movement_of_aliens % sub_alien_move == 0)
		{
			wsk[55]->Positioning_array(wsk, magnitude_x, speed);
			movement_of_aliens = 0;

			if (change_texture % 2 == 1)
				wsk[55]->Sprite_setting(wsk, texture_11, texture_21, texture_31);
			if (change_texture % 2 == 0)
				wsk[55]->Sprite_setting(wsk, texture_12, texture_22, texture_32);

			change_texture++;
		}

		player.Moving_player(player);
		player.Shooting(player, bullet);
		Alien_bullets_managing(window, array_alien_bullets, wsk, movement_of_aliens, player, game_loop);

		if (bullet != nullptr)
		{
			bullet->Positioning_bullet(bullet);
			Collision(wsk, bullet);
			window.draw(bullet->rectangle);
		}
		window.draw(player.sprite);

		for (int i = 0; i < 55; i++)
		{
			if (wsk[i] != nullptr)
			{
				window.draw(wsk[i]->rectangle);
				window.draw(wsk[i]->sprite);
			}
		}
		window.display();
		movement_of_aliens++;
	}
}