class Solution {
public:
    int getValue(string s){
        string val = "";
        for(char ch: s)
            val += to_string(ch - 'a');
        return stoi(val);
    }

    bool isSumEqual(string firstWord, string secondWord, string targetWord) {
        return getValue(firstWord) + getValue(secondWord) == getValue(targetWord);
    }
};