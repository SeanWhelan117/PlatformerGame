#include "SFML/Graphics.hpp"
#include <iostream>
#include <time.h>
#include <stdlib.h>

//Author - Se�n Whelan


class Game
{
public:

	Game();
	void run();


protected:

	sf::Font m_font;
	sf::Text m_gameText;


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
