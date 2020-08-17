#include "walletManager.h"

Wallet *createWallet(int amount) {
  Wallet *w = new Wallet;

  w->septims = amount;

  return w;
}

void destroyWallet(Wallet *w) {
  delete w;

  w = NULL;
}

Wallet *createWallets(int amount) {
  return new Wallet[amount];
}

void destroyWallets(Wallet *wallets) {
  delete wallets;
}