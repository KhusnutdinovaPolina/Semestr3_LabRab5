#pragma once
#include "Player.h"
#include <memory>
#include <vector>

class Game {
public:
    explicit Game(std::vector<std::unique_ptr<Player>> players);
    void playTournament(int maxRounds = 100);

    const std::vector<std::unique_ptr<Player>>& players() const {
        return players_;
    }

private:
    std::vector<std::unique_ptr<Player>> players_;
    int roundCounter_ = 0;

    // Внутренний метод для проведения раунда только среди активных
    std::vector<int> playRoundForActive(const std::vector<size_t>& activeIndices);
    void announceScores() const;
};