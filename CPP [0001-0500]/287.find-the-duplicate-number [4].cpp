class Solution {
public:
    // T.C.=O(n), S.C.=O(1)
    int findDuplicate(vector<int>& nums) { 
        int slow = nums[0];
        int fast = nums[0];

        // to detect the loop
        while(true) 
        {
            // move 'slow' by 1 step
            slow = nums[slow]; 
            // move 'fast' by 2 step
            fast = nums[nums[fast]];

            if(slow == fast)
                break;
        }
        
        // find the starting of the loop
        int slow2 = nums[0];
        while(slow != slow2) 
        {
            // move 'slow' and 'slow2 by 1 step
            slow = nums[slow]; 
            slow2 = nums[slow2];
        }
        
        return slow;
    }
};
// similar to Floyd's cycle detection algo.