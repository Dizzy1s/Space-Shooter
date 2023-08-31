/*
 * Invader.cpp
 *
 *  Created on: May 12, 2023
 *      Author: moaz
 */

#include "Invader.h"
Invader::Invader()
{
	type = 'I';
	sprite.setPosition(-4000,-4000);
}
bool Invader::collision(Spaceship *& p)
{
	bool detect = 0;
	if (((p->sprite.getPosition().x+45) >= sprite.getPosition().x-27.5) && ((p->sprite.getPosition().x-90) <= sprite.getPosition().x-22.5) && ((p->sprite.getPosition().y-77.5) <= sprite.getPosition().y-25)  && ((p->sprite.getPosition().y+32.5) >= sprite.getPosition().y-25) )
	{
		detect = true;
	}
	return detect;
}
int Invader::collision(Bullet *& b)
{
	int detect = 0;
	for (int loop = 0 ; loop < 20; loop++)
	if (((b[loop].sprite_b.getPosition().x-20) >= sprite.getPosition().x-27.5) && ((b[loop].sprite_b.getPosition().x-90) <= sprite.getPosition().x-22.5) && ((b[loop].sprite_b.getPosition().y-77.5) <= sprite.getPosition().y-25)  && ((b[loop].sprite_b.getPosition().y+32.5) >= sprite.getPosition().y-25) )
	{
		detect = loop;
		lives--;
	}
	return detect;
}
Invader::~Invader() {
	// TODO Auto-generated destructor stub
}

