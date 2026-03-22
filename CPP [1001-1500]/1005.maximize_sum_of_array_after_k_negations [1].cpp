class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) { // T.C.=O(n*logn), S.C.=O(1)
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int sum = 0;
        int i=0;
        // flip as many -ive nums as possible
        while(k > 0 && i < n && nums[i] < 0)
        {
            sum += abs(nums[i]);
            i++;
            k--;
        }
        // leftover even flips have no effect
        // leftover odd flips is equivalent to just 1 flip
        if(k % 2 == 1)
        {
            int maxNeg = (i-1 >= 0) ? nums[i-1] : -101;
            int minPos = (i < n) ? nums[i] : 101;
            // max -ive exists and is smaller than min +ive
            if(maxNeg != -101 && abs(maxNeg) < minPos) // CASE 1
            {
                sum += 2*maxNeg; // remove the min -ive from the sum 2 times
            }
            // min +ive exists and is smaller or equal than max -ive
            else if(minPos != 101 && abs(maxNeg) >= minPos) // CASE 2
            {
                sum -= minPos; // remove the min +ive from sum
                i++;
            }
        }
        for(; i<n; i++) // add the leftover elements to sum
            sum += nums[i];
        return sum;
    }
};
/*
CASE 1: [-3,-2,-1,10,20]; k=10 
    -> sum = 3+2+1 = 6; k=7; maxNeg = -1, minPos = 10 
    -> sum = 6 + 2*(-1) = 4 
    -> sum = 4+10+20 = 34 (ans)
CASE 2: [-30,-20,-10,1,2]; k=10 
    -> sum = 30+20+10 = 60; k=7; maxNeg = -10, minPos = 1 
    -> sum = 60 - (1) = 59  
    -> sum = 59+2 = 61 (ans)
*/