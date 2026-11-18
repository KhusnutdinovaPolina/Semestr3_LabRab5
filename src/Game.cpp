#include "Game.h"
#include "Rules.h"
#include <iostream>
#include <algorithm>

Game::Game(std::vector<std::unique_ptr<Player>> players)
    : players_(std::move(players)) {}

std::vector<int> Game::playRoundForActive(const std::vector<size_t>& activeIndices) {
    std::cout << "\n Ходы \n";

    std::vector<Move> moves(players_.size());

    // Опрашиваем только активных
    for (size_t idx : activeIndices) {
        moves[idx] = players_[idx]->chooseMove();
        std::cout << "  " << players_[idx]->name()
                  << " (" << players_[idx]->type()
                  << ") выбрал: " << moves[idx].toString() << "\n";
    }

    // Считаем очки между активными
    std::vector<int> roundPts(players_.size(), 0);
    const Rules& rules = Rules::instance();

    std::cout << "\n Результаты \n";
    for (size_t i : activeIndices) {
        for (size_t j : activeIndices) {
            if (i == j) continue;
            if (rules.compare(moves[i], moves[j]) == 1) {
                roundPts[i]++;
                std::cout << "  " << moves[i].toString() << " "
                          << rules.describeBeat(moves[i], moves[j]) << " "
                          << moves[j].toString() << "\n";
            }
        }
    }

    // Начисляем
    std::cout << "\n";
    for (size_t i : activeIndices) {
        players_[i]->addScore(roundPts[i]);
        for (size_t j : activeIndices) {
            if (i != j)
                players_[i]->onRoundResult(moves[i], moves[j],
                                           rules.compare(moves[i], moves[j]));
        }
        std::cout << "  " << players_[i]->name() << " получает "
                  << roundPts[i] << " очков (всего: " << players_[i]->score() << ")\n";
    }

    return roundPts;
}

void Game::playTournament(int maxRounds) {
    std::cout << "\n НАЧАЛО ТУРНИРА \n";

    for (auto& p : players_) p->resetScore();

    std::vector<size_t> active;
    for (size_t i = 0; i < players_.size(); ++i) active.push_back(i);

    int stage = 0;
    int consecutiveNoWinner = 0;

    while (active.size() > 1 && stage < maxRounds) {
        ++stage;
        std::cout << "\n ЭТАП " << stage << " (участников: " << active.size() << ")\n";

        std::vector<int> pts = playRoundForActive(active);

        int maxPts = 0;
        for (size_t idx : active) {
            if (pts[idx] > maxPts) maxPts = pts[idx];
        }

        if (maxPts == 0) {
            ++consecutiveNoWinner;
            std::cout << "\n  [Ничья на этапе — переигровка]\n";
            if (consecutiveNoWinner >= 5) {
                std::cout << "\nСлишком много переигровок подряд. Турнир завершён.\n";
                return;
            }
            continue;
        }
        consecutiveNoWinner = 0;

        std::vector<size_t> survivors;
        std::cout << "\n";
        for (size_t idx : active) {
            if (pts[idx] == maxPts) {
                survivors.push_back(idx);
                std::cout << "  " << players_[idx]->name() << " проходит дальше.\n";
            } else {
                std::cout << "  " << players_[idx]->name() << " выбывает.\n";
            }
        }

        if (survivors.size() == 1) {
            size_t w = survivors[0];
            std::cout << "ПОБЕДИТЕЛЬ: " << players_[w]->name()
                      << " (" << players_[w]->type() << ")\n";
            announceScores();
            return;
        }

        std::cout << "\n  Дуэль между: ";
        for (size_t idx : survivors) std::cout << players_[idx]->name() << " ";

        active = survivors;
    }

    if (stage >= maxRounds)
        std::cout << "\nДостигнут лимит этапов. Победитель не определён.\n";
}

void Game::announceScores() const {
    std::cout << "\nИТОГОВЫЕ СЧЁТЫ:\n";
    for (const auto& p : players_) {
        std::cout << "  " << p->name() << ": " << p->score() << "\n";
    }
}