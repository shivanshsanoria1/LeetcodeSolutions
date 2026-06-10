class Solution {
public:
    // T.C.=O(n*logn), S.C.=O(n)
    vector<string> findRelativeRanks(vector<int>& score) {
        // { score, index }
        vector<pair<int, int>> ranks;

        int n=score.size();
        for(int i=0; i<n; i++)
            ranks.push_back({score[i], i});
        
        // sort in decreasing order of scores
        sort(ranks.begin(), ranks.end(), greater<pair<int, int>>());

        vector<string> ans(n, "");
        int pos = 1; // position
        for(auto [score, idx]: ranks)
        {
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