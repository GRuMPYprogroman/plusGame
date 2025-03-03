#include "museum.h"
	

Museum::Museum()
{
		try {
			showPlayerAchievments();
		}
		catch (std::runtime_error& er) {
			std::cout << "������ �������: " << er.what() << std::endl;
		}
}

void Museum::showPlayerAchievments()
{
		std::ifstream in("playerAchievments.txt");

		if (!in) {
			throw std::runtime_error("���� ������ �������!");
		}

		str line;

		while (std::getline(in, line)) {
			std::stringstream ss(line);
			str achievment;

			ss >> achievment;
			foundLoot.push_back(achievment);
		}

		if (foundLoot.size() == 9) {
			std::cout << "�� ����� ��� ���������(9) - �� ����� ��������!\n\n";
		}
		else if (foundLoot.size() == 0) {
			std::cout << "������ �� ��� ������ �� ����� - ����� ������������ �� ��������!\n\n";
		}
		else {
			std::cout << "��������� ���������: \n";

			for (auto achiev : foundLoot) {
				std::cout << achiev << "\n";
			}
		}

		in.close();
}