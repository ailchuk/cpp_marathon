#pragma once

#include <iostream>

struct Wallet {
    int septims;
};

Wallet *createWallet(int amount);
void destroyWallet(Wallet *w);
Wallet *createWallets(int amount);
void destroyWallets(Wallet *wallets);
