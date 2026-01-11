#include <bits/stdc++.h>
using namespace std;

// splits the input string into an array of strings 
// on the basis of delimiter char
vector<string> splitString(string& str, char delimiter){
    vector<string> tokens;
    string token = "";
    
    str += delimiter;
    for(char ch: str)
    {
        if(ch == delimiter)
        {
            tokens.push_back(token);
            token = "";
        }
        else
            token += ch;
    }
    str.pop_back();
    
    return tokens;
}

// splits the input string into an array of strings 
// on the basis of delimiter char (using stringstream)
vector<string> splitStringSS(const string& str, char delimiter){
    istringstream iss(str);
    vector<string> tokens;
    string token = "";
    
    while(getline(iss, token, delimiter))
        tokens.push_back(token);
    
    return tokens;
}

int main() {
    string sentence1 = "this is a space separated sentence";
    // vector<string> tokens1 = splitString(sentence1, ' ');
    vector<string> tokens1 = splitStringSS(sentence1, ' ');
    
    cout<<sentence1<<endl;
    for(string& token: tokens1)
        cout<<token<<endl;
    
    cout<<endl;
    
    string sentence2 = "this,is,a,comma,separated,sentence";
    // vector<string> tokens2 = splitString(sentence2, ',');
    vector<string> tokens2 = splitStringSS(sentence2, ',');
    
    cout<<sentence2<<endl;
    for(string& token: tokens2)
        cout<<token<<endl;
    
    cout<<endl<<string(25, '-')<<endl;

    return 0;
}