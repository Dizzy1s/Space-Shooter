/*
 * Monster.h
 *
 *  Created on: May 14, 2023
 *      Author: moaz
 */
#include "Enemy.h"
#ifndef MONSTER_H_
#define MONSTER_H_

class Monster: public Enemy {
public:
	Texture Fire_M;
	Sprite sprite_F;
	float beam_time;
	Monster();
	void fire_beam();
	bool collision(Spaceship *& p);
	int collision(Bullet *& b);
	virtual ~Monster();
};

#endif /* MONSTER_H_ */
