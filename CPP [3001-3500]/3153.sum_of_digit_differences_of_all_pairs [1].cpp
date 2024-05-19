class Solution {
public:
    // T.C.=O(10*n), S.C.=O(10)
    long long sumDigitDifferences(vector<int>& nums) {
        int n=nums.size();
        // length of each num in nums[]
        int numLen = to_string(nums[0]).length();
        long long int count = 0;
        
        for(int i=0; i<numLen; i++)
        {
            vector<int> freq(10, 0);
            
            // count the freq of the ith bit of each num
            for(int num: nums)
                freq[to_string(num)[i] - '0']++;

            // each digit j can be paired with all the non-j digits
            for(int j=0; j<=9; j++)
                count += freq[j]*(n - freq[j]);
        }

        // count is divided by 2 since each pair is counted twice, ie,  
        // pairs (a,b) and (b,a) are counted twice instead of once
        return count/2;
    }
};