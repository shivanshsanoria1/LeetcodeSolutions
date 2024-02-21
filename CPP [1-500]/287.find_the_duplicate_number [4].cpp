class Solution {
public:
    int findDuplicate(vector<int>& nums) { // T.C.=O(n), S.C.=O(1)
        int slow = nums[0], fast = nums[0];
        while(true) // to detect the loop
        {
            slow = nums[slow]; // move slow by 1 step
            fast = nums[nums[fast]]; // move fast by 2 step
            if(slow == fast)
                break;
        }
        
        int slow2 = nums[0];
        while(slow != slow2) // to find the starting of the loop
        {
            slow = nums[slow]; // move slow by 1 step
            slow2 = nums[slow2]; // move slow2 by 1 step
        }
        return slow;
    }
};
// similar to Floyd's cycle detection algo.