#include "Bullet.h"


void Bullet::update(float time) {
	x = (time * dx) + x;
	dx = 0;
	if (fire) { y = y - time * speed; }

	if (y < 280) {
		fire = false;
		y = 500;
		x = 320;
		j = j - 1;

	}


	sprite.setPosition(x, y);

};