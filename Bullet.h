#ifndef BULLET_H_
#define BULLET_H_
#include <SFML/Graphics.hpp>
#include<string.h>
using namespace sf;
class Bullet{
public:
	Texture bullet;
	Sprite sprite_b;
	float speed = 0.1;
Bullet();
virtual ~Bullet();
};
#endif
