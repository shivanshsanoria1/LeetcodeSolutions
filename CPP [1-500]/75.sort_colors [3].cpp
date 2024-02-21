class Solution {
public:
    void sortColors(vector<int>& nums) { // T.C=O(n) , S.C=O(1), 1 pass
        int n=nums.size(), left=0, right=n-1;
        for(int i=0; i<=right; i++)
        {
            if(nums[i]==0) // here left and i both are incremented simultaneously
            {
                swap_numbers(&nums[i],&nums[left]);
                left++;
            }
            else if(nums[i]==2) // here right is decremented and i remains in the same place
            {
                swap_numbers(&nums[i],&nums[right]);
                right--;
                i--;
            }
        }
    }
    
     void swap_numbers(int *a,int *b)
        {
            int temp;
            temp=*a;
            *a=*b;
            *b=temp;
        }
};