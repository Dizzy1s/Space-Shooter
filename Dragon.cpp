/*
 * Dragon.cpp
 *
 *  Created on: May 15, 2023
 *      Author: moaz
 */

#include "Dragon.h"

Dragon::Dragon() {

	type = 'D';
	lives = 99999;
	enemy.loadFromFile("img/dragon1.png");
	sprite.setTexture(enemy);
	sprite.setScale(0.85,0.85);
	sprite.setPosition(3500,3500);
	Fire_M.loadFromFile("img/PNG/Lasers/laserRed16.png");
	sprite_F.setTexture(Fire_M);
	sprite_F.setScale(3,12);
	sprite_F.setPosition(-800,-800);
	beam_time = 0;

}
int Dragon::collision(Bullet *&b)
{
	int detect = 0;
	for (int loop = 0 ; loop < 20; loop++)
	if (((b[loop].sprite_b.getPosition().x+20) >= sprite.getPosition().x) && ((b[loop].sprite_b.getPosition().x-190) <= sprite.getPosition().x) && ((b[loop].sprite_b.getPosition().y-200) <= sprite.getPosition().y)  && ((b[loop].sprite_b.getPosition().y+60) >= sprite.getPosition().y) )
	{
		detect = loop;
	}
	return detect;
}
bool Dragon::collision(Spaceship *&p)
{
	bool detect = 0;
	if (((p->sprite.getPosition().x+80) >= sprite.getPosition().x) && ((p->sprite.getPosition().x-190) <= sprite.getPosition().x) && ((p->sprite.getPosition().y-200) <= sprite.getPosition().y)  && ((p->sprite.getPosition().y+60) >= sprite.getPosition().y) )
	{
		detect = true;
	}
	return detect;
}
void Dragon::fire_beam()
{
	sprite_F.setPosition(sprite.getPosition().x+80,sprite.getPosition().y+200);
}
Dragon::~Dragon() {
	// TODO Auto-generated destructor stub
}

