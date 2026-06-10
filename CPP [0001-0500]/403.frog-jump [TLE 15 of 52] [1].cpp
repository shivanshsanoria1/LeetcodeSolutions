class Solution {
public:
    bool solve(vector<int>& stones, unordered_map<int, int>& mp, int i, int jump){
        if(i == stones.size() - 1)
            return true;
        if(jump <= 0)
            return false;
        if(mp.find(stones[i] + jump) == mp.end())
            return false;
        int idx = mp[stones[i] + jump];
        bool j1 = solve(stones, mp, idx, jump - 1);
        bool j2 = solve(stones, mp, idx, jump);
        bool j3 = solve(stones, mp, idx, jump + 1);
        return j1 || j2 || j3;
    }

    bool canCross(vector<int>& stones) { // Recursion, T.C.=O(3^n)
        unordered_map<int, int> mp; // stone -> index
        for(int i=0; i<stones.size(); i++)
            mp[stones[i]] = i;
        return solve(stones, mp, 0, 1);
    }
};