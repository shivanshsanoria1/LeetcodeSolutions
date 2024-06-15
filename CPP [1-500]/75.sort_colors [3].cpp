class Solution {
public:
    // T.C=O(n), S.C=O(1)
    // 1 pass, DNF algo (Dutch National Flag)
    void sortColors(vector<int>& nums) { 
        int left = 0, right = nums.size()-1;
        int i = 0;

        while(i <= right)
        {
            if(nums[i] == 0)
            {
                swap(nums[i], nums[left]);
                left++;
            }
            else if(nums[i] == 2)
            {
                swap(nums[i], nums[right]);
                right--;
                i--;
            }

            i++;
        }
    }
};