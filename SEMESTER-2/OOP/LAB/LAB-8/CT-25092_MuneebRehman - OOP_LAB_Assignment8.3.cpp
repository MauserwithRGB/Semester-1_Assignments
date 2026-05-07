#include <iostream>

class Account
{
protected:
    double balance;
public:
    Account(double b = 0) : balance(b) {}
    virtual void deposit(double amount) { balance += amount; }
    virtual void withdraw(double amount) { balance -= amount; }
    void checkBalance() { std::cout << "Balance: Rs." << balance << "\n"; }
};

class InterestAccount : virtual public Account
{
protected:
    double interest;  // as a percentage
public:
    InterestAccount(double b = 0, double i = 30.0) : Account(b), interest(i) {}
    void deposit(double amount) override {
        double withInterest = amount + (amount * interest / 100);
        balance += withInterest;
        std::cout << "Deposited Rs." << amount << " + Rs." << (amount * interest / 100) << " interest\n";
    }
};

class ChargingAccount : virtual public Account
{
protected:
    double fee;
public:
    ChargingAccount(double b = 0, double f = 25.0) : Account(b), fee(f) {}
    void withdraw(double amount) override {
        balance -= (amount + fee);
        std::cout << "Withdrew Rs." << amount << " + Rs." << fee << " fee\n";
    }
};

class ACI : public InterestAccount, public ChargingAccount
{
public:
    ACI(double b = 0, double i = 30.0, double f = 25.0)
        : Account(b), InterestAccount(b, i), ChargingAccount(b, f) {}

    void transfer(double amount, Account& target) {
        withdraw(amount);
        target.deposit(amount);
        std::cout << "Transferred Rs." << amount << "\n";
    }
    void transfer(double amount, InterestAccount& target) {
        withdraw(amount);
        target.deposit(amount);
        std::cout << "Transferred Rs." << amount << " to Interest Account\n";
    }
    void transfer(double amount, ChargingAccount& target) {
        withdraw(amount);
        target.deposit(amount);
        std::cout << "Transferred Rs." << amount << " to Charging Account\n";
    }
    void deposit(double amount) override { InterestAccount::deposit(amount); }
    void withdraw(double amount) override { ChargingAccount::withdraw(amount); }
};

int main()
{
    ACI myAccount(1000.0);
    std::cout << "-- Initial --\n";
    myAccount.checkBalance();

    std::cout << "\n-- Deposit Rs.500 --\n";
    myAccount.deposit(500);
    myAccount.checkBalance();

    std::cout << "\n-- Withdraw Rs.200 --\n";
    myAccount.withdraw(200);
    myAccount.checkBalance();

    Account other(500);
    std::cout << "\n-- Transfer Rs.100 to another account --\n";
    myAccount.transfer(100, other);
    myAccount.checkBalance();
}