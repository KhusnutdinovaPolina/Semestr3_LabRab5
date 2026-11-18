#include "../include/Rules.h"
#include <map>
#include <utility>

Rules::Rules() {
    // заполняем всю таблицу в false
    for (int i = 0; i < 5; ++i)
        for (int j = 0; j < 5; ++j) beats_[i][j] = false;

    // Камень бьёт: Ножницы, Ящерица
    beats_[Move::ROCK][Move::SCISSORS] = true;
    beats_[Move::ROCK][Move::LIZARD]   = true;
    // Бумага бьёт: Камень, Спок
    beats_[Move::PAPER][Move::ROCK]    = true;
    beats_[Move::PAPER][Move::SPOCK]   = true;
    // Ножницы бьют: Бумага, Ящерица
    beats_[Move::SCISSORS][Move::PAPER] = true;
    beats_[Move::SCISSORS][Move::LIZARD] = true;
    // Ящерица бьёт: Бумага, Спок
    beats_[Move::LIZARD][Move::PAPER]  = true;
    beats_[Move::LIZARD][Move::SPOCK]  = true;
    // Спок бьёт: Камень, Ножницы
    beats_[Move::SPOCK][Move::ROCK]    = true;
    beats_[Move::SPOCK][Move::SCISSORS]= true;
}

const Rules& Rules::instance() {
    static Rules r;
    return r;
}
//сравнение ходов
int Rules::compare(const Move& a, const Move& b) const {
    if (a == b) return 0;
    return beats_[a.value()][b.value()] ? 1 : -1;
}

std::string Rules::describeBeat(const Move& a, const Move& b) const {
    static const std::map<std::pair<Move::Value, Move::Value>, std::string> verbs = {
        {{Move::ROCK, Move::SCISSORS},     "разбивает"},
        {{Move::ROCK, Move::LIZARD},       "давит"},
        {{Move::PAPER, Move::ROCK},        "покрывает"},
        {{Move::PAPER, Move::SPOCK},       "опровергает"},
        {{Move::SCISSORS, Move::PAPER},    "режут"},
        {{Move::SCISSORS, Move::LIZARD},   "отрезают голову"},
        {{Move::LIZARD, Move::PAPER},      "съедает"},
        {{Move::LIZARD, Move::SPOCK},      "отравляет"},
        {{Move::SPOCK, Move::ROCK},        "испаряет"},
        {{Move::SPOCK, Move::SCISSORS},    "ломает"}
    };
    auto it = verbs.find({a.value(), b.value()});
    return it == verbs.end() ? "" : it->second;
}