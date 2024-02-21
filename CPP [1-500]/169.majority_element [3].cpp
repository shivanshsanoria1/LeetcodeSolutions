class Solution {
public:
    // T.C.=O(n), S.C.=O(1), MOORE'S VOTING algo.
    int majorityElement(vector<int>& nums) { 
        int count = 1;
        // assume 1st element as majority element
        int majority = nums[0]; 
        for(int num: nums)
        {
            // curr element is majority element
            if(num == majority) 
                count++;
            else
                count--;
            // set curr element as majority element
            if(count == 0)
            {
                majority = num;
                count++;
            }
        }
        return majority;
    }
};