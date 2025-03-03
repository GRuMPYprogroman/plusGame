#pragma once
#include <iostream>
#include "player.h"
#include "base.h"   
#include <sstream>
#include <memory>
#include <string>
#include <fstream>


class Game {
public:
	static void start();
	static void loadSave(Player* player);
	static void autoSave(Player* player);
	static void newGame();
	static void gameOver();
};