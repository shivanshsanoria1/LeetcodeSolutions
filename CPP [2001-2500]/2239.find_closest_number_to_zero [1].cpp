class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        int min_dist=INT_MAX, flag=false;
        for(int i=0; i<nums.size(); i++)
        {
            if(abs(nums[i]) < min_dist) //new min distance found
            {
                flag=false; //reset flag
                min_dist=abs(nums[i]); //update min distance
                if(nums[i] > 0) //+ive value found
                    flag=true;
            }
            else if(abs(nums[i]) == min_dist && nums[i] > 0) //+ive value found
                flag=true;
        }
        return flag==true ? min_dist: -min_dist;
    }
};