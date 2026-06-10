class Solution {
public:
    void solve(vector<string>& perms, string& s, int i){
        if(i == s.length())
        {
            perms.push_back(s);
            return;
        }

        solve(perms, s, i+1);

        if(s[i] >= 'a' && s[i] <= 'z')
        {
            s[i] = toupper(s[i]);
            solve(perms, s, i+1);
            s[i] = tolower(s[i]);

        }
        else if(s[i] >= 'A' && s[i] <= 'Z')
        {
            s[i] = tolower(s[i]);
            solve(perms, s, i+1);
            s[i] = toupper(s[i]);
        }
    }

    vector<string> letterCasePermutation(string s) { // Backtracking, T.C.=O(2^n)
        vector<string> perms;
        solve(perms, s, 0);
        return perms;
    }
};