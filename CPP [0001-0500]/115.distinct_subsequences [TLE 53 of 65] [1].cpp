class Solution {
public:
    int solve(string& s, string& t, int i, int j){
        if(j == t.length()) // string t is exhausted
            return 1;
        if(i == s.length()) // string s is exhausted
            return 0;
        // including s[i] in subsequence
        int include = s[i] == t[j] ? solve(s, t, i+1, j+1) : 0;
        // excluding s[i] from subsequence
        int exclude = solve(s, t, i+1, j);
        return include + exclude;
    }

    int numDistinct(string s, string t) { // Recursion
        if(s.length() < t.length())
            return 0;
        return solve(s, t, 0, 0);
    }
};