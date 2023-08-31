/*
 * Gamma.cpp
 *
 *  Created on: May 14, 2023
 *      Author: moaz
 */

#include "Gamma.h"

Gamma::Gamma()
{
	type = 'G';
	enemy.loadFromFile("img/PNG/Enemies/enemyBlack5.png");
	sprite.setTexture(enemy);
	sprite.setPosition(-5000,-5000);
	sprite.setScale(0.75,0.75);
	lives = 3;
}

Gamma::~Gamma() {
	// TODO Auto-generated destructor stub
}

