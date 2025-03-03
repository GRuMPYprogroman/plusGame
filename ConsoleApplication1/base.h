#pragma once
#include "player.h"
#include "game.h"
#include <iostream>
#include <limits>
#include "shop.h"
#include "museum.h"
#include "excavations.h"

class Base {
private:
	Player* player;
public:
	Base(Player* player);
	
	bool isNullBalance(Player* player);

	bool awaitResponse();
};