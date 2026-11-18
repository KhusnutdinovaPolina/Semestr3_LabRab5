#pragma once
#include "Move.h"

class Rules {
public:
    //функция для доступа к правилам
    static const Rules& instance();

    // Кто победил - Возвращает 1 если a бьёт b, -1 если b бьёт a, 0 — ничья
    int compare(const Move& a, const Move& b) const;

    // Что происходит - Текстовая подсказка «X бьёт Y»
    std::string describeBeat(const Move& a, const Move& b) const;

private:
    Rules();
    // таблица из T/F, хранит правила
    bool beats_[5][5];
};


//b=         ROCK   PAPER  SCISSORS  LIZARD   SPOCK
//a=ROCK        F      F       T       T       F
//a=PAPER       T      F       F       F       T
//a=SCISSORS    F      T       F       T       F
//a=LIZARD      F      T       F       F       T
//a=SPOCK       T      F       T       F       F