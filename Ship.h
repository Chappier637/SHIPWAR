#pragma once
#include <SFML/Graphics.hpp>




using namespace sf;



//////////////////////////////////////////////////// À¿——  Œ–¿¡Àﬂ ////////////////////////
class Ship {
public:
	float x, y, x0, y0, w, h, dx = 0, dy, speed, CurrentFrame = 0;
	float seaX = 0;
	int dir;
	String File;
	Image image;
	Texture texture;
	Sprite sprite;

	Ship(String F, float X, float Y, float W, float H, float Speed) {
		File = F;
		w = W; h = H;
		speed = Speed;
		image.loadFromFile("image/" + File);
		texture.loadFromImage(image);
		sprite.setTexture(texture);
		x = X; y = Y;
		seaX = x;
		x0 = X; y0 = Y;
		sprite.setTextureRect(IntRect(0, 0, w, h));

	};
	void update(float time);
};
