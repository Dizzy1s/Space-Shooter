Commands for compiling and running the sfml code:

g++ -c main.cpp Bullet.cpp Add_on.cpp Danger.cpp Game.cpp Lives.cpp Spaceship.cpp Menu.cpp Fire.cpp Enemy.cpp Invader.cpp Alpha.cpp Beta.cpp Gamma.cpp Monster.cpp Dragon.cpp Bomb.cpp PowerUp.cpp

g++ main.o bullet.o Add_on.o Danger.o Game.o Lives.o Spaceship.o Menu.o Fire.o  Enemy.o Invader.o Alpha.o Beta.o Gamma.o  Monster.o Dragon.o Bomb.o PowerUp.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system

./sfml-app
