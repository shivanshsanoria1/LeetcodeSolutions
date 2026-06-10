class Solution {
private:
    // a 'group' is just the elements belonging to a valid-subarray
    // find the group-id of each element in nums[]
    vector<int> findGroupIds(vector<int>& nums){
        int n = nums.size();
        int left = 0, right = 1;
        vector<int> groupIds(n, -1);
        int groupId = 1;
        groupIds[0] = groupId;

        while(right < n)
        {
            // 'right' is the bad index which has broken our streak :(
            // subarray in range [left, right-1] is valid :)
            if(nums[right - 1] % 2 == nums[right] % 2)
            {
                left = right;
                groupId++;
            }

            groupIds[right] = groupId;
            right++;
        }

        return groupIds;
    }

public:
    // T.C.=O(n + q), S.C.=O(n)
    // 2-pointer
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> groupIds = findGroupIds(nums);

        vector<bool> ans;
        for(vector<int>& query: queries)
        {
            // subarray in range [q_left, q_right] is valid 
            // if q_left and q_right belong to the same group
            int q_left = query[0], q_right = query[1];
            ans.push_back(groupIds[q_left] == groupIds[q_right]);
        }

        return ans;
    }
};