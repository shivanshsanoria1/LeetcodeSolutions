class Solution {
public:
    // T.C.=O(n), S.C.=O(1)
    string shiftingLetters(string s, vector<int>& shifts) {
        int postfixSum = 0;
        string ans = "";

        for(int i=shifts.size()-1; i>=0; i--)
        {
            postfixSum = (postfixSum + shifts[i]) % 26;
            ans += (((s[i] - 'a') + postfixSum) % 26) + 'a';
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};