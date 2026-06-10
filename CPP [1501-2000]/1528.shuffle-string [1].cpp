class Solution {
public:
    // T.C.=O(n), S.C.=O(1)
    string restoreString(string s, vector<int>& indices) {
        int n = s.length();
        string ans(n, '#');

        for(int i=0; i<n; i++)
            ans[indices[i]] = s[i];

        return ans;
    }
};