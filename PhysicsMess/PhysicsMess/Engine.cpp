#include "Engine.h"


Engine::Engine()
{
	// Получаем разрешение экрана, создаем окно SFML и View
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
	// Расчет времени
	Clock clock;

	window.setVerticalSyncEnabled(true);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			// Кроме обычного способа наше окно будет закрываться по нажатию на Escape
			if (event.type == sf::Event::Closed ||
				(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape))
			{
				window.close();
			}
				
		}
		// Перезапускаем таймер и записываем отмеренное время в dt
		
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
	// Стираем предыдущий кадр
	window.clear(Color::White);

	if (ballcnt != 0)
	{
		for (int i = 0; i < ballcnt; i++)
		{
			window.draw(balls[i].circle);
		}
	
	}

	// Отображаем все, что нарисовали
	window.display();
}