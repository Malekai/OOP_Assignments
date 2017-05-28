#include <iostream>

using namespace std;

class Time
{
    int seconds;
    int minutes;
    int hours;
public:

    Time()
    {
        seconds = minutes = hours = 0;
    }

    Time(int h, int m = 0, int s = 0)
    {
        hours = h;
        minutes = m;
        seconds = s;
    }

    int getHours() const { return hours; }
    
    int getMinutes() const { return minutes; }
    
    int getSeconds() const { return seconds; }
    
    bool LessThan(Time otherTime) const
    {
        if(hours < otherTime.hours)
            return true;
        else if(hours > otherTime.hours)
            return false;
        else if(minutes < otherTime.minutes)
            return true;
        else if(minutes > otherTime.minutes)
            return false;
        else if(seconds < otherTime.seconds)
            return true;
        else
            return false;
    }

    bool GreaterThan(Time otherTime) const
    {
        if(hours > otherTime.hours)
            return true;
        else if(hours < otherTime.hours)
            return false;
        else if(minutes > otherTime.minutes)
            return true;
        else if(minutes < otherTime.minutes)
            return false;
        else if(seconds > otherTime.seconds)
            return true;
        else
            return false;
    }

    bool EqualTo(Time otherTime) const
    {
        if(!LessThan(otherTime) && !GreaterThan(otherTime))
            return true;
        return false;
    }

    void setHours(int h) { hours = h; }

    void setMinutes(int m) { minutes = m; }

    void setTime(int h = 0, int m = 0, int s = 0)
    {
        hours = h;
        minutes = m;
        seconds = s;
    }

    void Read()
    {
        char temp;
        cin >> hours >> temp >> minutes >> temp >> seconds;
    }

    void Write()
    {
        cout << hours << ":";
        cout << minutes << ":";
        cout << seconds << endl;
    }
    
    void ReadData(Time *tList, int tCount){
        
        tList = new Time[tCount];
        
        for(int i=0;i<tCount;i++){
            cout<<"\nEnter the time value "<<i+1<<" : ";
            tList[i].Read();
        }
        
        SortData(tList,tCount);
        WriteData(tList,tCount);
    }
    
    void SortData(Time *tList, int tCount){
        
        cout<<"\nSorted time values are : \n";
        
        for(int i=0; i<tCount; i++){
            for(int j=i+1; j<tCount; j++){
                
                if(tList[i].GreaterThan(tList[j])){
                    
                    Time temp=tList[i];
                    tList[i]=tList[j];
                    tList[j]=temp;
                }
            }
        }
    }
    
    void WriteData(Time *tList, int tCount){
        
        
        for(int i=0;i<tCount;i++)
            tList[i].Write();      
    }
};

int main()
{
    Time *tList;
    Time t1;
    int tCount;
    
    do{
        cout<<"\nHow many values are to be processed?\n";
        cin>>tCount;
        
        if(tCount<0 || tCount>100)
            cout<<"\nInvalid value!";
        
    }while(tCount<0 || tCount>100);
    
    tList = new Time[tCount];
    
    t1.ReadData(tList, tCount);
    //t1.SortData(tList, tCount);
    //t1.WriteData(tList, tCount);
}


