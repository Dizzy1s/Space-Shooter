/*
 * Bomb.h
 *
 *  Created on: May 16, 2023
 *      Author: moaz
 */

#ifndef BOMB_H_
#define BOMB_H_
#include <SFML/Graphics.hpp>
#include<string.h>
using namespace sf;
class Bomb {
public:
	Texture tex;
	Sprite sprite;
	Bomb();
	virtual ~Bomb();
};

#endif /* BOMB_H_ */
