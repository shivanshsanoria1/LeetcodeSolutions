class Solution {
public:
    void reverse_array(vector<int>& nums, int left, int right)
    {
        while(left < right)
        {
            int temp= nums[left];
            nums[left]= nums[right];
            nums[right]= temp;
            left++;
            right--;
        }
    }

    void rotate(vector<int>& nums, int k) { //S.C.=O(1)
        int n=nums.size();
        k=k%n; //to reduce k in the range(0,n-1)
        reverse_array(nums,0,n-1); //reverse all the elements
        reverse_array(nums,0,k-1); //reverse the first k elements
        reverse_array(nums,k,n-1); //reverse the remaining (n-k) elements
    }
};