#include "../include/SmartBot.h"
#include "../include/Rules.h"

SmartBot::SmartBot(std::string name, unsigned seed)
    : Player(std::move(name)), rng_(seed) { freq_.fill(0); }

void SmartBot::observe(const Move& m) { freq_[m.value()]++; observed_++; }

void SmartBot::onRoundResult(const Move&, const Move& other, int) {
    observe(other);
}

Move SmartBot::chooseMove() {
    // Если данных мало — случайный ход
    if (observed_ < 3) {
        std::uniform_int_distribution<int> d(0, 4);
        return Move::fromIndex(d(rng_));
    }
    // Иначе — найти самый частый ход соперника
    int best = 0;
    for (int i = 1; i < 5; ++i) if (freq_[i] > freq_[best]) best = i;
    Move target = Move::fromIndex(best);

    // Найти ход, бьющий target
    for (int i = 0; i < 5; ++i) {
        Move cand = Move::fromIndex(i);
        if (Rules::instance().compare(cand, target) == 1) return cand;
    }
    return Move::fromIndex(0);
}