class Solution {
private:
    int solve(string& s, int i, string curr, unordered_set<string>& dict){
        if(i == s.length())
            return 0;

        curr += s[i];

        int noSplit = solve(s, i+1, curr, dict);

        int split = 0; 
        // 'curr' not found in 'dict'
        if(dict.find(curr) == dict.end())
        {
            dict.insert(curr);
            split = 1 + solve(s, i+1, "", dict);
            dict.erase(curr);
        }

        return max(split, noSplit);
    }

public:
    // T.C.=O(2^n), S.C.=O(n)
    // Backtracking
    int maxUniqueSplit(string s) {
        unordered_set<string> dict;
        
        return solve(s, 0, "", dict);
    }
};