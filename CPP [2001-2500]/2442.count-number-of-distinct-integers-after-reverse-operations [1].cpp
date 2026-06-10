class Solution {
public:
    // T.C.=O(n), S.C.=O(n)
    int countDistinctIntegers(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        for(int num: nums)
        {
            int revNum = 0;
            while(num > 0)
            {
                revNum = 10*revNum + num % 10;
                num /= 10;
            }
            s.insert(revNum);
        }
        return s.size();
    }
};