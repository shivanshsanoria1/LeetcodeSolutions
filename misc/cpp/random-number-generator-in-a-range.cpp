#include <bits/stdc++.h>
using namespace std;

// generates a random-number in range [start, end]
int generateRandomNumber(int start, int end){
    return start + rand() % (end - start + 1);
}

int main(){
    int count = 1373;
    int start = 1;
    int end = 50;
    
    double meanFreq = (double)count / (end - start + 1);

    // number -> frequency
    map<int, int> mp;
    // Frequencies
    vector<int> freqs;

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
        
        freqs.push_back(freq);
    }
    
    cout<<endl<<string(25, '-')<<endl;
    
    cout<<"Expected Mean Freq = "<<meanFreq<<endl;
    
    sort(freqs.begin(), freqs.end());
    double medianFreq = freqs.size() % 2 == 0 
    ? ((double)freqs[freqs.size()/2 - 1] + freqs[freqs.size()/2])/2 
    : freqs[freqs.size()/2];
    cout<<"Median Freq = "<<medianFreq<<endl;
    
    cout<<"Min Freq = "<<minFreq<<endl;
    cout<<"Max Freq = "<<maxFreq<<endl;
    
    double deviationInMinFreq = ((minFreq - meanFreq)/meanFreq) * 100;
    double deviationInMaxFreq = ((maxFreq - meanFreq)/meanFreq) * 100;
    cout<<"Deviation in Min freq = "<<deviationInMinFreq<<" % "<<endl;
    cout<<"Deviation in Max freq = "<<deviationInMaxFreq<<" % "<<endl;
    
    cout<<endl<<string(25, '-')<<endl;
    
    return 0;
}