/*
 * Lives.cpp
 *
 *  Created on: May 11, 2023
 *      Author: moaz
 */
#include "Lives.h"

Lives::Lives()
{
	type = 'L';
	add_on.loadFromFile("img/PNG/Power-ups/pill_red.png");
	sprite.setTexture(add_on);
	sprite.setPosition((5 + rand() % 1080), -100);
	sprite.setScale(2,2);
	hit_x=sprite.getPosition().x;
	hit_y=sprite.getPosition().y;
}
void Lives::Display(Add_on& l)
{
	l.sprite.setPosition((5 + rand() % 1080), -20);
	hit_x=sprite.getPosition().x;
	hit_y=sprite.getPosition().y;
}
Lives::~Lives(){}



