class Solution {
private:
    void solve(string& s, unordered_set<string>& dict, vector<unordered_set<string>>& dp, int i, string& curr){
        if(i >= s.length())
            return;
        
        if(dp[i].find(curr) != dp[i].end())
            return;

        dp[i].insert(curr);

        // exclude index i
        solve(s, dict, dp, i+1, curr);
        
        // include index i
        curr += s[i];

        if(curr.length() < 3)
            solve(s, dict, dp, i+1, curr);
        else if(curr[0] == curr[2])
            dict.insert(curr);

        curr.pop_back();
    }

public:
    // T.C.=O()
    // DP-Memoization
    int countPalindromicSubsequence(string s) {
        int n=s.length();
        unordered_set<string> dict;
        string curr = "";
        vector<unordered_set<string>> dp(n);
        solve(s, dict, dp, 0, curr);
        return dict.size();
    }
};