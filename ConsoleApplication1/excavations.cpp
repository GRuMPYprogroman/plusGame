#include "excavations.h"

extern std::mt19937 gen;
extern std::uniform_int_distribution<> distribLoot;
extern std::uniform_int_distribution<> distribEffect;
extern std::uniform_int_distribution<> distirEquip;

Excavation::Excavation(Player* p) : player(p) {}

const bool Excavation::randomItem() {
	int rand = distirEquip(gen);
	std::cout << "Каким снаряжением будем пользоваться?:\n1)Кирка\n2)Кисточка\n3)Лопата\n\n";

	int input;
	std::cin >> input;

	if (input == rand) {
		return true;
	}
	return false;
}

template<typename T>
static bool Excavation::checkPlayer(Player* player) {
		if (player->getMoney() >= T::cost && player->getFood() >= T::cost_food) {
			return true;
		}
		return false;
	}

template bool Excavation::checkPlayer<ExcavationUnderWater>(Player* player);
template bool Excavation::checkPlayer<ExcavationVulkano>(Player* player);
template bool Excavation::checkPlayer<ExcavationMoon>(Player* player);

void Excavation::setName(str name) {
		this->name = name;
}

void Excavation::setLoot(std::map<str, int> loot) {
		this->Loot = loot;
}

str Excavation::getName() const {
		return this->name;
}

const std::map<str, int>& Excavation::getLoot() const {
		return this->Loot;
}


ExcavationUnderWater::ExcavationUnderWater(Player* p) :Excavation(p) {
		setLoot(std::map<std::string, int>{{"Глубоководный Тотем", 10}, { "Коралловая Корона", 25 }, { "Жемчужина Глубин", 50 }});
		setName("Экспедиция в царство Посейдона.");
		effect();
		excavate();
}

void ExcavationUnderWater::excavate() {
		player->setMoney(player->getMoney() - cost);
		int loot_chance = distribLoot(gen);
		std::map<str, int> Loot = getLoot();
		auto it = Loot.begin();

		std::cout << getName() << "\n\n";

		printText();

		if (loot_chance < 40) {
			std::cout << "Вы ничего не нашли!\n";
			player->setFood(player->getFood() - cost_food);
		}
		else if (loot_chance < 70) {
			if (randomItem()) 
			{
				std::cout << "Найден обычный лут: " << (*it).first << " Стоимостью: " << (*it).second << "\n";

				player->setFood(player->getFood() - cost_food);
				player->setArtifacts(10);

				if (!achievemnts[0]) {
					std::ofstream out("playerAchievments.txt", std::ios::app);
					out << (*it).first << "\n";
					achievemnts[0] = true;
				}
			}
			else 
			{
				std::cout << "Применяемый инструмент оказался бесполезен!\n";
			}
		}
		else if (loot_chance < 90) {
			if (randomItem())
			{
				++it;
				std::cout << "Найден редкий лут: " << (*it).first << " Стоимостью: " << (*it).second;

				player->setFood(player->getFood() - cost_food);
				player->setArtifacts(25);

				if (!achievemnts[1]) {
					std::ofstream out("playerAchievments.txt", std::ios::app);
					out << (*it).first << "\n";
					achievemnts[1] = true;
				}
			}
			else
			{
				std::cout << "Применяемый инструмент оказался бесполезен!\n";
			}
		}
		else 
		{
			if (randomItem()) 
			{
				std::advance(it, 2);
				std::cout << "Найден эпический лут: " << (*it).first << " Стоимостью: " << (*it).second;

				player->setFood(player->getFood() - cost_food);
				player->setArtifacts(50);

				if (!achievemnts[2]) {
					std::ofstream out("playerAchievments.txt", std::ios::app);
					out << (*it).first << "\n";
					achievemnts[2] = true;
				}
			}
			else 
			{
				std::cout << "Применяемый инструмент оказался бесполезен!\n";
			}
		}

}

void ExcavationUnderWater::effect(){
		int event = distribEffect(gen);
		if (event) {
			std::cout << "О нет! ВОДИЧКА УНЕСЛА ВАШУ КУРОЧКУ!\n\n ЕДА УМЕНЬШИЛАСЬ НА ЕДИНИЧКУ.\n\n";
			player->setFood(player->getFood() - 1);
		}
}

void ExcavationUnderWater::printText(){
		std::cout << "Буль-буль карасик... водичка кап-кап... кажется дождь начинается...(добываем лут)\n\n";
		std::this_thread::sleep_for(std::chrono::seconds(4));
}

ExcavationVulkano::ExcavationVulkano(Player* p) :Excavation(p) {
		setLoot(std::map<std::string, int>{{"Камень Сердца Лавы", 20}, { "Пламенные Перчатки", 35 }, { "Лавовый Меч", 50 }});
		setName("Преисподняя.");
		effect();
		excavate();
	}

