/*
 * Dragon.h
 *
 *  Created on: May 15, 2023
 *      Author: moaz
 */

#ifndef DRAGON_H_
#define DRAGON_H_
#include"Enemy.h"
class Dragon : public Enemy{
public:
	Texture Fire_M;
	Sprite sprite_F;
	float beam_time;
	Dragon();
	void fire_beam();
	bool collision(Spaceship *& p);
	int collision(Bullet *& b);
	virtual ~Dragon();
};

#endif /* DRAGON_H_ */
