#include "game.h"
#include "base.h"
#include "player.h"
#define NOMINMAX
#include <windows.h>


#define MIN_PRICE 10
#define MAX_PRICE 20
#define MIN_ITEMS 1
#define MAX_ITEMS 4
#define MIN_LOOT_CHANCE 0
#define MAX_LOOT_CHANCE 100
#define MIN_EFFECT_CHANCE 0
#define MAX_EFFECT_CHANCE 1
#define MIN_EQUIPMENT 1 
#define MAX_EQUIPMENT 3 

std::mt19937 gen(time(0));
std::uniform_int_distribution<> distribPrice(MIN_PRICE, MAX_PRICE);
std::uniform_int_distribution<> distribItems(MIN_ITEMS, MAX_ITEMS);
std::uniform_int_distribution<> distribLoot(MIN_LOOT_CHANCE, MAX_LOOT_CHANCE);
std::uniform_int_distribution<> distribEffect(MIN_EFFECT_CHANCE, MAX_EFFECT_CHANCE);
std::uniform_int_distribution<> distirEquip(MIN_EQUIPMENT, MAX_EQUIPMENT);

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	std::cout << "Добро пожаловать в 'Потных археологов 2!'\n\n";

	std::cout << "1) Продолжить игру\n2) Начать заново\n\n";
	
	int input;
	std::cin >> input;

	switch (input) {
	case 1:
		Game::start();
		break;
	case 2:
		Game::newGame();
		break;
	}

	std::cout << "Спасибо за игру!\n";

	return 1;
}