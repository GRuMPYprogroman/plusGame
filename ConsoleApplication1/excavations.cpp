#include "excavations.h"

extern std::mt19937 gen;
extern std::uniform_int_distribution<> distribLoot;
extern std::uniform_int_distribution<> distribEffect;
extern std::uniform_int_distribution<> distirEquip;

Excavation::Excavation(Player* p) : player(p) {}

const bool Excavation::randomItem() {
	int rand = distirEquip(gen);
	std::cout << "����� ����������� ����� ������������?:\n1)�����\n2)��������\n3)������\n\n";

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
		setLoot(std::map<std::string, int>{{"������������� �����", 10}, { "���������� ������", 25 }, { "��������� ������", 50 }});
		setName("���������� � ������� ���������.");
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
			std::cout << "�� ������ �� �����!\n";
			player->setFood(player->getFood() - cost_food);
		}
		else if (loot_chance < 70) {
			if (randomItem()) 
			{
				std::cout << "������ ������� ���: " << (*it).first << " ����������: " << (*it).second << "\n";

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
				std::cout << "����������� ���������� �������� ����������!\n";
			}
		}
		else if (loot_chance < 90) {
			if (randomItem())
			{
				++it;
				std::cout << "������ ������ ���: " << (*it).first << " ����������: " << (*it).second;

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
				std::cout << "����������� ���������� �������� ����������!\n";
			}
		}
		else 
		{
			if (randomItem()) 
			{
				std::advance(it, 2);
				std::cout << "������ ��������� ���: " << (*it).first << " ����������: " << (*it).second;

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
				std::cout << "����������� ���������� �������� ����������!\n";
			}
		}

}

void ExcavationUnderWater::effect(){
		int event = distribEffect(gen);
		if (event) {
			std::cout << "� ���! ������� ������ ���� �������!\n\n ��� ����������� �� ��������.\n\n";
			player->setFood(player->getFood() - 1);
		}
}

void ExcavationUnderWater::printText(){
		std::cout << "����-���� �������... ������� ���-���... ������� ����� ����������...(�������� ���)\n\n";
		std::this_thread::sleep_for(std::chrono::seconds(4));
}

ExcavationVulkano::ExcavationVulkano(Player* p) :Excavation(p) {
		setLoot(std::map<std::string, int>{{"������ ������ ����", 20}, { "��������� ��������", 35 }, { "������� ���", 50 }});
		setName("�����������.");
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
			std::cout << "�� ������ �� �����!\n";
			player->setFood(player->getFood() - cost_food);
		}
		else if (loot_chance < 70) {
			if (randomItem())
			{
				std::cout << "������ ������� ���: " << (*it).first << " ����������: " << (*it).second << "\n";

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
				std::cout << "����������� ���������� �������� ����������!\n";
			}
		}
		else if (loot_chance < 90) {
			if (randomItem())
			{
				++it;
				std::cout << "������ ������ ���: " << (*it).first << " ����������: " << (*it).second;

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
				std::cout << "����������� ���������� �������� ����������!\n";
			}
		}
		else
		{
			if (randomItem())
			{
				std::advance(it, 2);
				std::cout << "������ ��������� ���: " << (*it).first << " ����������: " << (*it).second;

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
				std::cout << "����������� ���������� �������� ����������!\n";
			}
		}

	}

void ExcavationVulkano::effect(){
		int event = distribEffect(gen);
		if (event) {
			std::cout << "� ���! ����� ������ ���� ����������!\n\n\n\n";
			std::uniform_int_distribution<> distribEquipment(0, player->getEquipment().size() - 1);

			int distrib = distribEquipment(gen);

			auto it = (player->getEquipment()).begin();
			std::advance(it, distrib);

			std::cout << "1 " << (*it).first << "��� ��������� ����.\n";
			(*it).second = (*it).second - 1;
		}
	}

void ExcavationVulkano::printText(){
		std::cout << "����, ����-�. ������� ������ ������� �������!...(�������� ���)\n\n";
		std::this_thread::sleep_for(std::chrono::seconds(4));
	}

ExcavationMoon::ExcavationMoon(Player* p) :Excavation(p) {
		setLoot(std::map<std::string, int>{{"������ �������� ��������", 40}, { "������ ������� ����", 70 }, { "������� ������� ����", 100 }});
		effect();
		setName("������ �� ����.");
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
			std::cout << "�� ������ �� �����!\n";
			player->setFood(player->getFood() - cost_food);
		}
		else if (loot_chance < 70) {
			if (randomItem())
			{
				std::cout << "������ ������� ���: " << (*it).first << " ����������: " << (*it).second << "\n";

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
				std::cout << "����������� ���������� �������� ����������!\n";
			}
		}
		else if (loot_chance < 90) {
			if (randomItem())
			{
				++it;
				std::cout << "������ ������ ���: " << (*it).first << " ����������: " << (*it).second;

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
				std::cout << "����������� ���������� �������� ����������!\n";
			}
		}
		else
		{
			if (randomItem())
			{
				std::advance(it, 2);
				std::cout << "������ ��������� ���: " << (*it).first << " ����������: " << (*it).second;

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
				std::cout << "����������� ���������� �������� ����������!\n";
			}
		}
	}

void ExcavationMoon::effect(){
		int event = distribEffect(gen);
		if (event) {
			std::cout << "� ����� ������� �������������!\n\n\n\n";

			std::cout << "15 ������� �������� ��� ��������... (���� ��������� �������� �������� ������).\n\n ";
			player->setMoney(player->getMoney() - 15);
		}
	}

void ExcavationMoon::printText(){
		std::cout << "����� � ������������, ����� � ������������, ����� � ������������ �����...\n\n ";
		std::this_thread::sleep_for(std::chrono::seconds(4));
}