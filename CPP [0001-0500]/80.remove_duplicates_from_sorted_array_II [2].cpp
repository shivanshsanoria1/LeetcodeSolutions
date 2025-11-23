class Solution {
public:
    // shifts array elements by 1 position to the left from index [start, end)
    // element at index 'start' is lost
    void shiftArray(vector<int>& nums, int start, int end){
        for(int i=start; i<end; i++)
            nums[i] = nums[i+1];
    }

    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        int left = 0, right = 1;
        int count = 0;
        while(right < n-count)
        {
            if(nums[left] == nums[right])
            {
                if(right > left + 1)
                {
                    count++;
                    shiftArray(nums, right, n-count);
                }
                else
                    right++;
            }
            else
            {
                left = right;
                right++;
            }
        }
        return n-count;
    }
};