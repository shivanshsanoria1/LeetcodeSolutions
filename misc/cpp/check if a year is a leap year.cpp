#include <bits/stdc++.h>
using namespace std;

bool isLeapYear(int year){
    return year % 100 == 0 ? year % 400 == 0 : year % 4 == 0;
}

int main() {
    vector<int> years = { 12, 2024, 3000, 3200, 3100, 2100 };
    
    for(int year: years)
    {
        cout<<"Year "<<year;
        if(isLeapYear(year))
            cout<<" is a Leap year"<<endl;
        else
            cout<<" is not a leap year"<<endl;
    }
    
    cout<<endl<<string(25, '-')<<endl;

    return 0;
}