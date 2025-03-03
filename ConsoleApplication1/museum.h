#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include <fstream>
#include <sstream>

using str = std::string;

class Museum {
private:
	std::vector<str> foundLoot;
public:
	Museum();

	void showPlayerAchievments();

};