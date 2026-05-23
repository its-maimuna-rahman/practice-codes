// practicing constructors and encapsulation

/*  
1. Create a Smartphone class with private attributes
2. Add constructor
3. Use encapsulation properly
4. Handle invalid input WITHOUT cout inside logic functions
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Smartphone {
private:                        // Encapsulation
    string brand;
    string model;
    int battery_life;
    string security_pass;

public:
    // 🔹 Constructor
    Smartphone(string b, string m, int bl, string p)
        : brand(b), model(m), battery_life(bl), security_pass(p) {}

    // 🔹 Getter methods
    string getBrand() const {
        return brand;
    }

    int getBattery() const {
        return battery_life;
    }

    // 🔹 Use battery (logic only)
    bool use(int amount, string pass) {
        if (pass != security_pass) return false;
        if (amount <= 0 || amount > battery_life) return false;

        battery_life -= amount;
        return true;
    }

    // 🔹 Charge battery (logic only)
    bool charge(int amount, string pass) {
        if (pass != security_pass) return false;
        if (amount <= 0) return false;

        battery_life += amount;
        if (battery_life > 100) battery_life = 100;
        return true;
    }
};

int main() {

    cout << "\n========== SMARTPHONE MANAGER ==========\n";

    int n;
    cout << "How many phones you want to add? : ";
    cin >> n;

    vector<Smartphone> phone;

    for (int i = 0; i < n; i++) {
        string brand, model, pass;
        int battery;

        cout << "\n--- Phone " << i + 1 << " ---\n";
        cout << "Enter brand name     : ";
        cin >> brand;
        cout << "Enter model name     : ";
        cin >> model;

        do {
            cout << "Enter battery (0-100): ";
            cin >> battery;
        }
        while(battery < 0 || battery > 100);

        cout << "Set security pass    : ";
        cin >> pass;

        phone.emplace_back(brand, model, battery, pass);
    }

    while (true) {
        int choice;
        cout << "\n========== MENU ==========\n";
        cout << "1. Use battery\n";
        cout << "2. Charge battery\n";
        cout << "3. Exit\n";
        cout << "Enter choice : ";
        cin >> choice;

        if (choice == 3) {
            cout << "\n========== EXIT ==========\n";
            break;
        }

        int serial, amount;
        string password;

        cout << "Enter phone serial (1 to " << n << ") : ";
        cin >> serial;

        if (serial < 1 || serial > n) {
            cout << "Invalid phone serial.\n";
            continue;
        }

        cout << "Enter amount : ";
        cin >> amount;

        cout << "Enter security pass : ";
        cin >> password;

        // p is a reference to one Smartphone object inside the vector
        Smartphone &p = phone[serial - 1];

        if (choice == 1) {
            if (p.use(amount, password)) {
                cout << p.getBrand() << " used "
                     << amount << "% battery.\n";
                cout << "Current battery: "
                     << p.getBattery() << "%\n";
            } else {
                cout << "Operation failed (wrong pass / invalid amount)\n";
            }
        }
        else if (choice == 2) {
            if (p.charge(amount, password)) {
                cout << p.getBrand() << " charged "
                     << amount << "% battery.\n";
                cout << "Current battery: "
                     << p.getBattery() << "%\n";
            } else {
                cout << "Operation failed (wrong pass / invalid amount)\n";
            }
        }
        else {
            cout << "Invalid menu choice.\n";
        }
    }

    return 0;
}
