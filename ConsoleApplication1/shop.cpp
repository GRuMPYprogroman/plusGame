#include "shop.h"

extern std::mt19937 gen;
extern std::uniform_int_distribution<> distribPrice;
extern std::uniform_int_distribution<> distribItems;


Shop::Shop(Player* player) : player(player)
	{
		catalog.emplace("pick", std::make_tuple(distribPrice(gen), distribItems(gen)));
		catalog.emplace("brush", std::make_tuple(distribPrice(gen), distribItems(gen)));
		catalog.emplace("shovel", std::make_tuple(distribPrice(gen), distribItems(gen)));
		printInfo();
		while (true) {
			int input;
			std::cin >> input;
			switch (input) {
			case 1:
				buy();
				break;
			case 2:
				sell();
				break;
			case 3:
				return;
			}
			printInfo();
		}
	}

void Shop::printInfo() const {
		std::cout << "� �������� �������:\n\n";
		std::cout << "1) �����: " << std::get<1>(catalog.at("pick")) << " �� ����: " << std::get<0>(catalog.at("pick")) << "\n";
		std::cout << "2) ��������: " << std::get<1>(catalog.at("brush")) << " �� ����: " << std::get<0>(catalog.at("brush")) << "\n";
		std::cout << "3) ������: " << std::get<1>(catalog.at("shovel")) << " �� ����: " << std::get<0>(catalog.at("shovel")) << "\n\n";
		std::cout << "��� ������ �����?(���� �����/������� ���������)." << "\n";
		std::cout << "�������:\n1)������\n2)�������\n3)����� �� ��������\n\n";
		player->printInfo();
}

bool Shop::checkBuyer(str item, int amount) {
		if (player->getMoney() >= std::get<0>(catalog[item]) * amount && amount << std::get<1>(catalog[item])) {
			return true;
		}
		return false;
	}

void Shop::buy() {
		std::cout << "������� ����� ������ � ���������� ���������� ������.\n";
		int number, amount;
		std::cin >> number >> amount;
		switch (number)
		{
		case 1:
		{
			if (checkBuyer("pick", amount)) {
				player->setEquipment("pick", player->getEquipment().at("pick") + amount);
				player->setMoney(player->getMoney() - amount * std::get<0>(catalog["pick"]));
				catalog["pick"] = std::make_tuple(std::get<0>(catalog.at("pick")), std::get<1>(catalog.at("pick")) - amount);
			}
			else {
				std::cout << "� �������� ������������ �������, ���� � ��� ������������ �����!\n";
			}
		}
		case 2:
		{
			if (checkBuyer("brush", amount)) {
				player->setEquipment("brush", player->getEquipment().at("brush") + amount);
				player->setMoney(player->getMoney() - amount * std::get<0>(catalog["brush"]));
				catalog["brush"] = std::make_tuple(std::get<0>(catalog.at("brush")), std::get<1>(catalog.at("brush")) - amount);
			}
			else {
				std::cout << "� �������� ������������ �������, ���� � ��� ������������ �����!\n";
			}
		}

		case 3:
		{
			if (checkBuyer("shovel", amount)) {
				player->setEquipment("shovel", player->getEquipment().at("shovel") + amount);
				player->setMoney(player->getMoney() - amount * std::get<0>(catalog["shovel"]));
				catalog["shovel"] = std::make_tuple(std::get<0>(catalog.at("shovel")), std::get<1>(catalog.at("shovel")) - amount);
			}
			else {
				std::cout << "� �������� ������������ �������, ���� � ��� ������������ �����!\n";
			}
		}
		}
}

void Shop::sell() {
		std::cout << "������� ����� ������ � ���������� ����������� ������(������� 4 - ��� ������� ��������� ����������).\n";
		int number, amount;
		std::cin >> number >> amount;
		switch (number)
		{
		case 1:
		{
			if (checkBuyer("pick", amount)) {
				player->setEquipment("pick", player->getEquipment().at("pick") - amount);
				player->setMoney(player->getMoney() - amount * std::get<0>(catalog["pick"]));
				catalog["pick"] = std::make_tuple(std::get<0>(catalog.at("pick")), std::get<1>(catalog.at("pick")) + amount);
			}
			else {
				std::cout << "� ��� ��� ������� ���������!\n";
			}
		}
		case 2:
		{
			if (checkBuyer("brush", amount)) {
				player->setEquipment("brush", player->getEquipment().at("brush") - amount);
				player->setMoney(player->getMoney() - amount * std::get<0>(catalog["brush"]));
				catalog["brush"] = std::make_tuple(std::get<0>(catalog.at("brush")), std::get<1>(catalog.at("brush")) + amount);
			}
			else {
				std::cout << "� ��� ��� ������� ���������!\n";
			}
		}

		case 3:
		{
			if (checkBuyer("shovel", amount)) {
				player->setEquipment("shovel", player->getEquipment().at("shovel") - amount);
				player->setMoney(player->getMoney() - amount * std::get<0>(catalog["shovel"]));
				catalog["shovel"] = std::make_tuple(std::get<0>(catalog.at("shovel")), std::get<1>(catalog.at("shovel")) + amount);
			}
			else {
				std::cout << "� ��� ��� ������� ���������!\n";
			}
		}
		case 4:
			player->setMoney(player->getMoney() + player->getArtifacts());
			player->setArtifacts(0);
		}
	}