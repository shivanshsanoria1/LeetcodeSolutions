class Solution {
private:
    #define MOD int(1e9 + 7)

public:
    // T.C.=O(n), S.C.=O(n)
    int specialTriplets(vector<int>& nums) {
        int n = nums.size();

        // num -> freq
        unordered_map<int, int> mp;
        vector<int> leftCounts(n, 0);
        for(int j=0; j<n; j++)
        {
            if(mp.find(nums[j]*2) != mp.end())
                leftCounts[j] = mp[nums[j]*2];

            mp[nums[j]]++;
        }

        mp.clear();
        vector<int> rightCounts(n, 0);
        for(int j=n-1; j>=0; j--)
        {
            if(mp.find(nums[j]*2) != mp.end())
                rightCounts[j] = mp[nums[j]*2];

            mp[nums[j]]++;
        }

        int count = 0;
        for(int j=0; j<n; j++)
        {
            int prod = ((long long int)leftCounts[j] * rightCounts[j]) % MOD;
            count = (count + prod) % MOD;
        }
        
        return count;
    }
};