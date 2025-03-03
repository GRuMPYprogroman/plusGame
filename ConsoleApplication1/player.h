#pragma once
#include <map>
#include <string>
#include <iostream>

using str = std::string;

class Player {
private:
	int food;
	std::map<str, int> equipment;
	int money;
	int artifactsOnSell = 0;
public:
	Player(int sFood, int sMoney);

	void setMoney(int money);

	void setFood(int food);

	void setEquipment(const str& name, int amount);

	void setArtifacts(int toAdd);

	int getMoney() const;

	int getFood() const;

	std::map<str, int>& getEquipment();

	int getArtifacts() const;

	void printInfo();

};