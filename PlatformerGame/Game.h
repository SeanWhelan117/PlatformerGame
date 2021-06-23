#include "SFML/Graphics.hpp"
#include <iostream>
#include <time.h>
#include <stdlib.h>


#include "MainMenu.h"
#include "GameState.h"
#include "Player.h"

//Author - Seán Whelan


class Game
{
public:

	Game();
	void run();

	MainMenu menu;
	Player player;

protected:

	sf::Font m_font;
	sf::Text m_gameText;

	GameState m_gameState{ GameState::mainmenu };

	void update(double dt);
	void render();
	void processEvents();

	/// <summary>
	/// @brief Handles all user input.
	/// </summary>
	/// <param name="event">system event</param>
	void processGameEvents(sf::Event&);

	// main window
	sf::RenderWindow m_window;

};

