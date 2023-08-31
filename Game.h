#ifndef GAME_H_
#define GAME_H_
#include <SFML/Graphics.hpp>
#include <time.h>
#include <fstream>
/////////////////////////////
#include "Spaceship.h"
#include "Danger.h"
#include "Lives.h"
#include "Fire.h"
#include "PowerUp.h"
#include "Invader.h"
#include "Alpha.h"
#include "Beta.h"
#include "Gamma.h"
#include "Bomb.h"
#include "Monster.h"
#include "Dragon.h"
/////////////////////////////
#include <iostream>
using namespace std;
using namespace sf;

class Game
{
public:
	Sprite background; //Game background sprite
	Texture bg_texture;
	Texture b_left;
	Texture b_right;
	Font font;
	Text text;
	Enemy * enemy[3][3];
	Add_on * add_on[4];
	Danger D;
	Lives L;
	Fire F;
	PowerUp power;
	Bullet power_up[7][20];
	Invader I[3][50];
	Alpha a;
	Bomb bomb[50];
	Beta B;
	Gamma G;
	Monster M;
	Dragon dragon;
	Spaceship* p; //player
	Bullet b[20];
	int b_count;
	int level;
	bool fire_power;
	float fire_counter;
	float bomb_fire;
	bool bomb1;
	int bullets;
	int monster_move;
	int bullet_hit;
	float delay;
	float detect_delay;
	float detect_delay2;
	float detect_delay3;
	float detect_delay4;
	bool detect;
	int lvl2;
	int alpha_count;
	bool go_to_level2;
	bool detect2;
	bool detect3;
	bool detect4;
	bool monster_end;
	float timer;
	int m;
	float random;
	float fire_timer;
	bool firing;
	float time;
	float level_detect;
	bool invader_collide;
	float invade;
	bool change_level;
	bool collided;
	bool change_lvl;
	int shapes;
	float collide_time;
	float level_change_time;
	float add_delay;
	float add_delay1;
	int count_beta;
	bool trigger;
	float contact;
	float explode;
	float contact2;
	float dragon_timer;
	bool drag;
	int dw;
	int counter1;
	int count1;
	int score1;
	bool monster_collide;
	Sprite damage;
	Texture Damage;
	Texture Fires;
	Sprite fires;
	Texture Damage2;
	Sprite damage2;
	string score;
	string s;
	Texture Explosion1;
	Texture Explosion2;
	Texture Explosion3;
	Texture Explosion4;
	Sprite explosion1;
	Sprite explosion2;
	Sprite explosion3;
	Sprite explosion4;
	// add other game attributes


Game();
/// Functionalities ///
/*---1---*/		void make_addon();
/*---2---*/		void handle_addon();
/*---3---*/		void make_bullet();
/*---4---*/		void handle_bullet();
/*---5---*/		void start_game();
/*---6---*/		void make_level1();
/*---7---*/		void invader_player_collide();
/*---8---*/		void invader_bullet_collide();
/*---9---*/		bool go_to_lvl2();
/*---10---*/	void make_level2();
/*---11---*/	void handle_levels();
/*---12---*/	void call_monster();
/*---13---*/	void make_level3();
/*---14---*/ 	void call_dragon();
/*---15---*/	void Fire_bomb();
/// Functionalities ///
virtual ~Game();
};
#endif
