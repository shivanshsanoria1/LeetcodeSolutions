class Solution {
public:
    bool canBeIncreasing(vector<int>& nums) { // T.C.=O(n^2), S.C.=O(1)
        int n = nums.size();
        for(int i=0; i<n; i++)
        {
            // skip the element at index i (assume there is a hole at index i)
            bool isSorted = true; // assume the array is sorted
            for(int j=1; j<n; j++) // check if the array is sorted
            {
                if(j == i) // curr element does not exist
                    continue;
                if(j-1 == i) // prev element does not exist
                { // 2nd prev element exists and makes the array unsorted
                    if(j-2 >= 0 && nums[j-2] >= nums[j])
                    {
                        isSorted = false;
                        break;
                    }
                }
                else if(nums[j-1] >= nums[j]) // prev element makes the array unsorted
                {
                    isSorted = false;
                    break;
                }
            }
            if(isSorted)
                return true;
        }
        return false;
    }
};