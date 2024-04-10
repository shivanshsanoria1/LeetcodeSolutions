class Solution {
private:
    void solve(string& s, int i, unordered_set<string>& dict, string& curr){
        if(i >= s.length())
            return;
        
        // exclude index i
        solve(s, i+1, dict, curr);
        
        // include index i
        curr += s[i];

        if(curr.length() < 3)
            solve(s, i+1, dict, curr);
        else if(curr[0] == curr[2])
            dict.insert(curr);

        curr.pop_back();
    }

public:
    // T.C.=O(2^n)
    // Recursion
    int countPalindromicSubsequence(string s) {
        unordered_set<string> dict;
        string curr = "";
        solve(s, 0, dict, curr);
        return dict.size();
    }
};