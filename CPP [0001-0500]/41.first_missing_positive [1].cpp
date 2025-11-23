class Solution {
public:
    // T.C.=O(n*logn), S.C.=O(1)
    int firstMissingPositive(vector<int>& nums) { 
        sort(nums.begin(), nums.end());

        int minNum = 1;
        
        for(int num: nums)
        {
            if(num <= 0)
                continue;
            
            if(num > minNum)
                return minNum;
            else if(num == minNum)
                minNum++;
        }
        
        return minNum;
    }
};