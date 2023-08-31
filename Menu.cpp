/*
 * Menu.cpp
 *
 *  Created on: May 11, 2023
 *      Author: moaz
 */
#include "Menu.h"

Menu::Menu()
{
	time = 0;
	timer = 0;
	tex.loadFromFile("img/bg2.jpg");
	t1.loadFromFile("img/inst.jpeg");
	s1.setTexture(t1);
	sprite.setTexture(tex);
	sprite.move(-60,-50);
	font.loadFromFile("img/arial.ttf");
	score1 = 0;
	score2 = 0;
	score3 = 0;
	score4 = 0;
	score5 = 0;
}
void Menu::high_score()
{
	ifstream Myfile("scores.txt", ios::in);
	if (!Myfile)
	{
		cout << "File not Found!" << endl;
	}
	while (!Myfile.eof())
	{
		Myfile >> score1;
		Myfile >> score2;
		Myfile >> score3;
		Myfile >> score4;
		Myfile >> score5;
	}
	Myfile.close();
	int arr[5];
	arr[0] = score1;
	arr[1] = score2;
	arr[2] = score3;
	arr[3] = score4;
	arr[4] = score5;
	int temp = 0;
	for (int loop2 = 0; loop2 <4; loop2++)
	for (int loop = 0; loop < 4; loop++)
	{
		if (arr[loop+1] > arr[loop])
		{
			temp = arr[loop];
			arr[loop] = arr[loop+1];
			arr[loop+1] = temp;
		}
	}
	ofstream newfile;
	newfile.open("high_Score.txt");
	for (int loop = 0; loop < 5; loop++)
	{
		newfile << arr[loop] << endl;
	}
	score1 = arr[0];
	score2 = arr[1];
	score3 = arr[2];
	score4 = arr[3];
	score5 = arr[4];
	newfile.close();
}
void Menu::display_menu()
{
	high_score();
	  srand(std::time(0));
	    RenderWindow window(VideoMode(320,480), "Starting Screen");
	    Clock clock;
	   window.setKeyRepeatEnabled(false);
	    while (window.isOpen())
	    {
	    	time = clock.getElapsedTime().asSeconds();
	    	timer += time;
	    	clock.restart();
			Event e;
			while (window.pollEvent(e))
			{
				if (e.type == Event::Closed) // If cross/close is clicked/pressed
					{window.close();exit(0);} //close the game
			}
			if (Keyboard::isKeyPressed(Keyboard::P))
			{
				window.close();
			}
			if (Keyboard::isKeyPressed(Keyboard::H))
			{
				RenderWindow window3(VideoMode(320,480), "HighScore");
					Clock clock;
				   window3.setKeyRepeatEnabled(false);
					while (window3.isOpen())
					{
						Text tex;
						tex.setFont(font);
						tex.setCharacterSize(24);
						tex.setStyle(sf::Text::Bold);
						tex.setFillColor(sf::Color::Red);
						tex.setString(to_string(score1));
						Text tex2;
						tex2.setFont(font);
						tex2.setCharacterSize(24);
						tex2.setStyle(sf::Text::Bold);
						tex2.setFillColor(sf::Color::Red);
						tex2.setString(to_string(score2));
						Text tex3;
						tex3.setFont(font);
						tex3.setCharacterSize(24);
						tex3.setStyle(sf::Text::Bold);
						tex3.setFillColor(sf::Color::Red);
						tex3.setString(to_string(score3));
						Text tex4;
						tex4.setFont(font);
						tex4.setCharacterSize(24);
						tex4.setStyle(sf::Text::Bold);
						tex4.setFillColor(sf::Color::Red);
						tex4.setString(to_string(score4));
						Text tex5;
						tex5.setFont(font);
						tex5.setCharacterSize(24);
						tex5.setStyle(sf::Text::Bold);
						tex5.setFillColor(sf::Color::Red);
						tex5.setString(to_string(score5));
						time = clock.getElapsedTime().asSeconds();
						timer += time;
						clock.restart();
						Event e;
						while (window3.pollEvent(e))
						{
							if (e.type == Event::Closed) // If cross/close is clicked/pressed
								{window3.close();} //close the game
						}
						if (Keyboard::isKeyPressed(Keyboard::O))
						{
							window3.close();
						}
						if (Keyboard::isKeyPressed(Keyboard::Q))
						{
							window3.close();
						}
						tex.setPosition(40,10);
						tex2.setPosition(40,40);
						tex3.setPosition(40,70);
						tex4.setPosition(40,100);
						tex5.setPosition(40,130);
						window3.clear(Color::Black);
						window3.draw(tex);
						window3.draw(tex2);
						window3.draw(tex3);
						window3.draw(tex4);
						window3.draw(tex5);
						window3.display();
					}
			}
			if (Keyboard::isKeyPressed(Keyboard::Q))
			{
				window.close();
				exit(0);
			}
			if (Keyboard::isKeyPressed(Keyboard::I))
			{
				  srand(std::time(0));
				RenderWindow window2(VideoMode(320,480), "Starting Screen");
				Clock clock;
			   window2.setKeyRepeatEnabled(false);
				while (window2.isOpen())
				{
					time = clock.getElapsedTime().asSeconds();
					timer += time;
					clock.restart();
					Event e;
					while (window2.pollEvent(e))
					{
						if (e.type == Event::Closed) // If cross/close is clicked/pressed
							{window2.close();} //close the game
					}
					if (Keyboard::isKeyPressed(Keyboard::O))
					{
						window2.close();
					}
					if (Keyboard::isKeyPressed(Keyboard::Q))
					{
						window2.close();
					}
					window2.clear(Color::Black);
					window2.draw(s1);
					window2.display();
				}
			}
			window.clear(Color::Black);
			window.draw(sprite);
			window.display();
	    }
    Game g;
//display menu screen here

// add functionality of all the menu options here

//if Start game option is chosen

    g.start_game();

}
Menu::~Menu()
{

}
