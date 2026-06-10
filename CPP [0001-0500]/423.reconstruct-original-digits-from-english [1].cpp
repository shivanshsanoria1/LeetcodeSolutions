class Solution {
public:
    // T.C.=O(n), S.C.=O(26 + 10)
    string originalDigits(string s) {
        vector<int> freqChar(26, 0);
        for(char ch: s)
            freqChar[ch - 'a']++;

        vector<int> freqDigit(10, 0);

        freqDigit[0] = freqChar['z' - 'a'];
        freqDigit[2] = freqChar['w' - 'a'];
        freqDigit[4] = freqChar['u' - 'a'];
        freqDigit[6] = freqChar['x' - 'a'];
        freqDigit[8] = freqChar['g' - 'a'];

        freqDigit[3] = freqChar['h' - 'a'] - freqDigit[8];
        freqDigit[5] = freqChar['f' - 'a'] - freqDigit[4];
        freqDigit[7] = freqChar['s' - 'a'] - freqDigit[6];

        freqDigit[1] = freqChar['o' - 'a'] - (freqDigit[0] + freqDigit[2] + freqDigit[4]);
        freqDigit[9] = freqChar['i' - 'a'] - (freqDigit[5] + freqDigit[6] + freqDigit[8]);

        string ans = "";
        for(int i=0; i<=9; i++)
        {
            string str(freqDigit[i], '0' + i);
            ans += str;
        }

        return ans;
    }
};

/*
name -> determining char

zero -> z
two -> w
four -> u
six -> x
eight -> g

three -> h (eight is already determined)
five -> f (four is already determined)
seven -> s (six is already determined)

one - o (zero, two, four are already determined)
nine - i (five, six, eight are already determined)

-----------------------------------------

char -> {name containing that char}

a -> 
b -> 
c -> 
d -> 
e -> zero, one, three, three, five, seven, seven, eight, nine, 
f -> four, five, 
g -> eight, 
h -> three, eight, 
i -> five, six, eight, nine, 
j -> 
k -> 
l -> 
m -> 
n -> one, seven, nine, nine, 
o -> zero, one, two, four, 
p -> 
q -> 
r -> zero, three, four, 
s -> six, seven, 
t -> two, three, eight, 
u -> four, 
v -> five, seven, 
w -> two, 
x -> six, 
y -> 
z -> zero, 

-----------------------------------------

Code to generate the above table:

#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<vector<string>> mp(26);
    
    vector<string> names = 
    {
        "zero",
        "one",
        "two",
        "three",
        "four",
        "five",
        "six",
        "seven",
        "eight",
        "nine",
    };
        
    for(string name: names)
        for(char ch: name)
            mp[ch - 'a'].push_back(name);
    
    for(int i=0; i<26; i++){
        cout<<char(i + 'a')<<" -> ";
        for(string name: mp[i])
            cout<<name<<", ";
        cout<<endl;
    }

    return 0;
}

*/