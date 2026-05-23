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
                    cout << endl;
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
                    cout << owner << " deposited $" << amount << " successfully.\n";
                    cout << "current balance : $" << balance;
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
                    cout << owner << " withdrawn$" << amount << " successfully.\n";
                    cout << "current balance : $" << balance;
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
    cout << "\n========== BANK ACCOUNTS ==========\n";
    int n;
    cout << "How many accounts you wanna add? : ";
    cin >> n;

    vector<BankAccount> account;
    cout << endl;

    for(int i = 0; i < n; i++) {
        int balance;
        string name, pass;

        cout << "enter owner's name : ";
        cin >> name;
        cout << "enter initial balance : ";
        cin >> balance;
        cout << "set password : ";
        cin >> pass;

        account.emplace_back(name, pass, balance);
        // shorting syntax by emplace_back.
        // account.push_back(BankAccount(name, pass, balance);
    }
    while(true) {
        int choice;
        cout << "\n========== MENU ==========\n";
        cout << "1. getBalance\n";
        cout << "2. deposit\n";
        cout << "3. withdraw\n";
        cout << "4. exit.\n";
        cout << "\nEnter choice : ";
        cin >> choice;

        if(choice == 1) {
            int acc_num;
            string password;
            cout << "Enter account number : ";
            cin >> acc_num;

            if(acc_num > (n-1)) {
                cout << "Incorrect account number.\n";
                continue;
            }

            cout << "Enter password : ";
            cin >> password;

            account[acc_num].getBalance(password);

        }
        else if(choice == 2) {
            int acc_num;
            double amount;
            string password;
            cout << "Enter account number : ";
            cin >> acc_num;

            if(acc_num > (n-1)) {
                cout << "Incorrect account number.\n";
                continue;
            }

            cout << "Enter deposit amount : ";
            cin >> amount;
            cout << "Enter password : ";
            cin >> password;

            account[acc_num].deposit(amount, password);
        }
        else if(choice == 3) {
            int acc_num;
            double amount;
            string password;
            cout << "Enter account number : ";
            cin >> acc_num;

            if(acc_num > (n-1)) {
                cout << "Incorrect account number.\n";
                continue;
            }

            cout << "Enter withdraw amount : ";
            cin >> amount;
            cout << "Enter password : ";
            cin >> password;

            account[acc_num].withdraw(amount, password);
        }
        else if(choice == 4) {
            cout << "========== EXIT ==========\n\n";
            return 0;
        }
        else {
            cout << "Invalid choice.\n";
        }
    }

    cout << endl;
    return 0;
}