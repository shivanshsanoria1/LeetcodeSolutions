class Solution {
public:
    // T.C.=O(q*n), S.C.=O(n)
    // 2-pointer
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int left = 0, right = 0;
        vector<pair<int, int>> ranges;

        while(right < nums.size())
        {
            // 'right' is the bad index which has broken our streak :(
            // subarray in range [left, right-1] is valid :)
            if(right - 1 >= 0 && nums[right - 1] % 2 == nums[right] % 2)
            {
                ranges.push_back({left, right - 1});
                left = right;
            }

            right++;
        }
        // don't forget to push the last range
        ranges.push_back({left, right - 1});

        vector<bool> ans;
        
        for(vector<int>& query: queries)
        {
            int q_left = query[0];
            int q_right = query[1];

            for(auto [left, right]: ranges)
            {
                // [q_left, q_right] is fully contained in [left, right]
                if(left <= q_left && q_right <= right)
                {
                    ans.push_back(true);
                    break;
                }
                // only q_left is contained in [left, right] 
                // but q_right is outside this range
                else if(q_left <= right)
                {
                    ans.push_back(false);
                    break;
                }
            }
        }

        return ans;
    }
};