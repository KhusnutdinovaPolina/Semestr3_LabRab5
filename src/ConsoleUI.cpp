#include "../include/ConsoleUI.h"
#include <iostream>
#include <limits>

namespace ConsoleUI {
    void printHeader() {
        std::cout <<
                     "   Камень — Ножницы — Бумага — Ящерица — Спок\n"
                     "         (Rock-Paper-Scissors-Lizard-Spock)\n"
                     ;
    }

    void printRules() {
        std::cout << "\nПравила:\n"
                     "  Ножницы режут Бумагу; Бумага покрывает Камень;\n"
                     "  Камень давит Ящерицу; Ящерица отравляет Спока;\n"
                     "  Спок ломает Ножницы; Ножницы отрезают голову Ящерице;\n"
                     "  Ящерица съедает Бумагу; Бумага опровергает Спока;\n"
                     "  Спок испаряет Камень; Камень разбивает Ножницы.\n";
    }

    void pressEnterToContinue() {
        std::cout << "\nНажмите Enter...";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin.get();
    }

    int askInt(const std::string& prompt, int lo, int hi) {
        int x;
        while (true) {
            std::cout << prompt;
            if (std::cin >> x && x >= lo && x <= hi) return x;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Неверный ввод. Ожидается число от " << lo << " до " << hi << ".\n";
        }
    }
} // namespace