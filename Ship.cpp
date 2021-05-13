#include "Ship.h"


void Ship::update(float time)
{
	if (speed > 0) {
		dir = 1;
	}
	else {
		dir = 0;
	}
	seaX = (dx * time) + seaX;
	x = (time * (dx + speed)) + x;


	dx = 0;
	sprite.setPosition(x, y);
	CurrentFrame += 0.005*time;
	if (CurrentFrame > 3) CurrentFrame -= 3;
	if (speed >= 0) {
		sprite.setTextureRect(IntRect(w * int(CurrentFrame), 2 * h, w, h));
	}
	else {
		sprite.setTextureRect(IntRect(w * int(CurrentFrame), h, w, h));
	}
	if (abs(x - x0 - seaX) > 350) {
		speed = -speed;
	}
};