class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int n=nums.size(), c=0;
        for(int i=1; i<n-1; i++) //skip first and last index
        {
            if(nums[i] == nums[i-1]) //same hill or valley for i as we did for (i-1) so we skip i
                continue;
            int left=i-1, right=i+1;
            while(left >= 0) //decrement left until an unequal element is found
            {
                if(nums[left] != nums[i])
                    break;
                left--;
            }
            if(left < 0) //left neighbour not found
                continue;
            while(right < n) //increment right until an unequal element is found
            {
                if(nums[right] != nums[i])
                    break;
                right++;
            }
            if(right >= n) //right neighbour not found
                continue;
            if((nums[i]>nums[left] && nums[i]>nums[right]) || (nums[i]<nums[left] && nums[i]<nums[right])) //hill or valley found
                c++;
        }
        return c;
    }
};