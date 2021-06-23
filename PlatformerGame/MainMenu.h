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

	void mouseCollision(sf::Vector2i t_mousePos, GameState& t_gameState);

	void loadAssets();

private:

	static const int MAX_BUTTONS = 4;
	sf::RectangleShape buttons[MAX_BUTTONS];

	//int menuState = 1;
	// 1: intitial showing the whole menu
	// 2: Start game button 1
	// 3: instructions button 2
	// 4:
	// 5: exit game

	sf::Vector2i mousePos;


	
	sf::Font m_font;
	sf::Text m_buttonOneText;
	sf::Text m_buttonTwoText;
	sf::Text m_buttonThreeText;
	sf::Text m_buttonFourText;


};

