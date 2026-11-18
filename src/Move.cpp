#include "../include/Move.h"
#include <array>
#include <stdexcept>
#include <algorithm>

static const std::array<std::string, 5> NAMES = {
    "Камень", "Бумага", "Ножницы", "Ящерица", "Спок"
};
//конструктор из строки
Move::Move(const std::string& name) {
    auto it = std::find(NAMES.begin(), NAMES.end(), name);
    if (it == NAMES.end()) throw std::invalid_argument("Неизвестный ход: " + name);
    v_ = static_cast<Value>(std::distance(NAMES.begin(), it));
}

std::string Move::toString() const { return NAMES[v_]; }

Move Move::fromIndex(int i) {
    if (i < 0 || i >= 5) throw std::out_of_range("bad index");
    return Move(static_cast<Value>(i));
}