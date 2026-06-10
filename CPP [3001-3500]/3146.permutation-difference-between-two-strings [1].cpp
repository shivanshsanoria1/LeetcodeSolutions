class Solution {
public:
    int findPermutationDifference(string s, string t) {
        int n=s.length();
        // stores the index of each char in 's'
        vector<int> pos(26, -1);

        for(int i=0; i<n; i++)
            pos[s[i] - 'a'] = i;
        
        int ans = 0;

        for(int i=0; i<n; i++)
            ans += abs(i - pos[t[i] - 'a']);
        
        return ans;
    }
};