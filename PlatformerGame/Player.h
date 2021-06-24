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

	void loadAssets();

private:

	//sf::CircleShape m_player;

	sf::Sprite m_player;

	//Idle textures
	sf::Texture idleLeft;
	sf::Texture idleRight;
	sf::Texture idleUp;
	sf::Texture idleDown;

	//Walking Textures
	sf::Texture walkingLeft;
	sf::Texture walkingRight;
	sf::Texture walkingUp;
	sf::Texture walkingDown;

	//Jumping Textures
	//Attacking Textures
	//



};

