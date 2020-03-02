#include "Engine.h"


Engine::Engine()
{
	// �������� ���������� ������, ������� ���� SFML � View
	Vector2f resolution;
	resolution.x = VideoMode::getDesktopMode().width;
	resolution.y = VideoMode::getDesktopMode().height;

	window.create(VideoMode(resolution.x, resolution.y),
		"PhysicsMess",
		Style::Fullscreen);

	ballcnt = 0;
	flag = 1;
}



void Engine::start()
{
	// ������ �������
	Clock clock;

	window.setVerticalSyncEnabled(true);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			// ����� �������� ������� ���� ���� ����� ����������� �� ������� �� Escape
			if (event.type == sf::Event::Closed ||
				(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape))
			{
				window.close();
			}
				
		}
		// ������������� ������ � ���������� ���������� ����� � dt
		
		input();

		Time dt = clock.restart();
		float dtAsSeconds = dt.asSeconds();

		update(dtAsSeconds);
		draw();
	}


}


void Engine::input()
{
	if ((Mouse::isButtonPressed(Mouse::Left)) && flag==0)
	{
		Vector2i mpos = Mouse::getPosition(window);
		if (ballcnt < maxballs)
		{
			balls[ballcnt].create(mpos, ballcnt+1);
			ballcnt += 1;
		}
		flag = 1;
	}
	if (!(Mouse::isButtonPressed(Mouse::Left))) flag = 0;
}


void Engine::update(float dtAsSeconds)
{
	if (ballcnt != 0)
	{
		for (int i = 0; i < ballcnt; i++)
		{
			balls[i].update(dtAsSeconds, g, &window);
		}
	}
}


void Engine::draw()
{
	// ������� ���������� ����
	window.clear(Color::White);

	if (ballcnt != 0)
	{
		for (int i = 0; i < ballcnt; i++)
		{
			window.draw(balls[i].circle);
		}
	
	}

	// ���������� ���, ��� ����������
	window.display();
}