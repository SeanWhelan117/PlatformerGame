#pragma once
#include <iostream>
#include <SFML\Graphics.hpp>

class Player
{
public:
	Player();

	void update(double dt);
	void render(sf::RenderWindow& t_window);
	
	void checkForKeyInput();

private:

	sf::CircleShape m_player;

};

