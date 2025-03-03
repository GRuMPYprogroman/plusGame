#include "base.h"

Base::Base(Player* player):player(player) {
		while (true) {
			if (isNullBalance(player)) {
				Game::gameOver();
				break;
			}
			if (!awaitResponse())
				break;
	}
}

bool Base::isNullBalance(Player* player)
{
	return player->getMoney() == 0;
}

bool Base::awaitResponse() {
		std::cout << "�������� �������� ��������:" << "\n";
		std::cout << "1) ����� � �������." << "\n" << "2) ����� � �����." << "\n" << "3) ����������� �� ��������.\n" << "4) ��������� ���� � �����.\n\n";
		int input;

		if (!(std::cin >> input)) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "�������� ����! ������� ����� �� 1 �� 5.\n";
			return true;
		}

		switch (input)
		{
		case 1:
		{
			auto shop = std::make_unique<Shop>(player);
			Game::autoSave(player);
			return true;
		}
		case 2:
		{
			auto museum = std::make_unique<Museum>();
			Game::autoSave(player);
			return true;
		}
		case 3:
		{
			{
				std::cout << "�������� ������� ��� ��������:\n";
				std::cout << "1) ������� ��������� (-10 �������, -1 ���)\n2) ����������� (-25 �������, -2 ���)\n3) ���� (-50 �������, -3 ���)\n";
				int loc;
				std::cin >> loc;
				switch (loc) {
				case 1:
					if (ExcavationUnderWater::checkPlayer<ExcavationUnderWater>(player)) {
						ExcavationUnderWater exc(player);
					}
					else {
						std::cout << "������������ ����� ��� ���!\n";
					}
					break;
				case 2:
					if (ExcavationVulkano::checkPlayer<ExcavationVulkano>(player)) {
						ExcavationVulkano exc(player);
					}
					else {
						std::cout << "������������ ����� ��� ���!\n";
					}
					break;
				case 3:
					if (ExcavationMoon::checkPlayer<ExcavationMoon>(player)) {
						ExcavationMoon exc(player);
					}
					else {
						std::cout << "������������ ����� ��� ���!\n";
					}
					break;
				default:
					std::cout << "�������� ����! ������� ����� �� 1 �� 3.\n";
					return true;
				}
				Game::autoSave(player);
				return true;
			}
		}
		case 4:
		{
			Game::autoSave(player);
			return false;
		}
		}
}