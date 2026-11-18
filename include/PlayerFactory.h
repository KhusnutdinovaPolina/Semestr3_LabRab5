#pragma once
#include "Player.h"
#include <memory>
#include <string>

// Простая фабрика (Factory Method) для создания игроков нужного типа
class PlayerFactory {
public:
    enum Kind { HUMAN, RANDOM_BOT, SMART_BOT };
    //создаём игрока нужного типа
    static std::unique_ptr<Player> create(Kind k, const std::string& name);
};