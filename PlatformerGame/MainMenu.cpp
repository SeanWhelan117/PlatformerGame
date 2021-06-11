#include "MainMenu.h"

MainMenu::MainMenu()
{
	std::cout << "Menu Created..." << std::endl;

	int buttonPosX = 600;
	int buttonPosY = 200;
	for (int i = 0; i < MAX_BUTTONS; i++)
	{
		buttons[i].setFillColor(sf::Color::Red);
		buttons[i].setSize(sf::Vector2f(200, 50));
		buttonPosY = buttonPosY + 120;
		buttons[i].setPosition(sf::Vector2f(buttonPosX, buttonPosY));
		
	}
	// Button Locations::

	// 600, 320
	// 600, 440
	// 600, 560
	// 600, 680

	loadAssets();
	m_buttonOneText.Bold;
	m_buttonOneText.setFont(m_font);
	m_buttonOneText.setCharacterSize(32u);
	m_buttonOneText.setPosition(600, 320);
	m_buttonOneText.setFillColor(sf::Color::Black);
	m_buttonOneText.setString("Play");

	m_buttonTwoText.Bold;
	m_buttonTwoText.setFont(m_font);
	m_buttonTwoText.setCharacterSize(32u);
	m_buttonTwoText.setPosition(600, 440);
	m_buttonTwoText.setFillColor(sf::Color::Black);
	m_buttonTwoText.setString("Instructions");

	m_buttonThreeText.Bold;
	m_buttonThreeText.setFont(m_font);
	m_buttonThreeText.setCharacterSize(32u);
	m_buttonThreeText.setPosition(600, 560);
	m_buttonThreeText.setFillColor(sf::Color::Black);
	m_buttonThreeText.setString("Choose Stuff");

	m_buttonFourText.Bold;
	m_buttonFourText.setFont(m_font);
	m_buttonFourText.setCharacterSize(32u);
	m_buttonFourText.setPosition(600, 680);
	m_buttonFourText.setFillColor(sf::Color::Black);
	m_buttonFourText.setString("Exit Game");
}

void MainMenu::loadAssets()
{
	if (!m_font.loadFromFile("arial.ttf"))
	{
		std::cout << "Error loading font..." << std::endl;
	}

}


void MainMenu::update(double dt)
{
	
	
	mouseCollision(mousePos);

}

void MainMenu::render(sf::RenderWindow& t_window)
{
	mousePos = sf::Mouse::getPosition(t_window);
	//std::cout << "Mouse x = " << mousePos.x << "Mouse y = "  << mousePos.y << std::endl;

	for (int i = 0; i < MAX_BUTTONS; i++)
	{
		t_window.draw(buttons[i]);
	}

	t_window.draw(m_buttonOneText);
	t_window.draw(m_buttonTwoText);
	t_window.draw(m_buttonThreeText);
	t_window.draw(m_buttonFourText);
}

void MainMenu::mouseCollision(sf::Vector2i t_mousePos)
{

	if (t_mousePos.x < 800 && t_mousePos.x > 600)
	{
		if (t_mousePos.y > 320 && t_mousePos.y < 370)
		{
			buttons[0].setFillColor(sf::Color::Yellow);
			buttons[0].setScale(1.25, 1.25);
			m_buttonOneText.setScale(1.25, 1.25);

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				std::cout << "Play pressed" << std::endl;
			}
		}
		else if (t_mousePos.y > 440 && t_mousePos.y < 490)
		{
			buttons[1].setFillColor(sf::Color::Yellow);
			buttons[1].setScale(1.25, 1.25);
			m_buttonTwoText.setScale(1.25, 1.25);

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				std::cout << "Instructions pressed" << std::endl;
			}

		}
		else if (t_mousePos.y > 560 && t_mousePos.y < 610)
		{
			buttons[2].setFillColor(sf::Color::Yellow);
			buttons[2].setScale(1.25, 1.25);
			m_buttonThreeText.setScale(1.25, 1.25);

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				std::cout << "Choose stuff pressed" << std::endl;
			}

		}
		else if (t_mousePos.y > 680 && t_mousePos.y < 730)
		{
			buttons[3].setFillColor(sf::Color::Yellow);
			buttons[3].setScale(1.25, 1.25);
			m_buttonFourText.setScale(1.25, 1.25);

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				std::cout << "End Game pressed" << std::endl;
			}

		}
		else
		{
			for (int i = 0; i < MAX_BUTTONS; i++)
			{
				buttons[i].setFillColor(sf::Color::Red);
				buttons[i].setScale(1, 1);
				m_buttonOneText.setScale(1, 1);
				m_buttonTwoText.setScale(1, 1);
				m_buttonThreeText.setScale(1, 1);
				m_buttonFourText.setScale(1, 1);

			}
		}
	}
	else
	{
		for (int i = 0; i < MAX_BUTTONS; i++)
		{
			buttons[i].setFillColor(sf::Color::Red);
			buttons[i].setScale(1, 1);
			m_buttonOneText.setScale(1, 1);
			m_buttonTwoText.setScale(1, 1);
			m_buttonThreeText.setScale(1, 1);
			m_buttonFourText.setScale(1, 1);
		}
	}


}

