#pragma once
#include <SFML/Graphics.hpp>




using namespace sf;

class Bullet{
public:
	int j = 6;
	float x, y, dx = 0, speed = 0.1;
	bool fire = false;
	int dir;
	String File;
	Image image;
	Texture texture;
	Sprite sprite;
	int i = 0;

	Bullet(String F, float X, float Y) {
		File = F;
		image.loadFromFile("image/" + File);
		texture.loadFromImage(image);
		sprite.setTexture(texture);

		sprite.scale(0.06, 0.06);
		sprite.rotate(90);
		x = X; y = Y;


	};
	void update(float time);
};