//Minhajul Malek
//Assignment One

#include <iostream>

using namespace std;

int main() {
    // get number of inputs from user and hold them
    int amount;
    
    cout << "How many inputs? " << endl;
    cin >> amount;
    float values[amount];
    
    // loop through and add user input to values
    // compute total and average
    float n;
    float total = 0;
    if (amount > 0) {
        for (int x = 0; x < amount; x++) {
            cout << "Give me a number: " << endl;
            cin >> n;
            values[x] = n;
            total += n;
        }
    }
    
    float avg = total / amount;
    
    //find max/min and negatives
    int negativeCounter = 0;
    float max = values[0];
    float min = values[0];
    
    for (int j = 0; j < amount; j++) {
        if (values[j] < 0) {
            negativeCounter++;
        }
        if (max < values[j]) {
            max = values[j];
        } else if (min > values[j]) {
            min = values[j];
        }
    }
    
    
    cout << "Number of values inputted: " << amount << endl;
    cout << "The sum of the values is: " << total << endl;
    cout << "The average of the values is: " << avg << endl;
    cout << "The number of negatives are: " << negativeCounter << endl;
    cout << "The largest number inputted is: " << max << endl;
    cout << "the smallest number inputted is: " << min << endl;
}
