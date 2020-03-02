#include "Ball.h"
#include <iostream>
using namespace sf;


Ball::Ball()
{
	this->vx = -1000;
	this->vy = 50;
	this->t = 0;
	this->mass = 10 + rand() % 100;
	this->r = 0.5*mass;
	this->circle.setRadius(r);
	this->circle.setFillColor(Color::Blue);
	this->circle.setOutlineColor(Color::Black);
	this->circle.setOutlineThickness(1);
	this->circle.setOrigin(r, r);
	this->collisionFixx = 0;
	this->collisionFixy = 0;

	
	this->font.loadFromFile("../19104.ttf");
	this->balltext.setFont(font);
	this->balltext.setCharacterSize(20);
}

void Ball::create(Vector2i mpos, int counter)
{
	this->circle.setPosition(mpos.x, mpos.y);
	this->balltext.setString(std::to_string(counter));
	this->balltext.setPosition(mpos.x, mpos.y);
	//draw();
}






void Ball::collide(sf::RenderWindow* window, float g, float time)
{
	if (((this->circle.getPosition().x - this->r) <= 0) || ((this->circle.getPosition().x + this->r) >= window->getSize().x))
	{
		if(collisionFixx == 0) vx *= -0.75;
		if (((this->circle.getPosition().x - this->r <= 0) && vx>0) || ((this->circle.getPosition().x + this->r) >= window->getSize().x) && vx<0) collisionFixx = 1;
	}
	else collisionFixx = 0;
	if ((((this->circle.getPosition().y + this->r) > window->getSize().y)) /*|| ((this->circle.getPosition().y - this->r) == 0)*/)
	{
		if (collisionFixy == 0)
		{
			vy *= -0.9;
		}
		if (vy<0) collisionFixy = 1;
	}
	else
	{
		this->vy += g * time;
		collisionFixy = 0;
	}
}

void Ball::update(float time, float g, sf::RenderWindow* window)
{
	this->circle.move(vx*time, vy*time);
	this->balltext.move(vx * time, vy * time);
	if ((this->circle.getPosition().y + this->r > (window->getSize().y - 2)) && ((vy < 30) && (vy > -30))) vy = vy/2 /*- g * time*/;
	
	this->collide(window, g, time);
}


