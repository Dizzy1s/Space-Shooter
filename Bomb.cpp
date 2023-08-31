/*
 * Bomb.cpp
 *
 *  Created on: May 16, 2023
 *      Author: moaz
 */

#include "Bomb.h"

Bomb::Bomb() {
	tex.loadFromFile("img/enemy_laser.png");
	sprite.setTexture(tex);
	sprite.setPosition(-400, -400);
}

Bomb::~Bomb() {
	// TODO Auto-generated destructor stub
}

