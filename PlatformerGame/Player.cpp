#include "Player.h"

Player::Player()
{
	loadAssets();

	//Temporary player is just a black square
	/*m_player.setFillColor(sf::Color::Black);
	m_player.setRadius(10);
	m_player.setOrigin(5,5);
	m_player.setPosition(200, 200);*/

	if (currentAnimState == PlayerAnimState::idleRight)
	{
		m_player.setTexture(idleRight);
	}

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
	checkAnimState();
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
		moving = true;
		currentAnimState = PlayerAnimState::walkingLeft;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		m_player.move(1, 0);
		moving = true;
		currentAnimState = PlayerAnimState::walkingRight;
	}
	else
	{
		moving = false;
	}

	/*if (currentAnimState == PlayerAnimState::walkingRight)
	{
		
	}*/

}

void Player::checkAnimState()
{
	if (currentAnimState == PlayerAnimState::walkingRight)
	{
		if (moving == true)
		{
			animatePlayer(currentAnimState);
		}
		else
		{
			currentAnimState = PlayerAnimState::idleRight;
		}
	}
	
	if (currentAnimState == PlayerAnimState::walkingLeft)
	{
		if (moving == true)
		{
			animatePlayer(currentAnimState);
		}
		else
		{
			currentAnimState = PlayerAnimState::idleLeft;
		}

	}
	
	/*if (currentAnimState == PlayerAnimState::idleRight)
	{
		m_player.setTexture(idleRight);
	}
	
	if (currentAnimState == PlayerAnimState::idleLeft)
	{
		m_player.setTexture(idleLeft);
	}*/


}

void Player::animatePlayer(PlayerAnimState t_currentAnimState)
{
	if (t_currentAnimState == PlayerAnimState::walkingRight)
	{
		m_player.setTexture(walkingRight); // set the correct texture sheet
	}
	else if (t_currentAnimState == PlayerAnimState::walkingLeft)
	{
		m_player.setTexture(walkingLeft); // set the correct texture sheet
	}

	totalElapsed++;

	if (totalElapsed > 16)
	{
		totalElapsed = 0;
		animationframe++;

		if (animationframe > 3)
		{
			animationframe = 0;
		}

	}

	int col = animationframe % 3; // 3 columns of sprites
	int row = animationframe / 4; // 4 rows of sprites
	rectSourceSprite.height = 25; // height / width is gotten with the formula :: totalImageWidth / columns = width and  totalImageHeight / rows = height
	rectSourceSprite.width = 47;
	rectSourceSprite.left = col * rectSourceSprite.width;
	rectSourceSprite.top = row * rectSourceSprite.height;
	m_player.setTextureRect(rectSourceSprite);

}




