class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int n=nums.size();
        set<pair<int,int>> s;
        for(int i=1; i<n-1; i++) //skip first and last index
        {
            int left=i-1, right=i+1;
            while(left >= 0) //decrement left until an unequal element is found
            {
                if(nums[left] != nums[i])
                    break;
                left--;
            }
            while(right < n) //increment right until an unequal element is found
            {
                if(nums[right] != nums[i])
                    break;
                right++;
            }
            if(left < 0 || right >= n) //left or right neighbour is not found
                continue;
            if((nums[i]>nums[left] && nums[i]>nums[right]) || (nums[i]<nums[left] && nums[i]<nums[right])) //hill or valley found
                s.insert({left,right});
        }
        return s.size();
    }
};