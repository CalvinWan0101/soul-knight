#include "stdafx.h"
#include "Wallet.h"

Wallet::Wallet() : money(0) {
    
}

void Wallet::MakeMoney(int money) {
    this->money += money;
}

bool Wallet::SpendMoney(int money) {
    if (this->money >= money) {
        this->money -= money;
        return true;
    }
    else {
        return false;   
    }
}

int Wallet::GetMoney() {
    return money;
}

