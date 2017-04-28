//Minhajul Malek
//Assignment 3

#include <iostream>

using namespace std;

bool isPrime(int num) {
    if (num < 2) return false;
    if (num == 2) return true;
    if (num % 2 == 0) return false;
    for (int i = 3; i < num; i++) {
        if (num % i == 0) return false;
    }
    return true;
}

int prime(int n) {
    int c = 0;
    int x = 0;
    while (c < n) {
        x++;
        if (isPrime(x)) {
            c++;
        }
    }
    return x;
}

int main() {
    char input;
    do {
        cout << "F: Find the nth prime number\nT: Test a value to see if it is prime\nQ: Terminate the program" << endl;
        cin >> input;
        if (input == 'F' || input == 'f') {
            int n;
            cout << "Give me a number" << endl;
            cin >> n;
            cout << prime(n) << endl;
        }
        if (input == 'T' || input == 't') {
            int num;
            cout << "Give me a number" << endl;
            cin >> num;
            cout << boolalpha << isPrime(num) << endl;
        }

    } while (input != 'Q' && input != 'q');
};