/*
 * PowerUp.cpp
 *
 *  Created on: May 16, 2023
 *      Author: moaz
 */

#include "PowerUp.h"

PowerUp::PowerUp()
{
	type = 'P';
	add_on.loadFromFile("img/PNG/Power-ups/powerupBlue_star.png");
	sprite.setTexture(add_on);
	sprite.setPosition((5 + rand() % 1080), -100);
	sprite.setScale(1.5,1.5);
	hit_x=sprite.getPosition().x;
	hit_y=sprite.getPosition().y;
}
void PowerUp::Display(Add_on & P)
{
	P.sprite.setPosition((5 + rand() % 1080), -20);
	hit_x=sprite.getPosition().x;
	hit_y=sprite.getPosition().y;
}
PowerUp::~PowerUp() {
	// TODO Auto-generated destructor stub
}

