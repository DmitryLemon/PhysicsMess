#pragma once

#include "Ball.h"

using namespace sf;

class Engine
{
private:

	RenderWindow window;

	float g = 980;
	static const int maxballs = 1000;
	Ball balls[maxballs];
	int ballcnt;
	int flag;
	void input();
	void update(float dtAsSeconds);
	void draw();

public:
	// Конструктор движка
	Engine();


	// Функция старт вызовет все приватные функции
	void start();

};