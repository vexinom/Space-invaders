#pragma once
int life = 3;
int level = 1;

class Aliens
{
public:
	RectangleShape rectangle;
	Sprite sprite; Texture texture;
	float x = 46, y = 36, x_pos = 0, y_pos = 0;
	int magnitude_x = 1, score = 0;


	Aliens(RectangleShape rectangle_c, Sprite sprite_c, float x_c, float y_c, float x_pos_c, float y_pos_c, int magnitude_x_c, int score_c)
	{
		rectangle = rectangle_c;
		sprite = sprite_c;
		x = x_c;
		y = y_c;
		x_pos = x_pos_c;
		y_pos = y_pos_c;
		magnitude_x = magnitude_x_c;
		score = score_c;
	}

	Aliens() {}
	~Aliens() {}

	void Data_to_RectangleShape(Aliens* wsk[56])
	{

		for (int i = 0; i < 55; i++)
		{
			wsk[i]->rectangle.setSize(Vector2f(wsk[i]->x, wsk[i]->y));
			wsk[i]->rectangle.setFillColor(Color(255, 255, 255, 0));
			wsk[i]->rectangle.setPosition(Vector2f(wsk[i]->x_pos, wsk[i]->y_pos));

		}
	}


	void Array_parameters(Aliens* wsk[56])
	{
		for (int i = 0; i < 55; i++)
		{
			float a = 200, b = 80;
			for (int i = 0; i < 55; i++)
			{
				if (i % 11 == 0 && i != 0)
				{
					b = b + 68;
					a = 200;
				}
				wsk[i]->x_pos = a;
				a = a + 70;
				wsk[i]->y_pos = b;
				wsk[i]->rectangle.setPosition(wsk[i]->x_pos, wsk[i]->y_pos);
			}
		}
	}

	void Positioning_array(Aliens* wsk[56], int& magnitude_x, int speed)
	{
		bool change_down = false;
		int div = 1;

		for (int i = 0; i < 55; i++)
		{
			if (wsk[i] != nullptr)
			{
				if (wsk[i]->x_pos > 1149)
				{
					magnitude_x = -1;
					change_down = true;
					div = 2;
				}
				if (wsk[i]->x_pos < 71)
				{
					magnitude_x = 1;
					change_down = true;
					div = 2;
				}
			}
		}

		if (change_down == true)
		{
			for (int i = 0; i < 55; i++)
			{
				if (wsk[i] != nullptr)
					wsk[i]->y_pos = wsk[i]->y_pos + 10;
			}
		}

		for (int i = 0; i < 55; i++)
		{
			if (wsk[i] != nullptr)
			{
				switch (magnitude_x)
				{
				case 1:
					wsk[i]->x_pos = wsk[i]->x_pos + (6 + speed)/ div;
					break;

				case -1:
					wsk[i]->x_pos = wsk[i]->x_pos - (6 + speed) / div;
					break;
				}
				wsk[i]->rectangle.setPosition(wsk[i]->x_pos, wsk[i]->y_pos);
				wsk[i]->sprite.setPosition(wsk[i]->x_pos - 7, wsk[i]->y_pos - 2);
			}
		}
	}

	void Sprite_setting(Aliens* wsk[], Texture& texture_1, Texture& texture_2, Texture& texture_3)
	{
		for (int i = 0; i < 11; i++)
		{
			if (wsk[i] != nullptr)
			{
				wsk[i]->sprite.setTexture(texture_3);
				wsk[i]->sprite.setColor(Color(COLOR_RED_3, COLOR_GREEN_3, COLOR_BLUE_3, 255));
				wsk[i]->sprite.setScale(2, 2);
				wsk[i]->score = 50;
			}
		}
		for (int i = 11; i < 33; i++)
		{
			if (wsk[i] != nullptr)
			{
				wsk[i]->sprite.setColor(Color(COLOR_RED_2, COLOR_GREEN_2, COLOR_BLUE_2, 255));
				wsk[i]->sprite.setTexture(texture_2);
				wsk[i]->sprite.setScale(2, 2);
				wsk[i]->score = 20;
			}
		}
		for (int i = 33; i < 55; i++)
		{
			if (wsk[i] != nullptr)
			{
				wsk[i]->sprite.setColor(Color(COLOR_RED_1, COLOR_GREEN_1, COLOR_BLUE_1, 255));
				wsk[i]->sprite.setTexture(texture_1);
				wsk[i]->sprite.setScale(2, 2);
				wsk[i]->score = 10;
			}
		}
	}

};
class Bullet
{
public:
	RectangleShape rectangle;
	float x = 5, y = 20, x_pos = 0, y_pos = 0;

