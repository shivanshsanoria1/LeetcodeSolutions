class Solution {
public:
    // T.C.=O(n), S.C.=O(1)
    int maxProductDifference(vector<int>& nums) { 
        int max1 = INT_MIN, max2 = INT_MIN; // 1st and 2nd max num
        int min1 = INT_MAX, min2 = INT_MAX; // 1st and 2nd min num 
        for(int num: nums)
        {
            if(num >= max1) // new max1 found
            {
                max2 = max1; // save max1 in max2
                max1 = num; // update max1
            }
            else if(num > max2) // new max2 found
                max2 = num; // update max2
            
            if(num <= min1) // new min1 found
            {
                min2 = min1; // save min1 in min2
                min1 = num; // update min1
            }
            else if(num < min2) // new min2 found
                min2 = num; // update min2
        }
        return max1*max2 - min1*min2;
    }
};