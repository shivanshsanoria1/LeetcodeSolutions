class Solution {
private:
    int solve(vector<int>& nums, vector<bool>& isTaken, int prevIdx){
        int n=nums.size();
        if(count(isTaken.begin(), isTaken.end(), true) == n)
            return 1;

        int res = 0;
        for(int i=0; i<n; i++)
        {
            if(isTaken[i])
                continue;

            if(prevIdx != -1)
            {
                double sq = sqrt(nums[prevIdx] + nums[i]);
                if(floor(sq) != ceil(sq))
                    continue;
            }

            isTaken[i] = true;
            res += solve(nums, isTaken, i);
            isTaken[i] = false;
        }

        return res;
    }

    int factorial(int num){
        if(num == 0)
            return 1;
        
        int fact = 1;
        while(num > 1)
        {
            fact *= num;
            num--;
        }

        return fact;
    }

public:
    // T.C.=O(n^n), S.C.=O(n)
    int numSquarefulPerms(vector<int>& nums) {
        int n=nums.size();
        vector<bool> isTaken(n, false);
        int ans = solve(nums, isTaken, -1);

        // num -> freq
        unordered_map<int, int> mp;
        for(int num: nums)
            mp[num]++;
        
        for(auto [num, freq]: mp)
            ans /= factorial(freq);

        return ans;
    }
};