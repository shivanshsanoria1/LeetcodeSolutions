class Solution {
public:
    int returnToBoundaryCount(vector<int>& nums) {
        int sum = 0;
        int count = 0;
        for(int num: nums)
        {
            sum += num;
            if(sum == 0)
                count++;
        }
        return count;
    }
};