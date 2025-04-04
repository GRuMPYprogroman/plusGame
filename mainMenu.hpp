#pragma once
#include <vector>
#include "../sweatyArc/button.hpp"
#include "../sweatyArc/game.h"

class Button;


class mainMenu {
private:
	std::vector<Button*> buttons;
	int selectedButton = -1;
public:
	bool deleteFlag = false;

	mainMenu(sf::VideoMode& mode, sf::RenderWindow* window);

	~mainMenu();

	void render(sf::RenderWindow* window);

	void handleEvent(sf::Event& event, sf::RenderWindow* window);
};