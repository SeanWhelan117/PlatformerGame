#include "Game.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
//Author - Seán Whelan


//updates per milliseconds
static double const MS_PER_UPDATE = 10.0;


Game::Game()
	: m_window(sf::VideoMode(1440, 900, 32), "SFML Playground", sf::Style::Default)
{
	m_window.setVerticalSyncEnabled(true);

	/*if (!m_font.loadFromFile("arial.ttf"))
	{
		std::cout << "Error loading font..." << std::endl;

	}*/

	

}

////////////////////////////////////////////////////////////
void Game::run()
{
	sf::Clock clock;
	sf::Int32 lag = 0;

	while (m_window.isOpen())
	{
		sf::Time dt = clock.restart();

		lag += dt.asMilliseconds();

		processEvents();

		while (lag > MS_PER_UPDATE)
		{
			update(lag);
			lag -= MS_PER_UPDATE;
		}
		update(lag);

		render();
	}

	//menu.loadAssets();
}



////////////////////////////////////////////////////////////
void Game::processEvents()
{
	sf::Event event;
	while (m_window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			m_window.close();
		}
		//processGameEvents(event);
	}
}

////////////////////////////////////////////////////////////
void Game::processGameEvents(sf::Event& event)
{

	if (sf::Event::KeyPressed == event.type)
	{
		switch (event.key.code)
		{
		case sf::Keyboard::Escape:
			m_window.close();
			break;

		default:
			break;
		}
	}
}

////////////////////////////////////////////////////////////
void Game::update(double dt)
{
	

	if (m_gameState == GameState::mainmenu) //what happens when the game is currently on the main menu
	{
		menu.update(dt, m_gameState);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Tab)) //return to mainmenu
	{
		m_gameState = GameState::mainmenu;
	}

	if (m_gameState == GameState::gamePlay)
	{
		player.update(dt);
	}

}

////////////////////////////////////////////////////////////
void Game::render()
{
	m_window.clear(sf::Color::Blue);

	if (m_gameState == GameState::mainmenu)
	{
		menu.render(m_window);
	}

	if (m_gameState == GameState::gamePlay)
	{
		//m_window.clear(sf::Color::Green);
		player.render(m_window);

	}

	if (m_gameState == GameState::instructions)
	{
		m_window.clear(sf::Color::Red);
	}

	if (m_gameState == GameState::chooseStuff)
	{
		m_window.clear(sf::Color::Magenta);
	}

	if (m_gameState == GameState::endGame)
	{
		m_window.close();
	}

	m_window.display();
}

