#include "mainMenu.hpp"

mainMenu::mainMenu(sf::VideoMode& mode,sf::RenderWindow* window)
{
	buttons.reserve(4);
	Button* contGame = new Button("Continue", [window, this, &mode]()
		{
			window->clear();
			Game::currentState = Game::state::game_play;
			Game::gameplay = new Gameplay(mode, window);
			Game::loadSave(Game::gameplay->getPlayer());

			this->deleteFlag = true;
		});
	Button* newGame = new Button("New Game",[window,this,&mode]()
	{
			window->clear();
			Game::currentState = Game::state::game_play;
			Game::gameplay = new Gameplay(mode, window);
			Game::clearAchievments();

			this->deleteFlag = true;
	});
	Button* option = new Button("Options", [window,this,&mode]()
		{
			window->clear();
			Game::currentState = Game::state::options;
			Game::options = new Options(mode,window);
			this->deleteFlag = true;
		});
	Button* exit_game = new Button("Exit", [window]()
	{
		window->clear();
		window->close();
	});

	contGame->placeCenter(mode);
	newGame->placeCenter(mode);
	option->placeCenter(mode);
	exit_game->placeCenter(mode);

	buttons.push_back(contGame);
	buttons.push_back(newGame);
	buttons.push_back(option);
	buttons.push_back(exit_game);

}

mainMenu::~mainMenu()
{
	for (auto& button : buttons)
	{
		delete button;
	}
}

void mainMenu::render(sf::RenderWindow* window)
{
		for (auto& button : buttons)
		{
			button->render(window);
		}

}

void mainMenu::handleEvent(sf::Event& event, sf::RenderWindow* window)
{
	if (const auto* keyboardButtonPressed = event.getIf<sf::Event::KeyPressed>())
	{
		if (keyboardButtonPressed->scancode == sf::Keyboard::Scancode::Down)
		{
			selectedButton = (selectedButton + 1) % buttons.size();
			buttons[selectedButton]->isSelected = true;
			if (selectedButton == 0)
			{
				buttons[buttons.size()-1]->isSelected = false;
			}
			else
			{
				buttons[selectedButton - 1]->isSelected = false;
			}
		}
		if (keyboardButtonPressed->scancode == sf::Keyboard::Scancode::Up)
		{
			selectedButton -= 1;

			if (selectedButton < 0)
			{
				selectedButton = buttons.size()-1;
			}

			buttons[selectedButton]->isSelected = true;

			if (selectedButton == buttons.size()-1)
			{
				buttons[0]->isSelected = false;
			}
			else
			{
				buttons[selectedButton + 1]->isSelected = false;
			}
		}
	}
	for (auto& button : buttons)
	{
		button->handleEvent(event, window);
	}
}