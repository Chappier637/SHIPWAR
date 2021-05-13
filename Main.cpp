
#include "Sea.h"
#include "Ship.h"
#include "Bullet.h"
#include "Periscope.h"
#include <random>


int randInt(int from, int to)
{

	int low = from, high = to;
	if (from > to)
	{
		low = to;
		high = from;
	}

	return rand() % ((high + 1) - low) + low;
}

int main()

{
	int i = 0;
	int j = 6;
	
	
	
	RenderWindow window(sf::VideoMode(640, 480), "SHIPWAR");

	Clock clock;
	

	Ship s("s.png", randInt(0, 320), 200, 80, 96,0.05);
	Ship s1("s.png", randInt(0, 320), 200, 80, 96, 0.075);
	Ship s2("s.png", randInt(0, 320), 200, 80, 96, 0.025);
	Sea sea("fon.png", -350, -100);
	Periscope per("per.png", -150, 0);
	Bullet b("t.png", 320, 500);
	

	Image win; //создаем объект Image (изображение)
	win.loadFromFile("image/win.jpg");//загружаем в него файл

	Texture wintexture;//создаем объект Texture (текстура)
	wintexture.loadFromImage(win);//передаем в него объект Image (изображения)

	Sprite winsprite;//создаем объект Sprite(спрайт)
	winsprite.setTexture(wintexture);//передаём в него объект Texture (текстуры)
	winsprite.setPosition(0, 0);//задаем начальные координаты появления спрайта

	Image loseimage; //создаем объект Image (изображение)
	loseimage.loadFromFile("image/lose.png");//загружаем в него файл

	Texture losetexture;//создаем объект Texture (текстура)
	losetexture.loadFromImage(loseimage);//передаем в него объект Image (изображения)

	Sprite losesprite;//создаем объект Sprite(спрайт)
	losesprite.setTexture(losetexture);//передаём в него объект Texture (текстуры)
	losesprite.setPosition(0, 0);//задаем начальные координаты появления спрайта

	
	while (window.isOpen())
	{
		float time = clock.getElapsedTime().asMicroseconds();
		clock.restart();
		time = time / 800;

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		///////////////////////////////////////////Управление кораблями////////////////////////////////////////////////////////////////////////
		if (Keyboard::isKeyPressed(Keyboard::Right) ) {
			if (sea.getMoveR()) {
				s.dir = 1; s.dx = 0.1;
				s1.dir = 1; s1.dx = 0.1;
				s2.dir = 1; s2.dx = 0.1;
				sea.dx = 0.1;
				b.dx = 0.1;
			}
			
		}

		if (Keyboard::isKeyPressed(Keyboard::Left)) {
			if (sea.getMoveL()) {
				s.dir = 0; s.dx = -0.1;
				s1.dir = 0; s1.dx = -0.1;
				s2.dir = 0; s2.dx = -0.1;
				sea.dx = -0.1;
				b.dx = -0.1;
			}
		}
		if (Keyboard::isKeyPressed(Keyboard::Space)) {
			b.fire = true;
			
			
			b.x = 343;
		}

		if (b.x < s.x+s.w && b.x > s.x && b.y < 285)
		{
			s.x = 12220;
			i += 1;
		}
		if (b.x < s1.x + s1.w && b.x > s1.x && b.y < 285)
		{
			s1.x = 12220;
			i += 1;
		}
		if (b.x < s2.x + s2.w && b.x > s2.x && b.y < 285)
		{
			s2.x = 12220;
			i += 1;
		}
		else
		{
			// nothing...
		}

		s.update(time);
		s1.update(time);
		s2.update(time);
		sea.update(time);
		b.update(time);
		

		window.clear();
		window.draw(sea.sprite);
		window.draw(b.sprite);
		window.draw(s.sprite);

		window.draw(s1.sprite);

		window.draw(s2.sprite);
		window.draw(per.sprite);



		if (i == 3) {
			window.draw(winsprite);
		}
		if (b.j == 0) {
			window.draw(losesprite);
		}

		
		
		window.display();
	}

	return 0;
 }