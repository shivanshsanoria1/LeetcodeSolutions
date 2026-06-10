class Solution {
public:
    int countQuadruplets(vector<int>& nums) { // T.C.=O(n^3), S.C.=O(n)
        int n=nums.size();
        int count = 0;
        unordered_map<int, int> mp;
        for(int i=n-1; i>=2; i--)
        {
            for(int j=i-1; j>=1; j--)
                for(int k=j-1; k>=0; k--)
                    count += mp[nums[i] + nums[j] + nums[k]];
            mp[nums[i]]++;
        }
        return count;
    }
};