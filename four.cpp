#include <iostream>

using namespace std;

class Time {
private:
    int hr;
    int min;
    int sec;
public:
    Time(){
        hr = 0;
        min = 0;
        sec = 0;
    }
    Time(int h, int m, int s){
        hr = h;
        min = m;
        sec = s;
    }
    int getHours(){
        return hr;
    }
    int getMinutes(){
        return min;
    }
    int getSeconds(){
        return sec;
    }
    void setHours(int h){
        hr = h;
    }
    void setMinutes(int m){
        min = m;
    }
    void setSeconds(int s){
        sec = s;
    }
    void setTime(int h, int m, int s){
        hr = h;
        min = m;
        sec = s;
    }
    bool LessThan(Time t){
        if (hr < t.getHours())
            return true;
        if (hr == t.getHours()){
            if (min < t.getMinutes())
                return true;
            if (min == t.getMinutes()){
                if (sec < t.getSeconds())
                    return true;
            }
        }
        return false;
    }
    bool GreaterThan(Time t){
        if (hr > t.getHours())
            return true;
        if (hr == t.getHours()){
            if (min > t.getMinutes())
                return true;
            if (min == t.getMinutes()){
                if (sec > t.getSeconds())
                    return true;
            }
        }
        return false;
    }
    bool EqualTo(Time t){
        if (hr == t.getHours() && min == t.getMinutes() && sec == t.getSeconds())
            return true;
        return false;
    }
    void Read(){
        string input;
        cout << "Enter value in hh:mm:ss format" << endl;
        cin >> input;
        hr = stoi(input.substr(0,2));
        min = stoi(input.substr(3,2));
        sec = stoi(input.substr(6,2));
    }
    void Write(){
        if (hr < 10)
            cout << "0" << hr << ":";
        else
            cout << hr << ":";
        if (min < 10)
            cout << "0" << min << ":";
        else
            cout << min << ":";
        if (sec < 10)
            cout << "0" << sec << endl;
        else
            cout << sec << endl;
        
    }
};

int main() {
    Time t1;
    Time t2(12,45,35);
    t1.Write();
    t2.Write();
    char i;
    do {
        cout << "Would you like to sort two times? Y for yes N for no to exit" << endl;
        cin >> i;
        if (i == 'Y' || i == 'y') {
            t1.Read();
            t2.Read();
            if (t1.LessThan(t2) || t1.EqualTo(t2)) {
                cout << "Here are the times in ascending order" << endl;
                t1.Write();
                t2.Write();
            }
            else {
                cout << "Here are the times in ascending order" << endl;
                t2.Write();
                t1.Write();
            }
        }
    } while (i != 'N' && i != 'n');
};
