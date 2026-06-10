class Solution {
public:
    // T.C.=O(q*n), S.C.=O(1)
    vector<int> maximumSumQueries(vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& queries) {
        vector<int> ans;
        for(vector<int>& query: queries)
        {
            int x = query[0];
            int y = query[1];
            int maxVal = -1;

            for(int i=0; i<nums1.size(); i++)
                if(nums1[i] >= x && nums2[i] >= y)
                    maxVal = max(maxVal, nums1[i] + nums2[i]);
            
            ans.push_back(maxVal);
        }

        return ans;
    }
};