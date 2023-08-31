#ifndef ADDON_H_
#define ADDON_H_


#include <iostream>
#include <SFML/Graphics.hpp>
#include<string.h>
using namespace sf;
class Add_on{
public:
	Texture add_on;
	Sprite sprite;
	char type;
	int hit_x;
	int hit_y;
	Add_on();
	virtual void Display(Add_on& add_on) = 0;
	virtual ~Add_on();
};
#endif
