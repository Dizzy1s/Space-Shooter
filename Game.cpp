/*
 * Game.cpp
 *
 *  Created on: May 11, 2023
 *      Author: moaz
 */
#include "Game.h"
Game::Game()
{
	p=new Spaceship("img/PNG/playerShip3_blue.png");
	bg_texture.loadFromFile("img/background_1.png");
	b_left.loadFromFile("img/PNG/Lasers/bullet_left.png");
	b_right.loadFromFile("img/PNG/Lasers/bullet_right.png");
	background.setTexture(bg_texture);
	background.setPosition(0,-1480);
	background.setScale(2,2);
	font.loadFromFile("img/arial.ttf");
	text.setFont(font);
	Damage.loadFromFile("img/PNG/Damage/playerShip1_damage2.png");
	Damage2.loadFromFile("img/PNG/Effects/shield1.png");
	damage.setTexture(Damage);
	damage2.setTexture(Damage2);
	damage2.setPosition(-200,-200);
	for (int loop = 0; loop < 7; loop++)
	{
		for (int loop2= 0 ; loop2 < 20; loop2++)
		{
			power_up[loop][loop2].sprite_b.setPosition(-900,-900);
		}
	}
	damage2.setScale(0.75,0.75);
	damage.setPosition(-100,-100);
	Fires.loadFromFile("img/PNG/Lasers/im.png");
	fires.setTexture(Fires);
	fires.setPosition(0,-1000);
	fires.setScale(0.85,18);
	Explosion1.loadFromFile("img/explosion1.png");
	Explosion2.loadFromFile("img/explosion2.png");
	Explosion3.loadFromFile("img/explosion3.png");
	Explosion4.loadFromFile("img/explosion4.png");
	explosion1.setTexture(Explosion1);
	explosion2.setTexture(Explosion2);
	explosion3.setTexture(Explosion3);
	explosion4.setTexture(Explosion4);
	explosion1.setScale(0.25,0.25);
	explosion2.setScale(0.25,0.25);
	explosion3.setScale(0.25,0.25);
	explosion4.setScale(0.25,0.25);
	explosion1.setPosition(-900,-900);
	explosion2.setPosition(-900,-900);
	explosion3.setPosition(-900,-900);
	explosion4.setPosition(-900,-900);
	text.setCharacterSize(24);
	text.setFillColor(sf::Color::Red);
	text.setStyle(sf::Text::Bold | sf::Text::Underlined);
	enemy[1][0] = &M;
	delay = 0;
	b_count = 0;
	level = 0;
	bullet_hit = 0;
	counter1 = 0;
	count1 =0;
	collide_time = 0;
	lvl2 = 0;
	contact = 0;
	dw = 100;
	score1 = 0;
	s = "Score: ";
	fire_counter = 0;
	bomb_fire = 0;
	bullets = 0;
	monster_move = 100;
	firing = 0;
	detect4 = 0;
	alpha_count = 0;
	bomb1 = 0;
	monster_collide = 0;
	shapes = 1;
	explode = 0;
	monster_end = 0;
	time = 0;
	change_level = 0;
	delay =0;
	change_lvl = 0;
	level_detect = 0;
	go_to_level2 = 0;
	invader_collide = 0;
	detect_delay = 0;
	detect_delay2 = 0;
	add_delay = 0;
	detect_delay3 = 0;
	detect  = 0;
	detect2  = 0;
	detect3 = 0;
	timer=0;
	m = 100;
	count_beta = 0;
	fire_power = 0;
	random = 0;
	fire_timer = 0;
	invade = 0;
	collided = 0;
	detect_delay4 = 0;
	level_change_time = 0;
	add_delay1 = 0;
	trigger = 0;
	contact2 = 0;
	drag = 0;
	dragon_timer = 0;
}
void Game::make_addon()
{
	add_on[0] = &D;
	add_on[1] = &L;
	add_on[2] = &F;
	add_on[3] = &power;
	if (random >=5 && random <=5.0025)
	{
		add_on[0]->Display(D);
	}
	if (random >=10 && random <=10.0025)
	{
		add_on[1]->Display(L);
	}
	if (random >=15 && random <=15.0025)
	{
		add_on[2]->Display(F);
	}
	if (random >=20 && random <=20.0025)
	{
		add_on[3]->Display(power);
	}
	detect = p->collision(add_on[0]);
	detect2 = p->collision(add_on[1]);
	detect3 = p->collision(add_on[2]);
	detect4 = p->collision(add_on[3]);
}
void Game::handle_addon()
{
	if (detect && (timer - detect_delay > 1.5))
		{
			damage.setPosition(p->sprite.getPosition().x,p->sprite.getPosition().y);
			detect_delay = timer;
			//window.draw(damage);
			//cout << 1 << endl;
			p->lives--;
		//	cout << p->lives << endl;
		}
		if (detect2 && (timer - detect_delay2 > 1.5))
		{
			detect_delay2 = timer;
			p->lives++;
		//	cout << p->lives << endl;
		}
		if (detect3 && (timer - detect_delay3 > 1.5))
		{
			detect_delay3 = timer;
			fire_timer += time;
			fires.setPosition(p->sprite.getPosition().x+20,p->sprite.getPosition().y-870);
			//fires.setPosition(0,-1000);
		}
		if (detect4 && (timer - detect_delay4 > 1.5))
		{
			detect_delay4 = timer;
			for (int loop = 0; loop < 7; loop++)
			{
				for (int loop2= 0 ; loop2 < 20; loop2++)
				{
					power_up[loop][loop2].sprite_b.setPosition(p->sprite.getPosition().x+35,p->sprite.getPosition().y-50);
				}
			}
			fire_power = true;
		//	cout << p->lives << endl;
		}
		if (fire_power == true && fire_counter <= 4)
		{
			fire_counter+= time;
			for (int loop2= 0 ; loop2 < 20; loop2++)
			{
				power_up[0][loop2].sprite_b.move(0,-1000*time);
				power_up[1][loop2].sprite_b.move(0.5,-1000*time);
				power_up[2][loop2].sprite_b.move(1,-1000*time);
				power_up[3][loop2].sprite_b.move(1.5,-1000*time);
				power_up[4][loop2].sprite_b.move(-0.5,-1000*time);
				power_up[5][loop2].sprite_b.move(-1,-1000*time);
				power_up[6][loop2].sprite_b.move(-1.5,-1000*time);
			}
			for (int loop = 0; loop < 7; loop++)
			{
				for (int loop2 = 0; loop2 < 20; loop2++)
				{
					if (power_up[loop][loop2].sprite_b.getPosition().y < -30)
					{
						firing = true;
						power_up[loop][loop2].sprite_b.setPosition(p->sprite.getPosition().x+35,p->sprite.getPosition().y-50);
					}
				}
			}
		}
		if (fires.getPosition().y >=-999 && fires.getPosition().y < 2000)
		{
			firing = true;
			fire_timer += time;
			fires.setPosition(p->sprite.getPosition().x+20,p->sprite.getPosition().y-870);
			for (int loop = 0; loop < 50; loop++)
			{
				if (fires.getPosition().x-57 <= I[level][loop].sprite.getPosition().x && fires.getPosition().x+37 >= I[level][loop].sprite.getPosition().x)
				{
					I[level][loop].sprite.setPosition(-2000,-2000);
				}
			}
		}
		if (fire_timer >= 5)
		{
			firing = false;
			fire_timer = 0;
			fires.setPosition(0,-1000);
		}
		if (fire_counter >= 3.99)
		{
			firing = false;
			fire_counter = 0;
			fire_power = false;
			for (int loop = 0; loop < 7; loop++)
			{
				for (int loop2= 0 ; loop2 < 20; loop2++)
				{
					power_up[loop][loop2].sprite_b.setPosition(-900,-900);
				}
			}
		}
		if (add_on[0]->sprite.getPosition().y > -30 && add_on[0]->sprite.getPosition().y < 700)
		{
			add_on[0]->sprite.move((-2 + rand() % 5)*25*time,250*time);
			if (int(add_on[0]->sprite.getPosition().y) == 680)
			{
				score1 +=5;
			}
			//D.sprite.setPosition(400,400);
		}
		if (add_on[1]->sprite.getPosition().y > -30 && add_on[1]->sprite.getPosition().y < 700)
		{
			add_on[1]->sprite.move((-2 + rand() % 5)*25*time,250*time);
		//	L.sprite.setPosition(400,400);
		}
		if (add_on[2]->sprite.getPosition().y > -30 && add_on[2]->sprite.getPosition().y < 700)
		{
			add_on[2]->sprite.move((-2 + rand() % 5)*25*time,250*time);
		//	L.sprite.setPosition(400,400);
		}
		if (add_on[3]->sprite.getPosition().y > -30 && add_on[3]->sprite.getPosition().y < 700)
		{
			add_on[3]->sprite.move((-2 + rand() % 5)*25*time,250*time);
		//	L.sprite.setPosition(400,400);
		}
}
void Game::make_bullet()
{
	 if (Keyboard::isKeyPressed(Keyboard::Space) && (timer - delay > 0.20))
	 {
		 delay = timer;
		 if (bullets >= 20)
		 {
			 bullets = 0;
		 }
		 p->fire(b[bullets]);
		 bullets++;
	 }
}
void Game::invader_player_collide()
{
	invader_collide = false;
	for (int loop = 0; loop < 50; loop++)
	{
		invader_collide = I[level][loop].collision(p);
		if (invader_collide == true && (timer-invade >= 1.001))		/// invincble for 1 seconds after hitting invader
		{
			invade = timer;
			damage2.setPosition(p->sprite.getPosition().x-10,p->sprite.getPosition().y-10);
			collided = true;
			collide_time = 0;
			p->lives--;
		}
	}
	if (damage2.getPosition().y > -80 && damage2.getPosition().y < 680 && collide_time <= 1.101)
	{
		collide_time+= time;
		damage2.setPosition(p->sprite.getPosition().x-10,p->sprite.getPosition().y-10);
	}
	if (collide_time >= 1)
	{
		damage2.setPosition(-200,-200);
	}
}
void Game::handle_bullet()
{
	for (int loop = 0; loop < 20; loop++)
	{
		if (b[loop].sprite_b.getPosition().y > -80 && b[loop].sprite_b.getPosition().y < 680)
		{
			b[loop].sprite_b.move(0,-1000*time);
		}
	}
}
void Game::handle_levels()
{
	if (change_lvl && shapes < 4)
	{
		make_level1();
		shapes++;
	}
	if (change_lvl == true && shapes == 5)
	{
		make_level2();
		shapes++;
	}
	if (shapes == 4)
	{
		shapes++;
	}
	count_beta = 0;
	for (int loop = 0; loop < 33; loop++)
	{
		if (I[level][loop].sprite.getPosition().y == -2000 && I[level][loop].sprite.getPosition().x == -2000 && level == 1)
		{
			count_beta++;
		}
	}
	if (count_beta == 30 && shapes == 6)
	{
		make_level2();
		shapes++;
	}
	int bet = 0;
	for (int loop = 0; loop < 34; loop++)
	{
		if (I[level][loop].sprite.getPosition().y == -2000 && I[level][loop].sprite.getPosition().x == -2000 && level == 1)
		{
			bet++;
		}
	}
	if (bet == 34 && shapes == 7)
	{
		make_level2();
		shapes++;
	}
}
void Game::invader_bullet_collide()
{
	Bullet * b3;
	Bullet * b2 = b;
	for (int loop = -0; loop < 7; loop++)
	{
		b3 = power_up[loop];
		for (int loop = 0; loop < 50; loop++)
		{
			bullet_hit  = I[level][loop].collision(b2);
			I[level][loop].collision(b3);
			b[bullet_hit].sprite_b.setPosition(-900,-900);
			if (I[level][loop].lives <= 0)
			{
				I[level][loop].sprite.setPosition(-2000,-2000);
			}
		}
	}
}
void Game::make_level1()
{
	level = 0;
	for (int loop = 0; loop < 50; loop++)
	{
		I[0][loop] = a;
		I[0][loop].lives = 1;
	}
	enemy[0][0] = I[level];
	for (int loop = 0; loop < 50; loop++)
	{
		enemy[0][0][loop].sprite.setPosition(-1800,-1888);
	}
//	int shapes = 1 + rand() % 3;
	if (shapes == 1)
	{
		for (int loop = 0; loop < 7; loop++)
		{
			I[level][loop].sprite.setPosition(250+(80*loop),100);
		}
			I[level][7].sprite.setPosition(250,180);
		for (int loop = 8,loop2 = 0; loop < 15; loop2++, loop++)		/// RECTANGLE
		{
			I[level][loop].sprite.setPosition(250+(80*loop2),260);
		}
			I[level][15].sprite.setPosition(250+(80*6),180);
			if (level == 1)
			{
				score1 += 20;
			}
			if (level == 2)
			{
				score1 += 30;
			}
	}
	if (shapes == 2)
	{
		I[level][0].sprite.setPosition(497,20);
		for (int loop = 1; loop < 4; loop++)
		{
			I[level][loop].sprite.setPosition(497-(80*loop),20+(60*loop));
		}
		for (int loop = 4, loop2 =1; loop < 7; loop2++, loop++)
		{
			I[level][loop].sprite.setPosition(497+(80*loop2),20+(60*loop2));
		}
		for (int loop = 7,loop2 = 1; loop < 14; loop2++, loop++)		/// Triangle
		{
			I[level][loop].sprite.setPosition(95+(100*loop2),290);
		}
		I[level][14].sprite.setPosition(-2000,-2000);
		I[level][15].sprite.setPosition(-2000,-2000);
		I[level][16].sprite.setPosition(-2000,-2000);
		if (level == 0)
		{
			score1 += 10;
		}
		if (level == 1)
		{
			score1 += 20;
		}
		if (level == 2)
		{
			score1 += 30;
		}
	}
	if (shapes == 3)
	{
		for (int loop = 0; loop < 7; loop++)
		{
			I[level][loop].sprite.setPosition(317+(60*loop),20+(52*loop));			/// Cross Sign
		}
		for (int loop = 7,loop2 = 0; loop < 14; loop2++,loop++)
		{
			if (loop != 10)
			{
				I[level][loop].sprite.setPosition(677-(60*loop2),20+(52*loop2));			/// Cross Sign
			}
		}
		I[level][14].sprite.setPosition(-2000,-2000);
		I[level][10].sprite.setPosition(-2000,-2000);
		I[level][15].sprite.setPosition(-2000,-2000);
		I[level][16].sprite.setPosition(-2000,-2000);
		if (level == 0)
		{
			score1 += 10;
		}
		if (level == 1)
		{
			score1 += 20;
		}
		if (level == 2)
		{
			score1 += 30;
		}
	}

}
bool Game::go_to_lvl2()
{
	alpha_count = 0;
	change_level = false;
	lvl2 = 0;
	for (int loop = 0; loop < 16; loop++)
	{
		if(I[level][loop].sprite.getPosition().y == -2000 && I[level][loop].sprite.getPosition().x == -2000)
		{
			alpha_count++;
		}
	}
	if (alpha_count == 16)
	{
		go_to_level2 = true;
		lvl2++;
	}
	if (go_to_level2 == true && lvl2 == 1)
	{
		change_level = true;
	}
	return change_level;
}
void Game::make_level3()
{
	int beto1 = 0;
	for (int loop = 0; loop < 50; loop++)
	{
		if (((M.sprite.getPosition().x > 900 || M.sprite.getPosition().x < -30 ||  M.sprite.getPosition().y < -30 ||  M.sprite.getPosition().y > 680)) &&((I[level][loop].sprite.getPosition().x <= -20) || (I[level][loop].sprite.getPosition().x >= 1100) || (I[level][loop].sprite.getPosition().y <= -40) || (I[level][loop].sprite.getPosition().y >= 680)))
			{
				beto1++;
			}
			if (beto1 == 50 && (count1 == 1 && shapes == 10))
			{
				count1++;
				shapes++;
			}
	}
	int teko = 0;
	for (int loop = 0; loop < 50; loop++)
	{
		if (((M.sprite.getPosition().x > 900 || M.sprite.getPosition().x < -30 ||  M.sprite.getPosition().y < -30 ||  M.sprite.getPosition().y > 680)) &&((I[level][loop].sprite.getPosition().x <= -20) || (I[level][loop].sprite.getPosition().x >= 1100) || (I[level][loop].sprite.getPosition().y <= -40) || (I[level][loop].sprite.getPosition().y >= 680)))
			{
				teko++;
			}
			if (teko == 50 && (count1 == 2 && shapes == 12))
			{
				count1++;
				shapes++;
			}
	}
	int teko1 = 0;
	for (int loop = 0; loop < 50; loop++)
	{
		if (((M.sprite.getPosition().x > 900 || M.sprite.getPosition().x < -30 ||  M.sprite.getPosition().y < -30 ||  M.sprite.getPosition().y > 680)) &&((I[level][loop].sprite.getPosition().x <= -20) || (I[level][loop].sprite.getPosition().x >= 1100) || (I[level][loop].sprite.getPosition().y <= -40) || (I[level][loop].sprite.getPosition().y >= 680)))
			{
				teko1++;
			}
			if (teko1 == 50 && (count1 == 3 && shapes == 14))
			{
				count1++;
				shapes++;
			}
	}
	int teko2 = 0;
	for (int loop = 0; loop < 50; loop++)
	{
		if (((M.sprite.getPosition().x > 900 || M.sprite.getPosition().x < -30 ||  M.sprite.getPosition().y < -30 ||  M.sprite.getPosition().y > 680)) &&((I[level][loop].sprite.getPosition().x <= -20) || (I[level][loop].sprite.getPosition().x >= 1100) || (I[level][loop].sprite.getPosition().y <= -40) || (I[level][loop].sprite.getPosition().y >= 680)))
			{
				teko2++;
			}
			if (teko2 == 50 && (count1 == 4 && shapes == 16))
			{
				count1++;
				shapes++;
			}
	}
	if (shapes == 17)
	{
		level = 2;
		enemy[0][2] = I[level];
		for (int loop = 0; loop < 50; loop++)
		{
			I[level][loop] = G;
			I[level][loop].lives = 3;
		}
		for (int loop = 0; loop < 50; loop++)
		{
			I[level][loop].sprite.setPosition(-3700,-3700);
		}
		I[level][0].sprite.setPosition(370,30);
		I[level][1].sprite.setPosition(395,20);
		I[level][2].sprite.setPosition(420,10);
		I[level][3].sprite.setPosition(445,5);
		I[level][4].sprite.setPosition(470,10);
		I[level][5].sprite.setPosition(495,20);
		I[level][6].sprite.setPosition(520,30);
		I[level][7].sprite.setPosition(545,20);
		I[level][8].sprite.setPosition(570,10);
		I[level][9].sprite.setPosition(595,5);
		I[level][10].sprite.setPosition(620,10);
		I[level][36].sprite.setPosition(645,20);
		I[level][37].sprite.setPosition(670,20);
		for (int loop = 17,loop2 = 0; loop < 26; loop2++,loop++)
		{
			I[level][loop].sprite.setPosition(320+(20*loop2),110+(20*loop2));
		}
		for (int loop = 26,loop2 = 0; loop < 36; loop2++,loop++)
		{
			I[level][loop].sprite.setPosition(520+(23*loop2),290-(20*loop2));
		}
		I[level][11].sprite.setPosition(695,50);
		I[level][12].sprite.setPosition(720,70);
		I[level][13].sprite.setPosition(735,90);
		I[level][14].sprite.setPosition(345,50);
		I[level][15].sprite.setPosition(320,70);
		I[level][16].sprite.setPosition(295,90);
		for (int loop = 38 , loop2 = 0; loop < 46;loop2++, loop++)
		{
			I[level][loop].sprite.setPosition(397+(35*loop2), 100);
		}
		I[level][46].sprite.setPosition(462+20,140);
		I[level][47].sprite.setPosition(497+20,140);
		I[level][48].sprite.setPosition(532+20,140);
		I[level][49].sprite.setPosition(497+20,200);
		shapes++;
		if (level == 0)
		{
			score1 += 10;
		}
		if (level == 1)
		{
			score1 += 20;
		}
		if (level == 2)
		{
			score1 += 30;
		}
	}
	if (shapes == 15)
	{
		level = 2;
		enemy[0][2] = I[level];
		for (int loop = 0; loop < 50; loop++)
		{
			I[level][loop] = G;
			I[level][loop].lives = 3;
		}
		for (int loop = 0; loop < 50; loop++)
		{
			I[level][loop].sprite.setPosition(-3700,-3700);
		}
		for (int loop = 0; loop < 11; loop++)
		{
			I[level][loop].sprite.setPosition(370+(25*loop), 30);
		}
		for (int loop = 35 , loop2 = 0; loop < 43;loop2++, loop++)
		{
			I[level][loop].sprite.setPosition(360+(35*loop2), 100);
		}
		I[level][43].sprite.setPosition(462+10,140);
		I[level][44].sprite.setPosition(497+10,140);
		I[level][45].sprite.setPosition(532+10,140);
		I[level][46].sprite.setPosition(497+10,200);
		for (int loop = 17,loop2 = 0; loop < 26; loop2++,loop++)
		{
			I[level][loop].sprite.setPosition(320+(20*loop2),110+(20*loop2));
		}
		for (int loop = 26,loop2 = 0; loop < 36; loop2++,loop++)
		{
			I[level][loop].sprite.setPosition(510+(20*loop2),290-(20*loop2));
		}
		I[level][11].sprite.setPosition(645,50);
		I[level][12].sprite.setPosition(670,70);
		I[level][13].sprite.setPosition(695,90);
		I[level][14].sprite.setPosition(345,50);
		I[level][15].sprite.setPosition(320,70);
		I[level][16].sprite.setPosition(295,90);
		shapes++;
		if (level == 0)
		{
			score1 += 10;
		}
		if (level == 1)
		{
			score1 += 20;
		}
		if (level == 2)
		{
			score1 += 30;
		}
	}
	if (shapes == 13)
	{
		level = 2;
		enemy[0][2] = I[level];
		for (int loop = 0; loop < 50; loop++)
		{
			I[level][loop] = G;
			I[level][loop].lives = 3;
		}
		for (int loop = 0; loop < 50; loop++)
		{
			I[level][loop].sprite.setPosition(-3700,-3700);
		}
		I[level][24].sprite.setPosition(472, 270);
		I[level][25].sprite.setPosition(497, 280);
		I[level][26].sprite.setPosition(522, 270);
		I[level][0].sprite.setPosition(472, 10);
		I[level][1].sprite.setPosition(497, 10);
		I[level][2].sprite.setPosition(522, 10);
		I[level][34].sprite.setPosition(462,80);
		I[level][35].sprite.setPosition(497,80);
		I[level][36].sprite.setPosition(532,80);
		I[level][37].sprite.setPosition(462,140);
		I[level][38].sprite.setPosition(497,140);
		I[level][39].sprite.setPosition(532,140);
		I[level][40].sprite.setPosition(462,170);
		I[level][41].sprite.setPosition(497,170);
		I[level][42].sprite.setPosition(532,170);
		I[level][43].sprite.setPosition(462,210);
		I[level][44].sprite.setPosition(497,210);
		I[level][45].sprite.setPosition(532,210);
		for (int loop = 3,loop2 = 1; loop < 6;loop2++, loop++)
		{
			I[level][loop].sprite.setPosition(522+(loop2*35),10+(loop2*10));
		}
		for (int loop = 9,loop2 = 1; loop < 12;loop2++, loop++)
		{
			I[level][loop].sprite.setPosition(472-(loop2*35),10+(loop2*10));
		}
		for (int loop = 12,loop2 = 1; loop < 18;loop2++, loop++)
		{
			if (loop <= 14)
			{
				I[level][loop].sprite.setPosition(367-(10*loop2),40+(loop2*30));
			}
			if (loop > 14)
			{
				I[level][loop].sprite.setPosition(297+(10*loop2),40+(loop2*30));
			}
		}
		for (int loop = 18,loop2 = 1; loop < 24;loop2++, loop++)
		{
			if (loop <=20)
			{
				I[level][loop].sprite.setPosition(627+(10*loop2),40+(loop2*30));
			}
			if (loop > 20)
			{
				I[level][loop].sprite.setPosition(697-(10*loop2),40+(loop2*30));
			}
		}
		for (int loop = 27,loop2 = 1; loop < 30;loop2++, loop++)
		{
			I[level][loop].sprite.setPosition(367+(loop2*35),240+(loop2*10));
		}
		for (int loop = 30,loop2 = 1; loop < 33;loop2++, loop++)
		{
			I[level][loop].sprite.setPosition(522+(loop2*35),270-(loop2*10));
		}
		shapes++;
		if (level == 0)
		{
			score1 += 10;
		}
		if (level == 1)
		{
			score1 += 20;
		}
		if (level == 2)
		{
			score1 += 30;
		}
	}
	if (shapes == 11)
	{
		level = 2;
		enemy[0][2] = I[level];
		for (int loop = 0; loop < 50; loop++)
		{
			I[level][loop] = G;
			I[level][loop].lives = 3;
		}
		for (int loop = 0; loop < 50; loop++)
		{
			I[level][loop].sprite.setPosition(-3700,-3700);
		}
		for (int loop = 0; loop < 7; loop++)
		{
			I[level][loop].sprite.setPosition(317+(60*loop),20+(52*loop));			/// Cross Sign
		}
		for (int loop = 7,loop2 = 0; loop < 14; loop2++,loop++)
		{
			if (loop != 10)
			{
				I[level][loop].sprite.setPosition(677-(60*loop2),20+(52*loop2));			/// Cross Sign
			}
		}
		for (int loop = 0,loop2 = 14; loop < 5; loop2++,loop++)
		{
			I[level][loop2].sprite.setPosition(377+(loop*60),20);
		}
		for (int loop = 0,loop2 = 21; loop < 5; loop2++,loop++)
		{
			I[level][loop2].sprite.setPosition(377+(loop*60),332);
		}
			I[level][26].sprite.setPosition(497,280);
			I[level][27].sprite.setPosition(497,72);
		shapes++;
		if (level == 0)
		{
			score1 += 10;
		}
		if (level == 1)
		{
			score1 += 20;
		}
		if (level == 2)
		{
			score1 += 30;
		}
	}
	if (shapes == 9)
	{
		level = 2;
		enemy[0][2] = I[level];
		for (int loop = 0; loop < 50; loop++)
		{
			I[level][loop] = G;
			I[level][loop].lives = 3;
		}
		for (int loop = 0; loop < 50; loop++)
		{
			I[level][loop].sprite.setPosition(-3700,-3700);
		}
		I[level][0].sprite.setPosition(497,20);
		for (int loop = 1; loop < 4; loop++)
		{
			I[level][loop].sprite.setPosition(497-(80*loop),20+(60*loop));
		}
		for (int loop = 4, loop2 =1; loop < 7; loop2++, loop++)
		{
			I[level][loop].sprite.setPosition(497+(80*loop2),20+(60*loop2));
		}
		for (int loop = 7,loop2 = 1; loop <= 15; loop2++, loop++)		/// Triangle
		{
			I[level][loop].sprite.setPosition(95+(80*loop2),270);
		}
		I[level][16].sprite.setPosition(497,80);
		I[level][17].sprite.setPosition(497,140);
		I[level][18].sprite.setPosition(417,140);
		I[level][19].sprite.setPosition(577,140);
		I[level][20].sprite.setPosition(497,200);
		I[level][21].sprite.setPosition(417,200);
		I[level][22].sprite.setPosition(577,200);
		I[level][23].sprite.setPosition(657,200);
		I[level][24].sprite.setPosition(337,200);
		shapes++;
		if (level == 0)
		{
			score1 += 10;
		}
		if (level == 1)
		{
			score1 += 20;
		}
		if (level == 2)
		{
			score1 += 30;
		}
	}
	if (monster_end == true && (M.sprite.getPosition().x > 900 || M.sprite.getPosition().x < 0 ||  M.sprite.getPosition().y < -30 ||  M.sprite.getPosition().y > 680)&& shapes == 8)
	{
		level = 2;
		enemy[0][2] = I[level];
		for (int loop = 0; loop < 50; loop++)
		{
			I[level][loop] = G;
			I[level][loop].lives = 3;
		}
		if (shapes == 8)
		{
			for (int loop = 0; loop < 50; loop++)
			{
				I[level][loop].sprite.setPosition(3000,3000);
			}
			for (int loop = 0; loop < 7; loop++)
			{
				I[level][loop].sprite.setPosition(250+(80*loop),100);
			}
			I[level][7].sprite.setPosition(250,180);
			for (int loop = 8,loop2 = 0; loop < 15; loop2++, loop++)		/// RECTANGLE
			{
				I[level][loop].sprite.setPosition(250+(80*loop2),260);
			}
		//	I[level][15].sprite.setPosition(250+(80*6),180);
			for (int loop = 16,loop2 = 1; loop < 22;loop2++, loop++)
			{
				I[level][loop].sprite.setPosition(250+(80*loop2),180);
			}
		}
	}
	int beto = 0;
	for (int loop = 0; loop < 50; loop++)
	{
		if (((M.sprite.getPosition().x > 900 || M.sprite.getPosition().x < -30 ||  M.sprite.getPosition().y < -30 ||  M.sprite.getPosition().y > 680)) &&((I[level][loop].sprite.getPosition().x <= -20) || (I[level][loop].sprite.getPosition().x >= 1100) || (I[level][loop].sprite.getPosition().y <= -40) || (I[level][loop].sprite.getPosition().y >= 680)))
		{
			beto++;
		}
		if (beto == 50 && count1 == 0)
		{
			count1++;
			shapes++;
		}
	}
}
void Game::call_dragon()
{
	enemy[2][0] = &dragon;
	enemy[2][0]->sprite.setScale(0.85,0.85);
	int teko3 = 0;
	for (int loop = 0; loop < 50; loop++)
	{
		if (((dragon.sprite.getPosition().x > 900 || dragon.sprite.getPosition().x < -30 ||  dragon.sprite.getPosition().y < -30 ||  dragon.sprite.getPosition().y > 680)) &&((I[level][loop].sprite.getPosition().x <= -20) || (I[level][loop].sprite.getPosition().x >= 1100) || (I[level][loop].sprite.getPosition().y <= -40) || (I[level][loop].sprite.getPosition().y >= 680)))
		{
			teko3++;
		}
		if (teko3 == 50 && (count1 == 5 && shapes == 18))
		{
			count1++;
			shapes++;
		}
	}
	if (shapes == 19)
	{
		dragon.sprite.setPosition(437,20);
		Bullet * b2 = b;
		int bullet_hit = 0;
		bullet_hit = M.collision(b2);
		b[bullet_hit].sprite_b.setPosition(-900,-900);
		dragon.sprite_F.setPosition(dragon.sprite.getPosition().x+80,dragon.sprite.getPosition().y+200);
		dragon.sprite_F.setRotation(45*time);
		shapes++;
		drag = true;
	}
	if (drag == true)
	{
		dragon_timer += time;
		if (dragon_timer >= 10)
		{
			dragon.sprite.setPosition(-908,-908);
			score1+=50;
		}
	}
	if (dragon.sprite_F.getPosition().x-37 <= p->sprite.getPosition().x && dragon.sprite_F.getPosition().x+37 >= p->sprite.getPosition().x)
	{
		explosion1.setPosition(p->sprite.getPosition().x+20,p->sprite.getPosition().y+10);
		explosion2.setPosition(p->sprite.getPosition().x+50,p->sprite.getPosition().y+20);
		explosion3.setPosition(p->sprite.getPosition().x+30,p->sprite.getPosition().y+30);
		explosion4.setPosition(p->sprite.getPosition().x-5,p->sprite.getPosition().y-5);
		if (timer - contact2 >= 1.5)
		{
			contact2 = time;
			p->lives--;
		}
		trigger = true;
	}
	if (trigger == true)
	{
		explosion1.setPosition(p->sprite.getPosition().x+20,p->sprite.getPosition().y+10);
		explosion2.setPosition(p->sprite.getPosition().x+50,p->sprite.getPosition().y+20);
		explosion3.setPosition(p->sprite.getPosition().x+30,p->sprite.getPosition().y+30);
		explosion4.setPosition(p->sprite.getPosition().x-5,p->sprite.getPosition().y-5);
	}
}
void Game::make_level2()
{
	for (int loop = 0; loop < 50; loop++)
	{
		I[level][loop].sprite.setPosition(3000,3000);
	}
	level = 1;
	for (int loop = 0; loop < 50; loop++)
	{
		I[1][loop] = B;
		I[1][loop].lives = 2;
	}
	enemy[0][1] = I[level];
	if (shapes == 5)
	{
		if (level == 0)
		{
			score1 += 10;
		}
		if (level == 1)
		{
			score1 += 20;
		}
		if (level == 2)
		{
			score1 += 30;
		}
		I[level][24].sprite.setPosition(472, 270);
		I[level][25].sprite.setPosition(497, 280);
		I[level][26].sprite.setPosition(522, 270);
		I[level][0].sprite.setPosition(472, 10);
		I[level][1].sprite.setPosition(497, 10);
		I[level][2].sprite.setPosition(522, 10);
		for (int loop = 3,loop2 = 1; loop < 6;loop2++, loop++)
		{
			I[level][loop].sprite.setPosition(522+(loop2*35),10+(loop2*10));
		}
		for (int loop = 9,loop2 = 1; loop < 12;loop2++, loop++)
		{
			I[level][loop].sprite.setPosition(472-(loop2*35),10+(loop2*10));
		}
		for (int loop = 12,loop2 = 1; loop < 18;loop2++, loop++)
		{
			if (loop <= 14)
			{
				I[level][loop].sprite.setPosition(367-(10*loop2),40+(loop2*30));
			}
			if (loop > 14)
			{
				I[level][loop].sprite.setPosition(297+(10*loop2),40+(loop2*30));
			}
		}
		for (int loop = 18,loop2 = 1; loop < 24;loop2++, loop++)
		{
			if (loop <=20)
			{
				I[level][loop].sprite.setPosition(627+(10*loop2),40+(loop2*30));
			}
			if (loop > 20)
			{
				I[level][loop].sprite.setPosition(697-(10*loop2),40+(loop2*30));
			}
		}
		for (int loop = 27,loop2 = 1; loop < 30;loop2++, loop++)
		{
			I[level][loop].sprite.setPosition(367+(loop2*35),240+(loop2*10));
		}
		for (int loop = 30,loop2 = 1; loop < 33;loop2++, loop++)
		{
			I[level][loop].sprite.setPosition(522+(loop2*35),270-(loop2*10));
		}
	}
	if (shapes == 6)
	{
		if (level == 0)
		{
			score1 += 10;
		}
		if (level == 1)
		{
			score1 += 20;
		}
		if (level == 2)
		{
			score1 += 30;
		}
		for (int loop = 0; loop < 11; loop++)
		{
			I[level][loop].sprite.setPosition(370+(25*loop), 30);
		}
		for (int loop = 17,loop2 = 0; loop < 26; loop2++,loop++)
		{
			I[level][loop].sprite.setPosition(320+(20*loop2),110+(20*loop2));
		}
		for (int loop = 26,loop2 = 0; loop < 36; loop2++,loop++)
		{
			I[level][loop].sprite.setPosition(510+(20*loop2),290-(20*loop2));
		}
		I[level][11].sprite.setPosition(645,50);
		I[level][12].sprite.setPosition(670,70);
		I[level][13].sprite.setPosition(695,90);
		I[level][14].sprite.setPosition(345,50);
		I[level][15].sprite.setPosition(320,70);
		I[level][16].sprite.setPosition(295,90);
	}
	if (shapes == 7)
	{
		if (level == 0)
		{
			score1 += 10;
		}
		if (level == 1)
		{
			score1 += 20;
		}
		if (level == 2)
		{
			score1 += 30;
		}
		I[level][0].sprite.setPosition(370,30);
		I[level][1].sprite.setPosition(395,20);
		I[level][2].sprite.setPosition(420,10);
		I[level][3].sprite.setPosition(445,5);
		I[level][4].sprite.setPosition(470,10);
		I[level][5].sprite.setPosition(495,20);
		I[level][6].sprite.setPosition(520,30);
		I[level][7].sprite.setPosition(545,20);
		I[level][8].sprite.setPosition(570,10);
		I[level][9].sprite.setPosition(595,5);
		I[level][10].sprite.setPosition(620,10);
		I[level][36].sprite.setPosition(645,20);
		I[level][37].sprite.setPosition(670,20);
		for (int loop = 17,loop2 = 0; loop < 26; loop2++,loop++)
		{
			I[level][loop].sprite.setPosition(320+(20*loop2),110+(20*loop2));
		}
		for (int loop = 26,loop2 = 0; loop < 36; loop2++,loop++)
		{
			I[level][loop].sprite.setPosition(520+(23*loop2),290-(20*loop2));
		}
		I[level][11].sprite.setPosition(695,50);
		I[level][12].sprite.setPosition(720,70);
		I[level][13].sprite.setPosition(735,90);
		I[level][14].sprite.setPosition(345,50);
		I[level][15].sprite.setPosition(320,70);
		I[level][16].sprite.setPosition(295,90);
	}
}
void Game::call_monster()
{
	int beto = 0;
	enemy[1][0] = &M;
	enemy[1][0]->sprite.setScale(0.15,0.15);
	bool no_invader = false;
	for (int loop = 0; loop < 50; loop++)
	{
		if ((I[level][loop].sprite.getPosition().x <= -20) || (I[level][loop].sprite.getPosition().x >= 1100) || (I[level][loop].sprite.getPosition().y <= -40) || (I[level][loop].sprite.getPosition().y >= 680))
		{
			beto++;
		}
	}
	if (beto == 50)
	{
		no_invader = true;
	}
	if (no_invader)
	{
		Bullet * b2 = b;
		int bullet_hit = 0;
		bullet_hit = M.collision(b2);
		b[bullet_hit].sprite_b.setPosition(-900,-900);
		add_delay += time;
		if (counter1 == 0)
		{
			M.sprite.setPosition(497,20);
			counter1++;
		}
		M.sprite.move(3*monster_move*time,0);
		M.fire_beam();
		if (M.sprite.getPosition().x > 860)
		{
			monster_move = -100;
		}
		if (M.sprite.getPosition().x < 0)
		{
			monster_move = 100;
		}
		monster_collide = false;
		monster_collide = enemy[1][0]->collision(p);
		if (monster_collide == true && (timer-invade >= 1.001))		/// invincble for 1 seconds after hitting monster
		{
			invade = timer;
			damage2.setPosition(p->sprite.getPosition().x-10,p->sprite.getPosition().y-10);
			collided = true;
			collide_time = 0;
			p->lives--;
		}
		if (damage2.getPosition().y > -80 && damage2.getPosition().y < 680 && collide_time <= 1.101)
		{
			collide_time+= time;
			damage2.setPosition(p->sprite.getPosition().x-10,p->sprite.getPosition().y-10);
		}
		if (collide_time >= 1)
		{
			damage2.setPosition(-200,-200);
		}
		if (M.sprite_F.getPosition().y >=-999 && M.sprite_F.getPosition().y < 2000)
		{
			if (M.sprite_F.getPosition().x-37 <= p->sprite.getPosition().x && M.sprite_F.getPosition().x+37 >= p->sprite.getPosition().x)
			{
				M.beam_time += time;
				explosion1.setPosition(p->sprite.getPosition().x,p->sprite.getPosition().y);
				explosion2.setPosition(p->sprite.getPosition().x+50,p->sprite.getPosition().y+20);
				explosion3.setPosition(p->sprite.getPosition().x+30,p->sprite.getPosition().y+30);
				explosion4.setPosition(p->sprite.getPosition().x-5,p->sprite.getPosition().y-5);
				if (M.beam_time >= 0.2)		// hit immunity to player
				{
					p->lives--;
					M.beam_time = 0;
				}
			}
			else
			{
				explosion1.setPosition(-900,-900);
				explosion2.setPosition(-900,-900);
				explosion3.setPosition(-900,-900);
				explosion4.setPosition(-900,-900);
			}
		}
	}
}
void Game::Fire_bomb()
{
	if (bomb1 == true)
			for (int loop = 0;loop < 50;loop++)
			{
				bomb[loop].sprite.move(0,250*time);
			}
			if (bomb1 == false)
			{
				for (int loop = 0; loop < 50; loop++)
				{
					bomb[loop].sprite.setPosition(I[level][loop].sprite.getPosition().x+20,I[level][loop].sprite.getPosition().y+55);
				}
			}
			for (int loop = 0; loop < 50; loop++)
			{
				if (bomb[loop].sprite.getPosition().y >= 980)
				{
					bomb1 = false;
				}
			}
			for (int loop = 0; loop < 50; loop++)
			{
				if (bomb[loop].sprite.getPosition().x+25 >= p->sprite.getPosition().x && bomb[loop].sprite.getPosition().x-60 <= p->sprite.getPosition().x && bomb[loop].sprite.getPosition().y-50 <= p->sprite.getPosition().y && bomb[loop].sprite.getPosition().y+25 >= p->sprite.getPosition().y)
				{
					explosion1.setPosition(p->sprite.getPosition().x+20,p->sprite.getPosition().y+10);
					explosion2.setPosition(p->sprite.getPosition().x+50,p->sprite.getPosition().y+20);
					explosion3.setPosition(p->sprite.getPosition().x+30,p->sprite.getPosition().y+30);
					explosion4.setPosition(p->sprite.getPosition().x-5,p->sprite.getPosition().y-5);
					if (timer-contact >= 0.5)
					{
						contact = timer;
						p->lives--;
					}
					trigger = true;
				}
			}
			if (trigger == true)
			{
				explosion1.setPosition(p->sprite.getPosition().x+20,p->sprite.getPosition().y+10);
				explosion2.setPosition(p->sprite.getPosition().x+50,p->sprite.getPosition().y+20);
				explosion3.setPosition(p->sprite.getPosition().x+30,p->sprite.getPosition().y+30);
				explosion4.setPosition(p->sprite.getPosition().x-5,p->sprite.getPosition().y-5);
			}
}
void Game::start_game()
{
	change_level = 0;
    srand(std::time(0));
    RenderWindow window(VideoMode(1060,680), "Space Wars");
    Clock clock;
   window.setKeyRepeatEnabled(false);
    while (window.isOpen())
    {
        time = clock.getElapsedTime().asSeconds();
        clock.restart();
        timer += time;
        random += time;
        bomb_fire += time;
        if (fire_counter >= 4.2)
        {
        	fire_counter = 0;
        	fire_power = false;
        	for (int loop = 0; loop < 7; loop++)
        	{
        		for (int loop2= 0 ; loop2 < 20; loop2++)
        		{
        			power_up[loop][loop2].sprite_b.setPosition(-900,-900);
        		}
        	}
        }
        monster_end = false;
      if (random >= 22)
	  {
		random = 0;
	  }
      if (bomb_fire >= 3)
      {
		bomb1 = true;
		bomb_fire = 0;
		trigger = false;
		explosion1.setPosition(-400,-400);
		explosion2.setPosition(-400,-400);
		explosion3.setPosition(-400,-400);
		explosion4.setPosition(-400,-400);
      }
      if (add_delay >= 10.001)
      {
    	  add_delay = 0;
    	  monster_end = true;
    	  M.sprite.setPosition(-3500,-3500);
    	  score1+= 40;
      }
 	Event e;
        while (window.pollEvent(e))
        {
            if (e.type == Event::Closed) // If cross/close is clicked/pressed
                window.close(); //close the game
        }
        if ((!(Keyboard::isKeyPressed(Keyboard::Left)) && (!(Keyboard::isKeyPressed(Keyboard::Right)))))
        {
        	 p->sprite.setTexture(p->tex);			// reset left and right when key is let go
        	 p->sprite.setScale(0.85,0.85);
        }
    	if (Keyboard::isKeyPressed(Keyboard::P))
    	{
    		 RenderWindow window3(VideoMode(1,1), "Space Wars");
    		   while (window3.isOpen())
    		    {
    				Event e;
					while (window.pollEvent(e))
					{
						if (e.type == Event::Closed) // If cross/close is clicked/pressed
							window3.close(); //close the game
					}
					if (Keyboard::isKeyPressed(Keyboard::U))
					{
						window3.close();
					}
    		    }
    	}
	if (Keyboard::isKeyPressed(Keyboard::Left))
		{//If left key is pressed
            p->move("l");
		}// Player will move to left

	if (Keyboard::isKeyPressed(Keyboard::Right))
		{// If right key is pressed
			p->move("r"); //player will move to right
		}
    if (Keyboard::isKeyPressed(Keyboard::Up)) //If up key is pressed
            p->move("u");    //playet will move upwards
	if (Keyboard::isKeyPressed(Keyboard::Down)) // If down key is pressed
            p->move("d");  //player will move downwards
	if (p->lives <= 0)
	{
		window.close();
		Texture t1;
		t1.loadFromFile("img/game_over.jpg");
		Sprite s1;
		s1.setTexture(t1);
		RenderWindow window2(VideoMode(320,480), "Game Over");
		Clock clock;
	   window2.setKeyRepeatEnabled(false);
		while (window2.isOpen())
		{
			time = clock.getElapsedTime().asSeconds();
			timer += time;
			clock.restart();
			Event e;
		while (window2.isOpen())
		{
			time = clock.getElapsedTime().asSeconds();
			timer += time;
			clock.restart();
			Event e;
			while (window2.pollEvent(e))
			{
				if (e.type == Event::Closed) // If cross/close is clicked/pressed
					{window2.close();return ;} //close the game
			}
			if (Keyboard::isKeyPressed(Keyboard::Enter))
			{
				ofstream Myfile;
				Myfile.open("scores.txt",ios::app);
				Myfile << score1 << endl;
				Myfile.close();
				window.close();
				window2.close();
				return;
			}
			window2.clear(Color::Black);
			window2.draw(s1);
			window2.display();
			}
		}
	}
	////////////////////////////////////////////////
	/////  Call your functions here            ////
/*---1---*/		make_addon();
/*---2---*/		handle_addon();
/*---3---*/		make_bullet();
/*---4---*/		handle_bullet();
			if (level_detect == false)
			{
/*---5---*/		make_level1();
				shapes++;
			}
				level_detect = true;
				change_lvl = false;
/*---6---*/		invader_player_collide();
/*---7---*/		invader_bullet_collide();
/*---8---*/		change_lvl = go_to_lvl2();
/*---9---*/		handle_levels();		/*---10---*/ 	/// make_level2() inside handle level function
/*---11---*/	call_monster();
/*---12---*/	make_level3();
/*---13---*/	call_dragon();
/*---14---*/	Fire_bomb();
	//////////////////////////////////////////////
	background.move(0,m*time);
	if (background.getPosition().y + (680) > 681 && m > 0)
	{
		m = -4000;
		//background.setPosition(0,-1480);
	}
	if (background.getPosition().y < -1480)
	{
		m = 200;
	}
	damage.move(0,250*time);
	window.clear(Color::Black); //clears the screen
	window.draw(background);  // setting background
	window.draw(p->sprite);   // setting player on screen
	for (int loop = 0; loop < 20; loop++)
	{
		if (firing == false)
		window.draw(b[loop].sprite_b);
	}
	for (int loop = 0; loop < 7; loop++)
	{
		for (int loop2= 0; loop2 < 20; loop2++)
		{
			window.draw(power_up[loop][loop2].sprite_b);
		}
	}
	window.draw(power.sprite);
	if (shapes == 20)
	{
		dragon.sprite_F.move(3*dw*time,0);
		if (dragon.sprite_F.getPosition().x <= 0)
		{
			dw = 100;
		}
		if (dragon.sprite_F.getPosition().x >= 980)
		{
			dw = -100;
		}
		if (dragon_timer >= 10)
		{
			dragon.sprite_F.setPosition(-908,-908);
		}
	}
	s = to_string(score1);
	Text tex("Score: ", font);
	Text tex2("Lives: ", font);
	Text tex3(to_string(p->lives), font);
	Text tex4("Level: ", font);
	Text tex5(to_string(level+1), font);
	tex2.setCharacterSize(24);
	tex2.setStyle(sf::Text::Bold);
	tex2.setFillColor(sf::Color::Red);
	tex3.setCharacterSize(24);
	tex3.setStyle(sf::Text::Bold);
	tex3.setFillColor(sf::Color::Red);
	tex4.setCharacterSize(24);
	tex4.setStyle(sf::Text::Bold);
	tex4.setFillColor(sf::Color::Red);
	tex5.setCharacterSize(24);
	tex5.setStyle(sf::Text::Bold);
	tex5.setFillColor(sf::Color::Red);
	tex.setCharacterSize(24);
	tex.setStyle(sf::Text::Bold);
	tex.setFillColor(sf::Color::Red);
	text.setString(s);
	text.setPosition(100,10);
	tex.setPosition(5,10);
	tex2.setPosition(150,10);
	tex3.setPosition(250,10);
	tex4.setPosition(5,50);
	tex5.setPosition(100,50);
	window.draw(D.sprite);
	window.draw(damage);
	window.draw(L.sprite);
	window.draw(F.sprite);
	window.draw(fires);
	window.draw(damage2);
	window.draw(M.sprite);
	window.draw(M.sprite_F);
	window.draw(dragon.sprite);
	window.draw(explosion1);
	window.draw(explosion2);
	window.draw(explosion3);
	window.draw(explosion4);
	window.draw(dragon.sprite_F);
	window.draw(text);
	window.draw(tex);
	window.draw(tex2);
	window.draw(tex3);
	window.draw(tex4);
	window.draw(tex5);
	for (int loop = 0; loop < 50; loop++)
	{
		window.draw(I[level][loop].sprite);
		window.draw(bomb[loop].sprite);
	}
	window.display();  //Displying all the sprites
    }

delete p;
p = NULL;
}

Game::~Game()
{

}


