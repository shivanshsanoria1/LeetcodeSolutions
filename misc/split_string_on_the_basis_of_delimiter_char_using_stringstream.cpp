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
    string sentence = "this is a space separated sentence";
    vector<string> tokens = splitString(sentence, ' ');
    
    // string sentence = "this,is,a,comma,separated,sentence";
    // vector<string> tokens = splitString(sentence, ',');
    
    for(string& token: tokens)
        cout<<token<<endl;
    
    cout<<endl<<"-------------------"<<endl;

    return 0;
}