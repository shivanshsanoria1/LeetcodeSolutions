class Solution {
public:
    // T.C.=O(n), S.C.=O(1)
    int minOperations(vector<int>& nums) {
        for(int i=1; i<nums.size(); i++)
            if(nums[i-1] != nums[i])
                return 1;

        return 0;
    }
};

/*
# it is always optimal to take the AND of all elements 
  in the array instead of taking the same for some subarrays 
  to minmize the num of operations
# therefore the solution is simply 1 operation when 
  all the elements are not the same and 0 when they are
*/