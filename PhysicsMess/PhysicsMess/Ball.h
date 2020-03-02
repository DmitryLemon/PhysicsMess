#pragma once
#include <SFML/Graphics.hpp>

class Ball 
{
private:
	
	float vx, vy; //velocity components
	float t; //temperature component
	float r; //radius
	float mass;
	int collisionFixx, collisionFixy;

public:
	Ball();
	sf::CircleShape circle;
	sf::Font font;
	sf::Text balltext;
	//void draw();
	void create(sf::Vector2i mpos, int counter);
	void collide(sf::RenderWindow* window, float g, float time);



	void update(float dtAsSeconds, float g, sf::RenderWindow* window);




};