#include "Player.h"

Player::Player()
{
	m_player.setFillColor(sf::Color::Black);
	m_player.setRadius(10);
	m_player.setOrigin(5,5);
	m_player.setPosition(200, 200);
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
