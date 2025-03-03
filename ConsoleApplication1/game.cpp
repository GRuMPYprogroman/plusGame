#include "game.h"

using str = std::string;

void Game::start() {
		auto player = std::make_unique<Player>(10, 50);

		loadSave(player.get());

		auto base = std::make_unique<Base>(player.get());
}

void Game::loadSave(Player* player) {
		std::ifstream in("playerSettings.txt");

		if (!in.is_open()) {
			std::cout << "Сохранение повреждены! Загрузка параматеров по умолчанию.\n";
			return;
		}

		str line;

		std::getline(in, line);

		std::stringstream ss(line);
		int money, food;

		ss >> money >> food;

		player->setMoney(money);
		player->setFood(food);

		while (std::getline(in, line)) {
			std::stringstream ss(line);
			str item;
			int amount;

			ss >> item >> amount;
			player->getEquipment()[item] = amount;
		}

		in.close();
}

void Game::autoSave(Player* player) {
		std::ofstream out("playerSettings.txt", std::ios::trunc);

		if (!out) {
			throw std::runtime_error("Файл нельзя открыть!");
		}

		out << player->getMoney() << " " << player->getFood() << "\n";

		for (const auto& item : player->getEquipment())
		{
			out << item.first << " " << item.second << "\n";
		}

		out.close();

}

void Game::newGame() {
		auto player = std::make_unique<Player>(10, 50);

		std::ofstream out1("playerSettings.txt", std::ios::trunc);
		std::ofstream out2("playerAchievments.txt", std::ios::trunc);

		out1.close();
		out2.close();

		autoSave(player.get());

		auto base = std::make_unique<Base>(player.get());
}

void Game::gameOver() {
		std::cout << "Ваши деньги закончились - никто не хочет финансировать ваши экспедиции!\n\n";

		std::ofstream out1("playerSettings.txt", std::ios::trunc);
		std::ofstream out2("playerAchievments.txt", std::ios::trunc);

		out1.close();
		out2.close();
}