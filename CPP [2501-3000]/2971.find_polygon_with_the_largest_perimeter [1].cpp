class Solution {
public:
    // T.C.=O(n*logn), S.C.=O(1)
    long long largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        long long int preSum = 0; // prefix-sum
        long long int peri = -1; // perimeter
        for(int num: nums)
        {
            // polygon possible, since sum of all prev sides > largest side
            if(preSum > num)
                peri = preSum + num;
            // update the prefix sum
            preSum += num;
        }
        return peri;
    }
};