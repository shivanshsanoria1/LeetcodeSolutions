class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums, int x) { // T.C.=O(n*logn), S.C.=O(n)
        if(x == 0)
            return 0;

        set<int> s;
        int ans = INT_MAX;
        for(int i=0; i<nums.size(); i++)
        {
            if(i - x >= 0)
                s.insert(nums[i-x]);
                
            // iterator to the first num in set which is >= nums[i]
            auto itr = s.lower_bound(nums[i]);
            // iterator exist in set
            if(itr != s.end()) 
                ans = min(ans, *itr - nums[i]);
            // check for the num just smaller than the num at iterator
            if(itr != s.begin())
            {
                itr--;
                ans = min(ans, abs(nums[i] - *itr));
            }

            if(ans == 0) // 0 is the min possible
                break;
        }
        return ans;
    }
};