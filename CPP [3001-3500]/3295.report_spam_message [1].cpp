class Solution {
public:
    // T.C.=O(m + b), S.C.=O(b)
    // m: size of message[], b: size of bannedWords[]
    bool reportSpam(vector<string>& message, vector<string>& bannedWords) {
        unordered_set<string> s(bannedWords.begin(), bannedWords.end());
        int count = 0;

        for(string& word: message)
            if(s.find(word) != s.end() && ++count == 2)
                return true;
        
        return false;
    }
};