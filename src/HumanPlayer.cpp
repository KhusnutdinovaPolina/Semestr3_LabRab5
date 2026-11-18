#include "../include/HumanPlayer.h"
#include <iostream>
#include <limits>

Move HumanPlayer::chooseMove() {
    std::cout << "\nХод игрока [" << name_ << "]\n";
    std::cout << "  0 - Камень\n  1 - Бумага\n  2 - Ножницы\n"
                 "  3 - Ящерица\n  4 - Спок\n";
    int choice = -1;
    while (true) {
        std::cout << "Ваш выбор: ";
        if (std::cin >> choice && choice >= 0 && choice <= 4) break;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Неверный ввод, попробуйте снова.\n";
    }
    return Move::fromIndex(choice);
}