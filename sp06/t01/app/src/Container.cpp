#include "Container.h"

Container::Container(bool isLocked, const LockpickDifficulty difficulty)
    : m_isLocked(isLocked), m_difficulty(difficulty) {}

LockpickDifficulty Container::lockDifficulty() const { return m_difficulty; }

bool Container::isLocked() const { return m_isLocked; }

bool Container::tryToOpen(LockpickDifficulty skill) { return true; }

std::string Barrel::name() const { return "Barrel"; }

std::string Chest::name() const { return "Chest"; }

std::string Safe::name() const { return "Safe"; }


Barrel::Barrel() : Container(false, LockpickDifficulty::None) {}

Barrel::Barrel(bool isLocked, const LockpickDifficulty difficulty)
    : Container(isLocked, difficulty) {}

Chest::Chest() : Container(false, LockpickDifficulty::None) {}

Chest::Chest(bool isLocked, const LockpickDifficulty difficulty)
    : Container(isLocked, difficulty) {}

Safe::Safe() : Container(false, LockpickDifficulty::None) {}

Safe::Safe(bool isLocked, const LockpickDifficulty difficulty)
    : Container(isLocked, difficulty) {}
