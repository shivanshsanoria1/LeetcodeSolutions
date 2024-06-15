class Solution {
public:
    // T.C=O(n), S.C=O(n)
    void sortColors(vector<int>& nums) { 
        int n=nums.size();
        int left = 0, right = n-1;
        vector<int> temp(n, 1);

        for(int num: nums)
        {
            if(num == 0)
            {
                temp[left] = 0;
                left++;
            }
            else if(num == 2)
            {
                temp[right] = 2;
                right--;
            }
        }

        for(int i=0; i<n; i++) 
            nums[i] = temp[i];
    }
};