class Solution {
public:
    // T.C.=O(n), S.C.=O(1)
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        // no next greater sequence possible
        if(n < 2) 
            return;

        int left = -1, right = -1;
        bool flag = false;

        for(left = n-2; left >= 0; left--)
            if(nums[left] < nums[left + 1]) 
            {
                // find the rightmost element whcih is > nums[left] 
                // in the subarray in range [i+1, n-1]
                for(right = n-1; right > left; right--)
                    if(nums[right] > nums[left])
                        break;
                
                swap(nums[left], nums[right]);
                flag = true;
                break;
            }

        // reverse the subarray after the left index
        if(flag) 
            reverse(nums.begin() + left + 1, nums.end());
        // sequence is in descending order so for the next permutation, 
        // reverse it to get it in increasing order
        else 
            reverse(nums.begin(), nums.end());
    }
};