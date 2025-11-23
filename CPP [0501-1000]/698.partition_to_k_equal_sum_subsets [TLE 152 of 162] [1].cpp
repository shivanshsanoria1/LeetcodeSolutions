class Solution {
public:
    bool solve(vector<int>& nums, int subsetSum, vector<int>& subSums, int i){
        if(i == nums.size())
            return true;
        for(int j=0; j<subSums.size(); j++)
        {
            if(subSums[j] + nums[i] > subsetSum)
                continue;
            subSums[j] += nums[i];
            if(solve(nums, subsetSum, subSums, i+1))
                return true;
            subSums[j] -= nums[i];
        }
        return false;
    }

    bool canPartitionKSubsets(vector<int>& nums, int k) { // T.C.=(k^n)
        int sum = 0;
        for(int num: nums)
            sum += num;
        if(sum % k != 0)
            return false;
        int subsetSum = sum/k;
        vector<int> subSums(k, 0); // to store each subset sum 
        // sort the original array in decreasing order (to reduce the number of recursive calls)
        sort(nums.begin(), nums.end(), greater<int>());
        return solve(nums, subsetSum, subSums, 0);
    }
};