class Solution {
public:
    // T.C.=O(n), S.C.=O(1)
    int maximizeExpressionOfThree(vector<int>& nums) {
        int maxVal1 = -101, maxVal2 = -101;
        int minVal = 101;

        for(int num: nums){
            if(num >= maxVal1){
                maxVal2 = maxVal1;
                maxVal1 = num;
            }else if(num > maxVal2)
                maxVal2 = num;
            
            minVal = min(minVal, num);
        }

        return maxVal1 + maxVal2 - minVal;
    }
};