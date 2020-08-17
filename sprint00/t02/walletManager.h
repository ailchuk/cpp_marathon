#ifndef WALLETMANAGER_H
#define WALLETMANAGER_H

#include <iostream>

struct Wallet {
    int septims;
};

Wallet *createWallet(int amount);
void destroyWallet(Wallet *w);
Wallet *createWallets(int amount);
void destroyWallets(Wallet *w);

#endif