#pragma once
#include "Move.h"
#include <string>

// Абстрактный игрок. Все наследники реализуют chooseMove().
class Player {
public:
    //конструктор, принимает имя, инициализирует поле и обнуляет счётчик
    explicit Player(std::string name) : name_(std::move(name)), score_(0) {}
    virtual ~Player() = default;

    virtual Move chooseMove() = 0;   // главный метод - делаем ход
    virtual std::string type() const = 0;// возвращает строку - кто ты?

    const std::string& name() const { return name_; }
    int score() const { return score_; }
    void addScore(int s) { score_ += s; }
    void resetScore() { score_ = 0; } //сброс

    // результат после каждого раунда
    virtual void onRoundResult(const Move& /*mine*/,
                               const Move& /*other*/,
                               int /*result*/) {}

protected:
    std::string name_;
    int score_;
};