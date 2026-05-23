// practicing constructors and encapsulation

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class BankAccount {
    private :               // Encapsulation
        string owner;
        string password;
        double balance;

    public :
        //constructor (need to be same name as class)
        // it will save all 3 data, but will show only name (bec wanna public only name)
        BankAccount(string o, string p, double b) 
                : owner(o), password(p), balance(b) {
                    
                    cout << "Account created for " << owner << endl;
                }
        
        // function. Getter method (to access private data)
        void getBalance(string pass) {
            if (pass == password) {
                cout << "owner : " << owner << endl;
                cout << "balance : $ " << balance << endl;
            }  
            else {
                cout << "incorrect password for " << owner << endl;
            }

        cout << endl;    
        }
        
        // function. Setter method (to modify private data safely)
        void deposit(double amount, string pass) {

            if(pass == password) {
                if(amount > 0) {
                    balance += amount;
                    cout << owner << " deposited $" << balance << " successfully.\n";
                    cout << "currenct balance : " << balance;
                }
                else {
                    cout << "invalid amount input.\n";
                }
            }
            else {
                cout << "incorrect password for " << owner;
            }

        cout << endl;    
        }

        // function. Setter method (to modify private data safely)
        void withdraw(double amount, string pass) {

            if(pass == password) {
                if(amount > 0 && balance >= amount) {
                    balance -= amount;
                    cout << owner << " withdrawed $" << balance << " successfully.\n";
                    cout << "currenct balance : " << balance;
                }
                else {
                    cout << "invalid amount input.\n";
                }
            }
            else {
                cout << "incorrect password.\n";
            }
         
        cout << endl;    
        }

};


int main() {
    vector<BankAccount> account;
    cout << endl;

    // shorting syntax by emplace_back.
    // account.push_back(BankAccount("John", "123", 1000);

    account.emplace_back("John", "123", 1000);
    account.emplace_back("Alice", "abc", 2000);
    account.emplace_back("Bob", "xyz", 500);

    cout << endl;
    account[0].getBalance("123");
    account[1].getBalance("123");
    account[2].getBalance("xyz");    

    account[0].deposit(600, "abc");
    account[1].withdraw(1000, "abc");
    account[2].deposit(500, "xyz");   

    cout << endl;
    return 0;
}