#include "Player.h"

Player::Player()
{
	loadAssets();

	//Temporary player is just a black square
	/*m_player.setFillColor(sf::Color::Black);
	m_player.setRadius(10);
	m_player.setOrigin(5,5);
	m_player.setPosition(200, 200);*/

	m_player.setTexture(idleRight);
	m_player.setPosition(300, 300);
	m_player.setScale(1, 1);



}

void Player::loadAssets()
{

	//idle Textures
	if (!idleUp.loadFromFile("ASSETS/SPRITES/PLAYER/fox_idle_up.png"))
	{
		std::cout << "Error with player idle up file";
	}

	if (!idleDown.loadFromFile("ASSETS/SPRITES/PLAYER/fox_idle_down.png"))
	{
		std::cout << "Error with player idle down file";
	}

	if (!idleLeft.loadFromFile("ASSETS/SPRITES/PLAYER/fox_idle_left.png"))
	{
		std::cout << "Error with player idle left file";
	}

	if (!idleRight.loadFromFile("ASSETS/SPRITES/PLAYER/fox_idle_right.png"))
	{
		std::cout << "Error with player idle right file";
	}

	//Walking textures

	if (!walkingUp.loadFromFile("ASSETS/SPRITES/PLAYER/fox_walking_up.png"))
	{
		std::cout << "Error with player walking up file";
	}

	if (!walkingDown.loadFromFile("ASSETS/SPRITES/PLAYER/fox_walking_down.png"))
	{
		std::cout << "Error with player walking down file";
	}

	if (!walkingLeft.loadFromFile("ASSETS/SPRITES/PLAYER/fox_walking_left.png"))
	{
		std::cout << "Error with player walking left file";
	}

	if (!walkingRight.loadFromFile("ASSETS/SPRITES/PLAYER/fox_walking_right.png"))
	{
		std::cout << "Error with player walking right file";
	}

		
}

void Player::update(double dt)
{
	checkForKeyInput();
}

void Player::render(sf::RenderWindow& t_window)
{
	t_window.draw(m_player);

}

void Player::checkForKeyInput()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		m_player.move(-1, 0);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		m_player.move(1, 0);
	}
}


