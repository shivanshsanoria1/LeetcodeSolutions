class Solution {
public:
    // T.C.=O(n^2), S.C.=O(1)
    int countHillValley(vector<int>& nums) {
        int n = nums.size();
        int count = 0;

        for(int i=1; i<n-1; i++)
        {
            // same hill or valley for i as we found for (i-1) so we skip i
            if(nums[i] == nums[i-1]) 
                continue;

            // decrement left until an unequal element is found
            int left = i-1;
            for(; left>=0; left--)
                if(nums[left] != nums[i])
                    break;
            
            // left neighbour not found
            if(left == -1)
                continue;
            
            // increment right until an unequal element is found
            int right = i+1;
            for(; right<n; right++)
                if(nums[right] != nums[i])
                    break;
            
            // right neighbour not found
            if(right == n)
                continue;
            
            // hill or valley formed by i
            if((nums[left] < nums[i] && nums[i] > nums[right]) || nums[left] > nums[i] && nums[i] < nums[right])
                count++;
        }

        return count;
    }
};