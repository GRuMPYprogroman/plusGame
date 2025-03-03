#pragma once
#include <map>
#include <string>
#include <random>
#include <iostream>
#include "player.h"
#include <tuple>

using str = std::string;

class Shop {
private:
	std::map<std::string, std::tuple<int, int>> catalog;
public:
	Player* const player;

	Shop(Player* player);

	void printInfo() const;

	bool checkBuyer(str item, int amount);

	void buy();

	void sell();
};