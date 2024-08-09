class Solution {
public:
    // T.C.=O(q*n*log(n)), S.C.=O(n)
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        vector<int> ans;
        for(vector<int>& query: queries)
        {
            int k = query[0];
            int d = query[1];
            int l = nums[0].length();

            vector<pair<string, int>> temp;
            for(int i=0; i<nums.size(); i++)
                temp.push_back({nums[i].substr(l-d), i});
            
            sort(temp.begin(), temp.end());
            
            ans.push_back(temp[k-1].second);
        }

        return ans;
    }
};