	void Bullet_parameters(Bullet* bullet);
	void Positioning_bullet(Bullet* bullet);

	Bullet(RectangleShape rectangle_c, float x_c, float y_c, float x_pos_c, float y_pos_c)
	{
		rectangle = rectangle_c;
		x = x_c;
		y = y_c;
		x_pos = x_pos_c;
		y_pos = y_pos_c;
	}
	Bullet() {}
	~Bullet()
	{

	}
};

class Player
{
public:
	float x_pos = 575, y_pos = 620;
	RectangleShape rectangle;
	Texture texture; Sprite sprite;
	//void Setting_parameters(Player &object);

	Player(RectangleShape rectangle_c, Texture texture_c, Sprite sprite_c, float x_pos_c, float y_pos_c)
	{
		rectangle = rectangle_c;
		texture = texture_c;
		sprite = sprite_c;
		x_pos = x_pos_c;
		y_pos = y_pos_c;
	}
	Player()
	{}

	void Setting_parameters(Player& object)
	{
		object.texture.loadFromFile("Images/player.png", IntRect(0, 0, 130, 80));
		object.sprite.setTexture(object.texture);
		object.sprite.setColor(Color(0, 255, 0));
		sprite.setScale(0.7, 0.7);
		object.sprite.setPosition(object.x_pos, object.y_pos);

	}

	void Moving_player(Player& object)
	{
		if (Keyboard::isKeyPressed(Keyboard::Right) && object.x_pos <= 1140)
		{
			object.x_pos = object.x_pos + 4;
		}

		if (Keyboard::isKeyPressed(Keyboard::Left) && object.x_pos >= 10)
		{
			object.x_pos = object.x_pos - 4;
		}
		object.sprite.setPosition(object.x_pos, object.y_pos);
	}
	void Shooting(Player& object, Bullet* bullet)
	{
		if (Keyboard::isKeyPressed(Keyboard::Space))
		{
			if (bullet->y_pos < 0)
			{
				bullet->y_pos = object.y_pos + 10;
				bullet->x_pos = object.x_pos + 62*0.7; //scale of player sprite
				bullet->rectangle.setPosition(bullet->x_pos, bullet->y_pos);
			}
		}
	}
};

void Bullet::Bullet_parameters(Bullet* bullet_wsk)
{
	if (bullet_wsk != nullptr)
	{
		bullet_wsk->rectangle.setSize(Vector2f(bullet_wsk->x, bullet_wsk->y));
		bullet_wsk->rectangle.setFillColor(Color::White);
	}
}
void Bullet::Positioning_bullet(Bullet* bullet_wsk)
{
	if (bullet_wsk->x_pos > -20)
	{
		bullet_wsk->y_pos = bullet_wsk->y_pos - 8;
		bullet_wsk->rectangle.setPosition(bullet_wsk->x_pos, bullet_wsk->y_pos);
	}

}

class Alien_bullets
{
public:
	RectangleShape rectangle;
	float x = 4, y = 14, x_pos, y_pos;
	Alien_bullets(RectangleShape rectangle_c, float x_c, float y_c, float x_pos_c, float y_pos_c)
	{
		rectangle = rectangle_c;
		x = x_c;
		y = y_c;
		x_pos = x_pos_c;
		y_pos = y_pos_c;
	}

	Alien_bullets() {}
	~Alien_bullets() {}
};
void Alien_bullets_parameters(Alien_bullets &bullet_object, Aliens * alien_object)
{
	bullet_object.rectangle.setFillColor(Color::White);
	bullet_object.rectangle.setSize(Vector2f(bullet_object.x, bullet_object.y));
	bullet_object.rectangle.setPosition(alien_object->x_pos + 15, alien_object->y_pos - 3);
}

void Alien_bullets_deleting(vector <Alien_bullets> &array_bullets)
{
	for (int i = 0; i < array_bullets.size(); i++)
	{

		if (array_bullets.at(i).y_pos >= 734 && array_bullets.size() != i)
		{
			if (i != array_bullets.size())
				array_bullets.erase(array_bullets.begin() + i);
			i = i - 1;
		}
	}
}

