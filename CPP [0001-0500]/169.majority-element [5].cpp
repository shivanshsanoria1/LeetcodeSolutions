class Solution {
public:
    // T.C.=O(n), S.C.=O(1)
    // Boyer-Moore Majority Voting algo.
    int majorityElement(vector<int>& nums) { 
        int majority = INT_MIN; 
        int freq = 0;

        for(int num: nums)
        {
            if(freq == 0)
                majority = num;

            if(num == majority) 
                freq++;
            else
                freq--;
        }

        return majority;
    }
};