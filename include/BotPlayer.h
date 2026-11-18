#pragma once
#include "Player.h"
#include <random>

class BotPlayer : public Player {
public:
    explicit BotPlayer(std::string name, unsigned seed = std::random_device{}());
    Move chooseMove() override;
    std::string type() const override { return "Бот (random)"; }
protected:
    std::mt19937 rng_;
};