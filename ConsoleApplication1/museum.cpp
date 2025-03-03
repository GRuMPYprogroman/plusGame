#include "museum.h"
	

Museum::Museum()
{
		try {
			showPlayerAchievments();
		}
		catch (std::runtime_error& er) {
			std::cout << "Ошибка доступа: " << er.what() << std::endl;
		}
}

void Museum::showPlayerAchievments()
{
		std::ifstream in("playerAchievments.txt");

		if (!in) {
			throw std::runtime_error("Файл нельзя открыть!");
		}

		str line;

		while (std::getline(in, line)) {
			std::stringstream ss(line);
			str achievment;

			ss >> achievment;
			foundLoot.push_back(achievment);
		}

		if (foundLoot.size() == 9) {
			std::cout << "Вы нашли все артефакты(9) - вы истый археолог!\n\n";
		}
		else if (foundLoot.size() == 0) {
			std::cout << "Похоже вы ещё ничего не нашли - время отправляться на раскопки!\n\n";
		}
		else {
			std::cout << "Найденные артефакты: \n";

			for (auto achiev : foundLoot) {
				std::cout << achiev << "\n";
			}
		}

		in.close();
}