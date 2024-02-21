class Solution {
public:
    bool isAcronym(vector<string>& words, string s) {
        string acr = ""; // acronym 
        for(string& word: words)
            acr += word[0];
        return s == acr ? true : false;
    }
};