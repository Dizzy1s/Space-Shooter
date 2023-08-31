/*
 * Danger.cpp
 *
 *  Created on: May 11, 2023
 *      Author: moaz
 */
#include "Danger.h"

Danger::Danger()
{
	type = 'D';
	add_on.loadFromFile("img/PNG/Meteors/meteorBrown_big2.png");
	sprite.setTexture(add_on);
	sprite.setPosition((5 + rand() % 1080), -100);
	sprite.setScale(0.25,0.25);
	hit_x=sprite.getPosition().x;
	hit_y=sprite.getPosition().y;
}
void Danger::Display(Add_on& d)
{
	d.sprite.setPosition((5 + rand() % 1080), -20);
	hit_x=sprite.getPosition().x;
	hit_y=sprite.getPosition().y;
}
Danger::~Danger()
{

}