void Alien_bullets_generating(vector <Alien_bullets> &array_bullets, Aliens *wsk[], int random)
{

	for (int i = 0; i < 55; i++)
	{
		if (wsk[i] != nullptr && array_bullets.size() < 50 && i == random)
		{
			cout << "random: " << random << endl;
			cout << "size: " << array_bullets.size() << endl;
				
				Alien_bullets alien_bullets_object;
				alien_bullets_object.x_pos = wsk[i]->x_pos + 23;
				alien_bullets_object.y_pos = wsk[i]->y_pos + 10;
				Alien_bullets_parameters(alien_bullets_object, wsk[i]);
				array_bullets.push_back(alien_bullets_object);
				random = 0;


		}
	}
	random = 0;
}

void Alien_bullets_positioning(vector <Alien_bullets> &array)
{
	for (int i = 0; i < array.size(); i++)
	{
		array.at(i).y_pos = array.at(i).y_pos + 4;
		array.at(i).rectangle.setPosition(array.at(i).x_pos, array.at(i).y_pos);
	}
}

void Alien_bullets_drawing(RenderWindow &window, vector <Alien_bullets>& array)
{
	for (int i = 0; i < array.size(); i++)
	{
		window.draw(array.at(i).rectangle);
	}
}

void Alien_bullets_collision(vector <Alien_bullets> &array_bullet_aliens, Player player_object, RenderWindow &window, bool &game_loop)
{
	for (int i = 0; i < array_bullet_aliens.size(); i++)
	{
		if (array_bullet_aliens.at(i).x_pos > player_object.x_pos && array_bullet_aliens.at(i).x_pos
			< player_object.x_pos + 130 * 0.7  && array_bullet_aliens.at(i).y_pos >= player_object.y_pos + 15
			&& array_bullet_aliens.at(i).y_pos <= player_object.y_pos + 40)
		{
			life = life - 1;
			array_bullet_aliens.erase(array_bullet_aliens.begin() + i);

			if (life <= 0)
			{
				game_loop = false;
				break;
			}
		}
	}
}


int previous_random = 0;
int range = 55;
int max_size = 2;
int frames = 40;



void Alien_bullets_managing(RenderWindow& window, vector <Alien_bullets> &array_bullets_aliens, Aliens *array_aliens[], int movement_of_aliens, Player player, bool &game_loop)
{
	if (array_bullets_aliens.size() < max_size && movement_of_aliens % frames == 0)
	{
		cout << "idzie tu" << endl;
		int to_change_range = 0;

		for (int i = 33; i < 55; i++)
		{
			if (array_aliens[i] == nullptr)
			{
				to_change_range++;
			}
			if (to_change_range > 20)
			{
				range = 38;
			}
		}

		for (int i = 12; i < 55; i++)
		{
			if (array_aliens[i] == nullptr)
			{
				to_change_range++;
			}
			if (to_change_range > 20)
			{
				range = 30;
			}
		}
		to_change_range = 0;

		for (int i = 12; i < 55; i++)
		{
			if (array_aliens[i] == nullptr)
			{
				to_change_range++;
			}
			if (to_change_range > 25)
			{
				range = 22;
			}
		}
		to_change_range = 0;

		int c = 0;
		for (int i = 0; i < 55; i++)
		{
			if (array_aliens[i] == nullptr)
			{
				c++;
			}
			if (c > 5)
				max_size = 3;
			if (c > 15)
				max_size = 4;
			if (c > 25)
				max_size = 5;
			if (c > 45)
				frames = 25;
			if (c > 50)
				frames = 15;
			if (c > 53)
			{
				frames = 5;
				range = 11;
			}

		}
		

		struct timespec ts;
		timespec_get(&ts, TIME_UTC);
		srand((time_t)ts.tv_nsec);

		int d = 0;
		for (int i = 0; i < 55; i++)
		{
			if (array_aliens[i] == nullptr)
			{
				d++;
			}
			if (c > 45)
			{
				srand(time(NULL));
			}
		}
		int random;
		random = rand() % range;
		if (random == previous_random && random != 5 && random != 54 && range == 55)
		{
			int random_if = rand() % 4 + 1;
			switch (random_if)
			{
			case 1:
				if (random < 54)
				{
					random = random + 1;
				}
				break;

			case 2:
				if (random < 51)
				{
					random = random + 3;
					
				}
				break;
			case 3:
				if (random < 49)
				{
					random = random + 5;
				}
				break;

			case 4:
				if (random < 47)
				{
					random = random + 7;
				}
				break;

			}
			
		}

		Alien_bullets_generating(array_bullets_aliens, array_aliens, random);
		previous_random = random;
	}
	Alien_bullets_positioning(array_bullets_aliens);
	Alien_bullets_collision(array_bullets_aliens, player, window, game_loop);
	Alien_bullets_drawing(window, array_bullets_aliens);
	Alien_bullets_deleting(array_bullets_aliens);
}

