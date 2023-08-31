/*
 * Fire.cpp
 *
 *  Created on: May 12, 2023
 *      Author: moaz
 */

#include "Fire.h"

Fire::Fire()
{
	type = 'F';
	add_on.loadFromFile("img/PNG/Power-ups/powerupBlue_bolt.png");
	sprite.setTexture(add_on);
	sprite.setPosition((5 + rand() % 1080), -100);
	sprite.setScale(1.5,1.5);
	hit_x=sprite.getPosition().x;
	hit_y=sprite.getPosition().y;
}
void Fire::Display(Add_on& F)
{
	F.sprite.setPosition((5 + rand() % 1080), -20);
	hit_x=sprite.getPosition().x;
	hit_y=sprite.getPosition().y;
}
Fire::~Fire() {
	// TODO Auto-generated destructor stub
}

