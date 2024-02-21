class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, int> mp1; // num -> freq
        unordered_map<int, pair<int, int>> mp2; // num -> {first idx, last idx}
        int degree = 0; // max freq
        int n=nums.size();
        for(int i=0; i<n; i++)
        {
            mp1[nums[i]]++;
            degree = max(degree, mp1[nums[i]]);

            if(mp2.find(nums[i]) == mp2.end()) // not found in map
                mp2[nums[i]] = {i, i}; // update the first and last index
            else
                mp2[nums[i]].second = i; // update only the last index
        }

        int ans = n;
        for(auto it: mp2)
        {
            int num = it.first;
            if(mp1[num] != degree) // num does not have the max freq
                continue;
            int startIdx = it.second.first;
            int endIdx = it.second.second;
            ans = min(ans, endIdx - startIdx + 1);
        }
        return ans;
    }
};