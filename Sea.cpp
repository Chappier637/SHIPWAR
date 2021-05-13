
#include <SFML/Graphics.hpp>
#include "Sea.h"


using namespace sf;




void Sea::update(float time)
{

	x = (time * dx) + x;
	dx = 0;
	if (x >= 0) {
		x = 0;
	}
	if (x <= -350) {
		x = -350;
	}
	sprite.setPosition(x, y);


};
bool Sea::getMoveL() {
	if (x <= -350) { return false; }
	return true;
};
bool Sea::getMoveR() {
	if (x >= 0) { return false; }
	return true;
};