/*
 * Beta.cpp
 *
 *  Created on: May 13, 2023
 *      Author: moaz
 */

#include "Beta.h"

Beta::Beta()
{
	type = 'B';
	enemy.loadFromFile("img/PNG/Enemies/enemyBlue4.png");
	sprite.setTexture(enemy);
	sprite.setPosition(-5000,-5000);
	sprite.setScale(0.75,0.75);
	lives = 2;
}

Beta::~Beta() {
	// TODO Auto-generated destructor stub
}

