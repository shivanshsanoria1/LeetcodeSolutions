class Solution {
public:
    // T.C.=O(n*logn), S.C.=O(n)
    vector<string> findRelativeRanks(vector<int>& score) {
        // score -> index
        map<int, int> mp;

        int n=score.size();
        for(int i=0; i<n; i++)
            mp[score[i]] = i;

        vector<string> ans(n, "");
        int pos = 1; // position
        for(auto itr = mp.rbegin(); itr != mp.rend(); itr++)
        {
            int idx = itr->second;

            if(pos == 1)
                ans[idx] = "Gold Medal";
            else if(pos == 2)
                ans[idx] = "Silver Medal";
            else if(pos == 3)
                ans[idx] = "Bronze Medal";
            else
                ans[idx] = to_string(pos);

            pos++;
        }

        return ans;
    }
};