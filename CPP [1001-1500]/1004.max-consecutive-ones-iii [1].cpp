class Solution {
public:
    // T.C.=O(n), S.C.=O(1)
    // sliding-window
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int left = 0, right = 0;
        int maxWindowSize = 0;

        while(right < n)
        {
            // include the curr 0 in window
            if(nums[right] == 0)
            {
                nums[right] = -1;
                k--;
            }

            // k == -1 indicates that the window has k+1 0's
            // keep on shrinking the window until there are k 0's
            while(k == -1)
            {
                if(nums[left] == -1)
                {
                    nums[left] = 0;
                    k++;
                }
                left++;
            }

            maxWindowSize = max(maxWindowSize, right - left + 1);

            right++;
        }

        return maxWindowSize;
    }
};

/*
# a valid window can have atmost k 0's
# a 0 inside window is marked as -1
*/