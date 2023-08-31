/*
 * PowerUp.h
 *
 *  Created on: May 16, 2023
 *      Author: moaz
 */

#ifndef POWERUP_H_
#define POWERUP_H_
#include <SFML/Graphics.hpp>
#include<string.h>
#include "Add_on.h"
#include "Bullet.h"
using namespace sf;
class PowerUp: public Add_on {
public:
	void Display(Add_on & add_on);
	PowerUp();
	~PowerUp();
};

#endif /* POWERUP_H_ */
