class Solution {
public:
    // T.C.=O(q*n), S.C.=O(1)
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> ans;
        for(vector<int>& query: queries)
        {
            int left = query[0];
            int right = query[1];

            int x = 0;
            for(int i=left; i<= right; i++)
                x ^= arr[i];

            ans.push_back(x);
        }

        return ans;
    }
};