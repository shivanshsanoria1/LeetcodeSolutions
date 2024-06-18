class Solution {
public:
    // T.C.=O(q*n), S.C.=O(1)
    vector<int> countOfPeaks(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> ans;

        for(vector<int>& query: queries)
        {
            int type = query[0];

            if(type == 1)
            {
                int left = query[1];
                int right = query[2];

                int count = 0;

                for(int i=left + 1; i < right; i++)
                    if(nums[i-1] < nums[i] && nums[i] > nums[i+1])
                        count++;

                ans.push_back(count);
            }
            else // type == 2
            {
                int idx = query[1];
                int val = query[2];

                nums[idx] = val;
            }
        }

        return ans;
    }
};