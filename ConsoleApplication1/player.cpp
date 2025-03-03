#include "player.h"


Player::Player(int sFood, int sMoney) :food(sFood), money(sMoney) {
		equipment.emplace("pick", 1);
		equipment.emplace("shovel", 1);
		equipment.emplace("brush", 1);
}

void Player::setMoney(int money) {
		this->money = (money < 0) ? 0 : money;
}

void Player::setFood(int food) {
		this->food = (food < 0) ? 0 : food;
}

void Player::setEquipment(const str& name, int amount) {
		equipment[name] = (amount < 0) ? 0 : amount;
}

void Player::setArtifacts(int toAdd) {
		artifactsOnSell += toAdd;
}

int Player::getMoney() const {
		return this->money;
}

int Player::getFood() const {
		return this->food;
}

	std::map<str, int>& Player::getEquipment() {
		return this->equipment;
}

	int Player::getArtifacts() const {
		return artifactsOnSell;
}

void Player::printInfo() {
		std::cout << "У вас есть:\n";
		std::cout << "Еды: " << this->getFood() << "\n" << "Монет: " << this->getMoney() << "\n";
		for (const auto& i : equipment) {
			std::cout << i.first << ": " << i.second << " Шт." << "\n";
		}
}