#ifndef SPACESHIP_H_
#define SPACESHIP_H_
#include <SFML/Graphics.hpp>
#include<string.h>
#include "Add_on.h"
#include "Bullet.h"
using namespace sf;
class Spaceship{
	public:
		Texture tex;
		Texture rot_left;
		Texture rot_right;
		Sprite sprite;
		int lives;
		float speed=0.1;
		int hit_box_length;
		int hit_box_height;
		int x,y;
	Spaceship(std::string png_path);
	void fire(Bullet& b);
	void move(std::string s);
	bool collision(Add_on*& add_on);
	virtual ~Spaceship();
};
#endif
