#ifndef DANGER_H_
#define DANGER_H_
#include <SFML/Graphics.hpp>
#include<string.h>
#include "Add_on.h"
#include <ctime>
using namespace sf;
class Danger: public Add_on{
public:
	Danger();
	void Display(Add_on& d);
	virtual ~Danger();
};
#endif
