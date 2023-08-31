/*
 * Invader.h
 *
 *  Created on: May 12, 2023
 *      Author: moaz
 */

#ifndef INVADER_H_
#define INVADER_H_
#include <SFML/Graphics.hpp>
#include<string.h>
#include "Enemy.h"
class Invader: public Enemy {
public:
	Invader();
	bool collision(Spaceship *& p);
	int collision(Bullet *& b);
	virtual ~Invader();
};

#endif /* INVADER_H_ */
