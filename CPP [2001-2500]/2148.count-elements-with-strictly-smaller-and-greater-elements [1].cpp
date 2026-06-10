class Solution {
public:
    int countElements(vector<int>& nums) { //just remove all the occurences of max and min element
        int n=nums.size();
        int min_num=INT_MAX, max_num=INT_MIN;
        int min_count=1, max_count=1;
        for(int i=0; i<n; i++)
        {
            if(nums[i] > max_num) //new max num found
            {
                max_num=nums[i]; //update max num
                max_count=1; //reset max count
            }
            else if(nums[i] == max_num) //another max num found
                max_count++; //increment max count
            
            if(nums[i] < min_num) //new min num found
            {
                min_num=nums[i]; //update min num
                min_count=1; //reset min count
            }
            else if(nums[i] == min_num) //another min num found
                min_count++; //increment min count
        }
        if(min_num == max_num) //array has only 1 distinct element
            return 0;
        return n-max_count-min_count;
    }
};