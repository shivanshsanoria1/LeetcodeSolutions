#include <bits/stdc++.h>
using namespace std;

// splits the input string into an array of strings 
// on the basis of delimiter char
vector<string> splitString(string& str, char delimiter){
    stringstream ss(str);
    vector<string> tokens;
    string token = "";
    
    while(getline(ss, token, delimiter))
        tokens.push_back(token);
    
    return tokens;
}

int main() {
    string sentence1 = "this is a space separated sentence";
    vector<string> tokens1 = splitString(sentence1, ' ');
    
    cout<<sentence1<<endl;
    for(string& token: tokens1)
        cout<<token<<endl;
    
    cout<<endl;
    
    string sentence2 = "this,is,a,comma,separated,sentence";
    vector<string> tokens2 = splitString(sentence2, ',');
    
    cout<<sentence2<<endl;
    for(string& token: tokens2)
        cout<<token<<endl;
    
    cout<<endl<<"-------------------"<<endl;

    return 0;
}