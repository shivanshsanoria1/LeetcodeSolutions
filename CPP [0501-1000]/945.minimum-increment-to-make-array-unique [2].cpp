class Solution {
public:
    // T.C.=O(n + m), S.C.=O(n + m)
    // m: max-val in nums[]
    int minIncrementForUnique(vector<int>& nums) {
        int n=nums.size();
        int maxVal = *max_element(nums.begin(), nums.end());

        vector<int> freq(maxVal + n, 0);
        
        for(int num: nums)
            freq[num]++;

        int carry = 0;
        int moves = 0;
        for(int i=0; i<freq.size(); i++)
        {
            freq[i] += carry;

            if(freq[i] > 1)
            {
                carry = freq[i] - 1;
                freq[i] = 1;
                moves += carry;
            }
            else
                carry = 0;
        }

        return moves;
    }
};