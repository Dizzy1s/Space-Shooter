#ifndef MENU_H_
#define MENU_H_
#include "Game.h"
class Menu{
public:
float time;
float timer;
Texture tex;
Sprite sprite;
Font font;
Texture t1;
Sprite s1;
int score1;
int score2;
int score3;
int score4;
int score5;
//add menu attributes here
Menu();
void display_menu();
void high_score();
virtual ~Menu();

};
#endif
