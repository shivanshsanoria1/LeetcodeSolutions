class Solution {
public:
    // T.C.=O(n + q), S.C.=O(n)
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        // num -> {idx}
        unordered_map<int, vector<int>> mp;

        int n = nums.size();
        for(int i=0; i<n; i++)
            mp[nums[i]].push_back(i);

        vector<int> minDists(n, -1);
        for(auto& [num, idxs]: mp)
        {
            if(idxs.size() == 1)
                continue;

            int m = idxs.size();
            for(int i=0; i<m; i++)
            {
                int minDist = n;

                int prev = idxs[(i-1+m) % m];
                int curr = idxs[i];
                int next = idxs[(i+1) % m];

                // dist between 'curr' and 'next' in forward and reverse directions
                minDist = min(minDist, abs(curr - next));
                minDist = min(minDist, n - abs(curr - next));
                // dist between 'curr' and 'prev' in forward and reverse directions
                minDist = min(minDist, abs(curr - prev));
                minDist = min(minDist, n - abs(curr - prev));

                minDists[idxs[i]] = minDist;
            }
        }

        vector<int> ans;
        for(int query: queries)
            ans.push_back(minDists[query]);

        return ans;
    }
};