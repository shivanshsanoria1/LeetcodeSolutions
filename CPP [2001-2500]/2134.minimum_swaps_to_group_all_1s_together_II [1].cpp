class Solution {
public:
    // T.C.=O(n), S.C.=O(n)
    // Sliding-window (fixed length)
    int minSwaps(vector<int>& nums) {
        int total_1s = count(nums.begin(), nums.end(), 1);
        int n=nums.size();

        vector<int> nums2(2*n);
        for(int i=0; i<n; i++)
        {
            nums2[i] = nums[i];
            nums2[i + n] = nums[i];
        }

        int left = 0, right = total_1s;
        int count_0s = count(nums.begin(), nums.begin() + total_1s, 0);
        int minSwaps = count_0s;
        
        while(right < 2*n)
        {
            if(nums2[left] == 0)
                count_0s--;
            if(nums2[right] == 0)
                count_0s++;
            
            minSwaps = min(minSwaps, count_0s);

            left++;
            right++;
        }

        return minSwaps;
    }
};
/*
# to get rid of circular condition make another vector 
  nums2[] which is just nums[] appended to itself
# let 'total_1s' be the total num of 1's found in nums[]
# find the min num of 0's for each window of size 'total_1s' 
  in nums2[], this would give the min-swaps required
*/