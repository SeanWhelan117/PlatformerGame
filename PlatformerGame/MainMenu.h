#pragma once
#include <iostream>
#include <SFML\Graphics.hpp>
#include "GameState.h"


class MainMenu
{
public:
	MainMenu(); // constructor function

	void update(double dt, GameState& t_gameState);
	void render(sf::RenderWindow& t_window);

	void mouseCollision(sf::Vector2i t_mousePos, GameState& t_gameState); //checks the mouse location.
	//if mouse is hovering over a button it shows it
	//if left click is pressed the button is acted out

	void loadAssets();

private:

	static const int MAX_BUTTONS = 4;
	sf::RectangleShape buttons[MAX_BUTTONS]; // buttons array for menu buttons

	sf::Vector2i mousePos; // mouses current position


	
	sf::Font m_font; // arial.ttf font

	//text for each button stating what they are

	sf::Text m_buttonOneText;
	sf::Text m_buttonTwoText;
	sf::Text m_buttonThreeText;
	sf::Text m_buttonFourText;


};

