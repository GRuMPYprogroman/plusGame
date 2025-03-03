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
		std::cout << "Выберите желаемое действие:" << "\n";
		std::cout << "1) Зайти в магазин." << "\n" << "2) Зайти в музей." << "\n" << "3) Отправиться на раскопки.\n" << "4) Сохранить игру и выйти.\n\n";
		int input;

		if (!(std::cin >> input)) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Неверный ввод! Введите число от 1 до 5.\n";
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
				std::cout << "Выберите локацию для раскопок:\n";
				std::cout << "1) Царство Посейдона (-10 шекелей, -1 еда)\n2) Преисподняя (-25 шекелей, -2 еды)\n3) Луна (-50 шекелей, -3 еды)\n";
				int loc;
				std::cin >> loc;
				switch (loc) {
				case 1:
					if (ExcavationUnderWater::checkPlayer<ExcavationUnderWater>(player)) {
						ExcavationUnderWater exc(player);
					}
					else {
						std::cout << "Недостаточно денег или еды!\n";
					}
					break;
				case 2:
					if (ExcavationVulkano::checkPlayer<ExcavationVulkano>(player)) {
						ExcavationVulkano exc(player);
					}
					else {
						std::cout << "Недостаточно денег или еды!\n";
					}
					break;
				case 3:
					if (ExcavationMoon::checkPlayer<ExcavationMoon>(player)) {
						ExcavationMoon exc(player);
					}
					else {
						std::cout << "Недостаточно денег или еды!\n";
					}
					break;
				default:
					std::cout << "Неверный ввод! Введите число от 1 до 3.\n";
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