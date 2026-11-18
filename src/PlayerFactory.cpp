#include "../include/PlayerFactory.h"
#include "../include/HumanPlayer.h"
#include "../include/BotPlayer.h"
#include "../include/SmartBot.h"

std::unique_ptr<Player> PlayerFactory::create(Kind k, const std::string& name) {
    switch (k) {
        case HUMAN:      return std::make_unique<HumanPlayer>(name);
        case RANDOM_BOT: return std::make_unique<BotPlayer>(name);
        case SMART_BOT:  return std::make_unique<SmartBot>(name);
    }
    return nullptr;
}