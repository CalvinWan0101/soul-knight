#pragma once

class Wallet {
public:
    Wallet();
    void MakeMoney(int money);
    bool SpendMoney(int money);
    int GetMoney();

private:
    int money;
};
