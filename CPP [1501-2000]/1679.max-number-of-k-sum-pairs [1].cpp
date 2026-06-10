class Solution {
public:
    int maxOperations(vector<int>& nums, int k) { // T.C.=O(n*logn), S.C.=O(1)
        sort(nums.begin(), nums.end());
        int count = 0;
        int left = 0, right = nums.size()-1;
        while(left < right)
        {
            if(nums[left] + nums[right] < k)
                left++;
            else if(nums[left] + nums[right] > k)
                right--;
            else // nums[left] + nums[right] == k
            {
                count++;
                left++;
                right--;
            }
        }
        return count;
    }
};