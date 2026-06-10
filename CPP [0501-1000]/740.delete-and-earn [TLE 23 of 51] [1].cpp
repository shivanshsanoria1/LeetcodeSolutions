class Solution {
private:
    int solve(unordered_map<int, int>& mp, vector<int>& vec, int prevIdx, int i){
        if(i >= vec.size())
            return 0;

        int exclude = solve(mp, vec, prevIdx, i+1);

        bool cond = prevIdx == -1 || vec[i] - vec[prevIdx] > 1;
        int include = cond ? vec[i] * mp[vec[i]] + solve(mp, vec, i, i+1) : 0;

        return max(include, exclude);
    }

public:
    // T.C.=O(2^n)
    // Recursion
    int deleteAndEarn(vector<int>& nums) {
        // num -> freq
        unordered_map<int, int> mp; 
        for(int num: nums)
            mp[num]++;
            
        vector<int> vec;
        for(auto [num, freq]: mp)
            vec.push_back(num);
        sort(vec.begin(), vec.end());

        return solve(mp, vec, -1, 0);
    }
};