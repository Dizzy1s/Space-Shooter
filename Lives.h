#ifndef LIVES_H_
#define LIVES_H_
#include <SFML/Graphics.hpp>
#include<string.h>
#include "Add_on.h"
#include <ctime>
using namespace sf;
class Lives: public Add_on{
public:
	Lives();
	void Display(Add_on& l);
	virtual ~Lives();
};
#endif
