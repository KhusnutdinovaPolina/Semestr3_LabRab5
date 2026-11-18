#pragma once
#include <string>

namespace ConsoleUI {
    void printHeader();
    void printRules();
    void pressEnterToContinue();
    int  askInt(const std::string& prompt, int lo, int hi); //ввод целого числа в диапазоне
}