void ExcavationVulkano::excavate(){
		player->setMoney(player->getMoney() - cost);
		int loot_chance = distribLoot(gen);
		std::map<str, int> Loot = getLoot();
		auto it = Loot.begin();

		std::cout << getName() << "\n\n";

		printText();

		if (loot_chance < 40) {
			std::cout << "Вы ничего не нашли!\n";
			player->setFood(player->getFood() - cost_food);
		}
		else if (loot_chance < 70) {
			if (randomItem())
			{
				std::cout << "Найден обычный лут: " << (*it).first << " Стоимостью: " << (*it).second << "\n";

				player->setFood(player->getFood() - cost_food);
				player->setArtifacts(10);

				if (!achievemnts[0]) {
					std::ofstream out("playerAchievments.txt", std::ios::app);
					out << (*it).first << "\n";
					achievemnts[0] = true;
				}
			}
			else
			{
				std::cout << "Применяемый инструмент оказался бесполезен!\n";
			}
		}
		else if (loot_chance < 90) {
			if (randomItem())
			{
				++it;
				std::cout << "Найден редкий лут: " << (*it).first << " Стоимостью: " << (*it).second;

				player->setFood(player->getFood() - cost_food);
				player->setArtifacts(25);

				if (!achievemnts[1]) {
					std::ofstream out("playerAchievments.txt", std::ios::app);
					out << (*it).first << "\n";
					achievemnts[1] = true;
				}
			}
			else
			{
				std::cout << "Применяемый инструмент оказался бесполезен!\n";
			}
		}
		else
		{
			if (randomItem())
			{
				std::advance(it, 2);
				std::cout << "Найден эпический лут: " << (*it).first << " Стоимостью: " << (*it).second;

				player->setFood(player->getFood() - cost_food);
				player->setArtifacts(50);

				if (!achievemnts[2]) {
					std::ofstream out("playerAchievments.txt", std::ios::app);
					out << (*it).first << "\n";
					achievemnts[2] = true;
				}
			}
			else
			{
				std::cout << "Применяемый инструмент оказался бесполезен!\n";
			}
		}

	}

void ExcavationVulkano::effect(){
		int event = distribEffect(gen);
		if (event) {
			std::cout << "О нет! ОГОНЬ СПАЛИЛ ВАШЕ СНАРЯЖЕНИЕ!\n\n\n\n";
			std::uniform_int_distribution<> distribEquipment(0, player->getEquipment().size() - 1);

			int distrib = distribEquipment(gen);

			auto it = (player->getEquipment()).begin();
			std::advance(it, distrib);

			std::cout << "1 " << (*it).first << "был уничтожен огнём.\n";
			(*it).second = (*it).second - 1;
		}
	}

void ExcavationVulkano::printText(){
		std::cout << "Жара, жара-а. Жареное солнце больших городов!...(добываем лут)\n\n";
		std::this_thread::sleep_for(std::chrono::seconds(4));
	}

ExcavationMoon::ExcavationMoon(Player* p) :Excavation(p) {
		setLoot(std::map<std::string, int>{{"Лунный Кристалл Сущности", 40}, { "Лунный Осколок Силы", 70 }, { "Эликсир Звёздной Пыли", 100 }});
		effect();
		setName("Кратор на луне.");
		excavate();
	}

void ExcavationMoon::excavate(){
		player->setMoney(player->getMoney() - cost);
		int loot_chance = distribLoot(gen);
		std::map<str, int> Loot = getLoot();
		auto it = Loot.begin();

		std::cout << getName() << "\n\n";

		printText();

		if (loot_chance < 40) {
			std::cout << "Вы ничего не нашли!\n";
			player->setFood(player->getFood() - cost_food);
		}
		else if (loot_chance < 70) {
			if (randomItem())
			{
				std::cout << "Найден обычный лут: " << (*it).first << " Стоимостью: " << (*it).second << "\n";

				player->setFood(player->getFood() - cost_food);
				player->setArtifacts(10);

				if (!achievemnts[0]) {
					std::ofstream out("playerAchievments.txt", std::ios::app);
					out << (*it).first << "\n";
					achievemnts[0] = true;
				}
			}
			else
			{
				std::cout << "Применяемый инструмент оказался бесполезен!\n";
			}
		}
		else if (loot_chance < 90) {
			if (randomItem())
			{
				++it;
				std::cout << "Найден редкий лут: " << (*it).first << " Стоимостью: " << (*it).second;

				player->setFood(player->getFood() - cost_food);
				player->setArtifacts(25);

				if (!achievemnts[1]) {
					std::ofstream out("playerAchievments.txt", std::ios::app);
					out << (*it).first << "\n";
					achievemnts[1] = true;
				}
			}
			else
			{
				std::cout << "Применяемый инструмент оказался бесполезен!\n";
			}
		}
		else
		{
			if (randomItem())
			{
				std::advance(it, 2);
				std::cout << "Найден эпический лут: " << (*it).first << " Стоимостью: " << (*it).second;

				player->setFood(player->getFood() - cost_food);
				player->setArtifacts(50);

				if (!achievemnts[2]) {
					std::ofstream out("playerAchievments.txt", std::ios::app);
					out << (*it).first << "\n";
					achievemnts[2] = true;
				}
			}
			else
			{
				std::cout << "Применяемый инструмент оказался бесполезен!\n";
			}
		}
	}

void ExcavationMoon::effect(){
		int event = distribEffect(gen);
		if (event) {
			std::cout << "Я ЗАБЫЛ ЗАКРЫТЬ РЮКЗАЧООООООК!\n\n\n\n";

			std::cout << "15 шекелей покинули ваш бумажник... (ваша внутрення пейсатая личность бушует).\n\n ";
			player->setMoney(player->getMoney() - 15);
		}
	}

void ExcavationMoon::printText(){
		std::cout << "Земля в иллюминаторе, Земля в иллюминаторе, Земля в иллюминаторе видна...\n\n ";
		std::this_thread::sleep_for(std::chrono::seconds(4));
}