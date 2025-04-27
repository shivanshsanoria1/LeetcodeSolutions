class Solution {
public:
    // T.C.=O(m*n), S.C.=O(m*n)
    string findCommonResponse(vector<vector<string>>& responses) {
        // distinct response string in each row -> freq
        unordered_map<string, int> mp;
        for(vector<string>& response: responses)
        {
            unordered_set<string> s(response.begin(), response.end());
            for(string res: s)
                mp[res]++;
        }

        string ans = "";
        int maxFreq = 0;
        for(auto [res, freq]: mp)
        {
            if(freq > maxFreq)
            {
                maxFreq = freq;
                ans = res;
            }
            else if(freq == maxFreq)
                ans = min(ans, res);
        }

        return ans;
    }
};