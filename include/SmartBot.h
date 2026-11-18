#pragma once
#include "Player.h"
#include <random>
#include <array>

class SmartBot : public Player {
public:
    explicit SmartBot(std::string name, unsigned seed = std::random_device{}());
    Move chooseMove() override;
    std::string type() const override { return "Бот (умный)"; }
    void observe(const Move& m);   // запомни ход соперника (статистика)
    void onRoundResult(const Move& mine, const Move& other, int result) override;
private:
    std::mt19937 rng_;//генератор случайности, пока нет данных
    std::array<int, 5> freq_{}; // массив частот
    int observed_ = 0;//общее число наблюдений
};