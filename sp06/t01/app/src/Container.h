#pragma once

#include <iostream>

enum class LockpickDifficulty {
  None = 0,
  Noveice = 25,
  Apprentice = 40,
  Adept = 60,
  Expert = 80,
  Master = 100
};

class ILockable {
  virtual LockpickDifficulty lockDifficulty() const = 0;
  virtual bool isLocked() const = 0;
};

class IOpenable {
  virtual bool tryToOpen(LockpickDifficulty) = 0;
};

class Container : public ILockable, public IOpenable {
 public:
  Container(bool isLocked, const LockpickDifficulty difficulty);
  LockpickDifficulty lockDifficulty() const;
  bool isLocked() const;
  bool tryToOpen(LockpickDifficulty skill);
  virtual std::string name() const = 0;

 private:
  bool m_isLocked{false};
  LockpickDifficulty m_difficulty;
};

class Barrel : public Container {
 public:
  Barrel();
  Barrel(bool isLocked, const LockpickDifficulty difficulty);
  std::string name() const;

 private:
  bool m_isLocked{true};
};

class Chest : public Container {
 public:
  Chest();
  Chest(bool isLocked, const LockpickDifficulty difficulty);
  std::string name() const;
 private:
};

class Safe : public Container {
 public:
  Safe();
  Safe(bool isLocked, const LockpickDifficulty difficulty);
  std::string name() const;
 private:
};