#pragma once
#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;


class Periscope{
public:
	float x, y;
	int dir;
	String File;
	Image image;
	Texture texture;
	Sprite sprite;

	Periscope(String F, float X, float Y) {
		File = F;
		image.loadFromFile("image/" + File);
		texture.loadFromImage(image);
		sprite.setTexture(texture);
		x = X; y = Y;
		sprite.setPosition(x, y);
		sprite.scale(0.6, 0.6);
	}
};