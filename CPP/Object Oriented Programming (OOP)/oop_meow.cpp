// learning class and objects

#include <iostream>
#include <string>
using namespace std;

class cat {
    public :
        //attributes (data)
        string name;
        int age;

        //method (function)
        void meow() {
            cout << name << " meow meow" << endl;
        }

        void catYears() {
            cout << "The " << name << " meow is " << age << " years old." << endl;
        }
};

int main() {

    cat cat1;
    cat1.name = "Olivia";
    cat1.age = 3;

    cat cat2;
    cat2.name = "Benjamin";
    cat2.age = 1;

    cat cat3;
    cat3.name = "Meredith";
    cat3.age = 2;

    cat1.meow();
    cat2.meow();

    cout << endl;

    cat2.catYears();
    cat3.catYears();

    return 0;
}