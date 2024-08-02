class Solution {
public:
    // T.C.=O(n), S.C.=O(1)
    // Sliding-window (fixed length)
    int minSwaps(vector<int>& nums) {
        int total_1s = count(nums.begin(), nums.end(), 1);
        int n=nums.size();

        int left = 0, right = total_1s % n;
        int count_0s = count(nums.begin(), nums.begin() + right, 0);
        int minSwaps = count_0s;

        while(left < n)
        {
            if(nums[left] == 0)
                count_0s--;
            if(nums[right] == 0)
                count_0s++;
            
            minSwaps = min(minSwaps, count_0s);

            left++;
            right = (right + 1) % n;
        }

        return minSwaps;
    }
};
/*
# to get rid of circular condition make another vector 
  nums2[] which is just nums[] appended to itself,
# we actually don't need to create nums2[], 
  we can just return the 'right' pointer to index 0 
  after the last index by reducing it mod n
# let 'total_1s' be the total num of 1's found in nums[]
# find the min num of 0's for each window of size 'total_1s' 
  in nums2[], this would give the min-swaps required
*/