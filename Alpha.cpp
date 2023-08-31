/*
 * Alpha.cpp
 *
 *  Created on: May 13, 2023
 *      Author: moaz
 */

#include "Alpha.h"

Alpha::Alpha()
{
	type = 'A';
	enemy.loadFromFile("img/PNG/Enemies/enemyRed1.png");
	sprite.setTexture(enemy);
	sprite.setPosition(-4000,-4000);
	sprite.setScale(0.75,0.75);
	lives = 1;
}

Alpha::~Alpha() {
	// TODO Auto-generated destructor stub
}

