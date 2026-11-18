#include "../include/BotPlayer.h"

BotPlayer::BotPlayer(std::string name, unsigned seed)
    : Player(std::move(name)), rng_(seed) {}

Move BotPlayer::chooseMove() {
    std::uniform_int_distribution<int> d(0, 4);
    return Move::fromIndex(d(rng_));
}