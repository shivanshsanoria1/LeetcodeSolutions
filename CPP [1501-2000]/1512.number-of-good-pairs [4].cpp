class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) { // T.C.=O(n), S.C.=O(n), single pass
        vector<int> freq(101, 0);
        int count = 0;
        for(int num: nums)
        {
            count += freq[num]; // add the prev freq of curr element to ans
            freq[num]++; // update the freq of curr element
        }
        return count;
    }
};