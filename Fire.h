/*
 * Fire.h
 *
 *  Created on: May 12, 2023
 *      Author: moaz
 */

#ifndef FIRE_H_
#define FIRE_H_

#include <SFML/Graphics.hpp>
#include<string.h>
#include "Add_on.h"
#include <ctime>
using namespace sf;
class Fire: public Add_on{
public:
	Fire();
	void Display(Add_on& F);
	virtual ~Fire();
};
#endif /* FIRE_H_ */
