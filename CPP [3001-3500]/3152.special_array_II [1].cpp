class Solution {
public:
    // T.C.=O(n), S.C.=O(n)
    // 2-pointer
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        int left = 0, right = 0;
        vector<int> groupIds(n, -1);
        int groupId = 1;

        while(right < n)
        {
            // 'right' is the bad index which has broken our streak :(
            // subarray in range [left, right-1] is valid :)
            if(right - 1 >= 0 && nums[right - 1] % 2 == nums[right] % 2)
            {
                left = right;
                groupId++;
            }

            groupIds[right] = groupId;

            right++;
        }

        vector<bool> ans;

        for(vector<int>& query: queries)
        {
            int q_left = query[0];
            int q_right = query[1];
            // subarray in range [q_left, q_right] is valid 
            // if q_left and q_right belong to the same group
            ans.push_back(groupIds[q_left] == groupIds[q_right]);
        }

        return ans;
    }
};