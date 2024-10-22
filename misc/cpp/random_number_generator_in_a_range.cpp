#include <bits/stdc++.h>
using namespace std;

// generates a random-number in range [start, end]
int generateRandomNumber(int start, int end){
    return start + rand() % (end - start + 1);
}

int main(){
    int count = 518;
    int start = 1;
    int end = 50;
    
    double avgFreq = (double)count / (end - start + 1);

    // number -> frequency
    map<int, int> mp;

    srand(time(0)); // seed for rand()
    
    cout<<"Generating "<<count<<" random numbers in range ["<<start<<", "<<end<<"]..."<<endl<<endl;
    
    while(count--)
        mp[generateRandomNumber(start, end)]++;
    
    cout<<"Number -> Frequency"<<endl;
    int minFreq = INT_MAX;
    int maxFreq = 0;
    
    for(auto [num, freq]: mp)
    {
        cout<<num<<" -> "<<freq<<endl;
        
        minFreq = min(minFreq, freq);
        maxFreq = max(maxFreq, freq);
    }
    
    cout<<endl;
    cout<<"Min Freq = "<<minFreq<<endl;
    cout<<"Max Freq = "<<maxFreq<<endl;
    cout<<"Avg Freq expected = "<<avgFreq<<endl;
    
    cout<<endl<<string(25, '-')<<endl;
    
    return 0;
}