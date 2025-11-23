#include <bits/stdc++.h>
using namespace std;

string generateRandomAlphaNumericString(int len){
    vector<char> chars;
    
    // uppercase-alphabets: A-Z
    for(char ch = 'A'; ch <= 'Z'; ch++)
        chars.push_back(ch);
    
    // digits: 0-9
    for(char ch = '0'; ch <= '9'; ch++)
        chars.push_back(ch);
    
    // lowercase-alphabets: a-z
    for(char ch = 'a'; ch <= 'z'; ch++)
        chars.push_back(ch);
    
    string randStr = "";
    
    while(len-- > 0)
    {
        int randIdx = rand() % chars.size();
        randStr += chars[randIdx];
    }
    
    return randStr;
}

int main(){
    // number of strings to be generated
    int count = 100;
    // length of each string
    int len = 13;
    
    srand(time(0)); // seed for rand()
    
    cout<<"Generating "<<count<<" random alphanumeric strings of length = "<<len<<" ... "<<endl<<endl;
    
    for(int i=1; i<=count; i++)
        cout<<i<<" -> "<<generateRandomAlphaNumericString(len)<<endl;
    
    cout<<endl<<string(25, '-')<<endl;
    
    return 0;
}