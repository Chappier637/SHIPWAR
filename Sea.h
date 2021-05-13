#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
class Sea {
public:
	float x, y, dx = 0;
	int dir;
	String File;
	Image image;
	Texture texture;
	Sprite sprite;

	Sea(String F, float X, float Y) {
		File = F;
		image.loadFromFile("image/" + File);
		texture.loadFromImage(image);
		sprite.setTexture(texture);
		x = X; y = Y;
	};
	void update(float time);
	bool getMoveL();
	bool getMoveR();
};