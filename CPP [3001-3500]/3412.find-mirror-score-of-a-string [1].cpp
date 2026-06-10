class Solution {
public:
    // T.C.=O(n + 26), S.C.=O(n + 26)
    long long calculateScore(string s) {
        int n = s.length();
        vector<stack<int>> idxs(26);
        long long int score = 0;

        for(int i=0; i<n; i++)
        {
            // indexes of closest unmarked mirror chars of s[i]
            stack<int>& st = idxs[25 - (s[i] - 'a')];

            if(!st.empty())
            {
                score += i - st.top();
                st.pop();
            }
            else
                idxs[s[i] - 'a'].push(i);
        }

        return score;
    }
};