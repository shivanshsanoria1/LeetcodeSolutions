class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size(), min=INT_MAX, left, right, temp;
        bool flag=false;
        if(n < 2) // no next greater sequence possible
            return;
        for(int i=n-1; i>0; i--)
        {
            if(nums[i-1] < nums[i]) // find an element whose immediate left element is smaller
            {
                left=i-1; // immediate left of current element
                right=n-1; // last element
                while(right > i) // search the right subarray to find an element (with least weight possible) 
                {                // larger than left element
                    if(nums[right] > nums[left])
                        break;
                    right--;
                }
                temp=nums[right];
                nums[right]=nums[left];
                nums[left]=temp;
                flag=true;
                break;
            }
        }
        if(flag==false) // sequence is in descending order
            sort(nums.begin(),nums.end());
        else // sort the subarray after the left index
            sort(nums.begin()+left+1,nums.end());
    }
};