/*
 * Enemy.h
 *
 *  Created on: May 12, 2023
 *      Author: moaz
 */

#ifndef ENEMY_H_
#define ENEMY_H_
#include <SFML/Graphics.hpp>
#include<string.h>
#include "Spaceship.h"
using namespace sf;
class Enemy {
public:
	Texture enemy;
	Sprite sprite;
	int lives;
	char type;
	Enemy();
	virtual bool collision(Spaceship *& p) = 0;
	virtual int collision(Bullet *& b) = 0;
	virtual ~Enemy();
};

#endif /* ENEMY_H_ */
