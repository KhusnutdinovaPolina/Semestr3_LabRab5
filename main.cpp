#include "include/ConsoleUI.h"
#include "include/Game.h"
#include "include/PlayerFactory.h"
#include <iostream>
#include <vector>

int main() {
    ConsoleUI::printHeader();
    ConsoleUI::printRules();

    const int N = ConsoleUI::askInt("\nСколько игроков всего ? ", 3, 10);

    std::vector<std::unique_ptr<Player>> players;
    for (int i = 0; i < N; ++i) {
        std::cout << "\n Настройка игрока #" << (i + 1) << " \n"
                  << "  1) Человек\n  2) Случайный бот\n  3) Умный бот\n";
        int k = ConsoleUI::askInt("Тип: ", 1, 3);

        std::string name;
        std::cout << "Имя: ";
        std::cin >> name;

        PlayerFactory::Kind kind = PlayerFactory::HUMAN;
        if (k == 2) kind = PlayerFactory::RANDOM_BOT;
        if (k == 3) kind = PlayerFactory::SMART_BOT;

        players.push_back(PlayerFactory::create(kind, name));
    }

    std::cout << "\nНачинаем игру на выбывание: \n";

    Game game(std::move(players));
    game.playTournament();   // maxRounds = 100 по умолчанию

    return 0;

}
