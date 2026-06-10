class Solution {
private:
    void solve(vector<int>& nums, int i, vector<int>& subset, int& maxBitwiseOR, int& count){
        if(i == nums.size())
        {
            int bitwiseOR = 0;
            for(int num: subset)
                bitwiseOR |= num;

            if(bitwiseOR > maxBitwiseOR)
            {
                maxBitwiseOR = bitwiseOR;
                count = 1;
            }
            else if(bitwiseOR == maxBitwiseOR)
                count++;

            return;
        }
        
        // exclude
        solve(nums, i+1, subset, maxBitwiseOR, count);

        // include
        subset.push_back(nums[i]);
        solve(nums, i+1, subset, maxBitwiseOR, count);
        subset.pop_back();
    }

public:
    // T.C.=O(n*2^n), S.C.=O(n)
    // Backtracking
    int countMaxOrSubsets(vector<int>& nums) {
        vector<int> subset;
        int maxBitwiseOR = 0;
        int count = 0;

        solve(nums, 0, subset, maxBitwiseOR, count);

        return count;
    }
};