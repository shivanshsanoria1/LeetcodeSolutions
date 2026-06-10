class Solution {
public:
    // T.C.=O(n), S.C.=O(n)
    bool canSortArray(vector<int>& nums) {
        int n = nums.size();
        // {max, min} elements of the group
        vector<pair<int, int>> groups;
        // place the 0th element in a group
        groups.push_back({nums[0], nums[0]});

        for(int i=1; i<n; i++)
        {
            auto [prevMax, prevMin] = groups.back();
            // curr-element is a part of the prev-group
            if(__builtin_popcount(prevMax) == __builtin_popcount(nums[i]))
            {
                // update the max and min values of the prev-group
                groups.back().first = max(prevMax, nums[i]);
                groups.back().second = min(prevMin, nums[i]);
            }
            // curr-element is part of a new group
            else
                groups.push_back({nums[i], nums[i]});
        }

        for(int i=1; i<groups.size(); i++)
        {
            int prevMax = groups[i-1].first;
            int currMin = groups[i].second;

            if(prevMax > currMin)
                return false;
        }

        return true;
    }
};

/*
# basic idea is to split the array into 'groups'
# all elements in a group have the same num of set-bits
# in a group any 2 adjacent elements can be swapped, 
  thus all elements in the group can be sorted (similar Bubble-sort)
# the entire array can be sorted if: 
  the max-element in prev-group < min-element of the curr-group
# to achieve this we just need to maintain 
  the max and min values in each group
*/