#pragma once
#include <map>
#include <string>
#include <vector>
#include "player.h"
#include <random>
#include <iostream>
#include <thread>
#include <chrono>
#include <fstream>

using str = std::string;

class Excavation {
private:
	std::map<str, int> Loot;
	str name;
public:
	Player* const player;
	std::vector<bool> achievemnts = { false,false,false };

	Excavation(Player* p);
	virtual ~Excavation() = default;

	template<typename T>
	static bool checkPlayer(Player* player);

	virtual void excavate() = 0;
	virtual void effect() = 0;
	virtual void printText() = 0;

	void setName(str name);

	void setLoot(std::map<str, int> loot);

	str getName() const;

	const std::map<str, int>& getLoot() const;

	const bool randomItem();

};

class ExcavationUnderWater : public Excavation {
public:
	static const int cost = 10;
	static const int cost_food = 1;

	ExcavationUnderWater(Player* p);

	void excavate() override;

	void effect() override;

	void printText() override;
};

class ExcavationVulkano : public Excavation {
public:
	static const int cost = 25;
	static const int cost_food = 2;

	ExcavationVulkano(Player* p);

	void excavate() override;

	void effect() override;

	void printText() override;
};

class ExcavationMoon : public Excavation {
public:
	const static int cost = 50;
	const static int cost_food = 3;

	ExcavationMoon(Player* p);

	void excavate() override;

	void effect() override;

	void printText() override;
};