/*
 * Spaceship.cpp
 *
 *  Created on: May 11, 2023
 *      Author: moaz
 */
#include "Spaceship.h"

Spaceship::Spaceship(std::string png_path)
{
	lives = 3;
	rot_left.loadFromFile("img/PNG/rot1.png");
	rot_right.loadFromFile("img/PNG/rot2.png");
	tex.loadFromFile(png_path);
	sprite.setTexture(tex);
	x=490;y=580;
	hit_box_length = 90;
	hit_box_height = 75;
	sprite.setPosition(x,y);
	sprite.setScale(0.85,0.85);
}

void Spaceship::fire(Bullet& b)
{
	if (b.sprite_b.getPosition().y < -25)
	{
		b.sprite_b.setPosition(sprite.getPosition().x+35,sprite.getPosition().y - 50);
	}
}
void Spaceship::move(std::string s)
{
	float delta_x=0,delta_y=0;
	if(s=="l")
		{delta_x = -7;
		sprite.setTexture(rot_left);
		sprite.setScale(1.25,1.25);
		delta_x = -7;
		s = "0";}//move the player left
	if(s=="d")
			{
			delta_y= 7;}
	if(s=="r")
		{delta_x = 7;
		sprite.setTexture(rot_right);
		sprite.setScale(1.25,1.25);
		delta_x = 7;
		s = "0";
		}//move the player right
	if(s=="u")
		{
		delta_y= -7;}
	if(s=="d")
		{
		delta_y= 7;}

	delta_x*=speed;
	delta_y*=speed;
// 338 414		//cout << sprite.getPosition().x << " " << sprite.getPosition().y << endl;
		if (sprite.getPosition().x < -40 )
		{
			sprite.setPosition(1020,sprite.getPosition().y);
		}
		if (sprite.getPosition().x > 1020 )
		{
			sprite.setPosition(-40,sprite.getPosition().y);		// Border Anamoly Checking and Setting
		}
		if (sprite.getPosition().y > 640 )
		{
			sprite.setPosition(sprite.getPosition().x,-25);
		}
		if (sprite.getPosition().y < -25 )
		{
			sprite.setPosition(sprite.getPosition().x,640);
		}

	sprite.move(delta_x, delta_y);

}
bool Spaceship::collision(Add_on*& add_on)
{
	bool detect = false;
					/// LEFT SIDE																									/// RIGHT SIDE														/// DOWN																				/// UP
	if (((sprite.getPosition().x+hit_box_length/2) >= add_on->sprite.getPosition().x-27.5) && ((sprite.getPosition().x-hit_box_length/2) <= add_on->sprite.getPosition().x-22.5) && ((sprite.getPosition().y-hit_box_height/2) <= add_on->sprite.getPosition().y-25)  && ((sprite.getPosition().y+hit_box_height/2) >= add_on->sprite.getPosition().y-25) )
	{
		detect = true;
		add_on[0].sprite.setPosition(-100,-100);
	}
	return detect;
}

Spaceship::~Spaceship(){};



