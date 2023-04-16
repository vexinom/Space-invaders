#pragma once
using namespace std;
using namespace sf;

void Load_font()
{
	Font font;
	if (font.loadFromFile("Fonts/joystix monospace.ttf"))
		cout << "Error" << endl;
}

//Closing window - don't add anything to that
void Rendering(RenderWindow &window)
{
	Event closing;
	window.pollEvent(closing);
	if (closing.type == Event::Closed) window.close();
}
void Menu(RenderWindow &window)
{

}
