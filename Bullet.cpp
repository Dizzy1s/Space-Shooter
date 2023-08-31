/*
 * bullet.cpp
 *
 *  Created on: May 11, 2023
 *      Author: moaz
 */
#include "Bullet.h"

Bullet::Bullet()
{
	bullet.loadFromFile("img/PNG/Lasers/bullet.png");
	sprite_b.setTexture(bullet);
	sprite_b.setScale(0.25,0.25);
}
Bullet::~Bullet(){}



