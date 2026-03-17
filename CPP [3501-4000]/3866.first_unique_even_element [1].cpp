class Solution {
public:
    // T.C.=O(n + 100), S.C.=O(100)
    int firstUniqueEven(vector<int>& nums) {
        vector<int> freq(101, 0);
        for(int num: nums)
            freq[num]++;
        
        for(int num: nums)
            if(num % 2 == 0 && freq[num] == 1)
                return num;
        
        return -1;
    }
};