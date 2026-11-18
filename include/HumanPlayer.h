#pragma once
#include "Player.h"

class HumanPlayer : public Player {
public:
    explicit HumanPlayer(std::string name) : Player(std::move(name)) {}
    Move chooseMove() override;
    std::string type() const override { return "Человек"; }
};