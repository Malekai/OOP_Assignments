#include <iostream>

using namespace std;

double doublePower(double b, int e) {
    if (e == 1)
        return b * 1;
    else if (e > -1)
        e--;
        return b * (doublePower(b, e));
}

double presentValue(double payment, double interest, int term) {
    double z = 1 / doublePower((1+interest), term);
    double pv = payment * ((1 - z) / interest);
    
    return pv;
}

void readData(double &payment, double &interest, int &term) {
    cout << "What is the payment value?: " << endl;
    cin >> payment;
    cout << "What is the interest?: " << endl;
    cin >> interest;
    if (interest < 0 || interest > 100) {
        cout << "Interest rate invalid, try again: ";
        cin >> interest;
    }
    cout << "What is the term length?: " << endl;
    cin >> term;
}

int main() {
    double payment;
    double interest;
    int term;
    char answer;
    do {
        readData(payment, interest, term);
        cout << "The present value is: " << presentValue(payment, interest, term) << endl;
        cout << "Do you want to do another present value computation? answer Y/N: ";
        cin >> answer;
    } while ( answer == 'Y' || answer == 'y');
}
