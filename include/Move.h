#pragma once
#include <string>

// Класс-перечисление ходов
class Move {
public:
    enum Value { ROCK, PAPER, SCISSORS, LIZARD, SPOCK };

    Move() : v_(ROCK) {}
    Move(Value v) : v_(v) {}
    explicit Move(const std::string& name);

    Value value() const { return v_; } //возвращаем текущее значение хода
    std::string toString() const; //возвращаем читаемое имя хода (rock -> камень)
    static int totalMoves() { return 5; }
    static Move fromIndex(int i); //принимаем число от 0 до 4 и возвращаем соответствующий move
//перегрузка оператора для сравнения значений
    bool operator==(const Move& o) const { return v_ == o.v_; }

private:
    Value v_;
};