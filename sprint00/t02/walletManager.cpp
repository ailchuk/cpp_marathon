#include "walletManager.h"

Wallet *createWallet(int amount) {
  Wallet *w = new Wallet;

  w->septims = amount;

  return w;
}

void destroyWallet(Wallet *w) {
  delete w;
}

Wallet *createWallets(int amount) {
  Wallet *w = new Wallet[amount];

  return w;
}

void destroyWallets(Wallet *w) {
  delete [] w;
}