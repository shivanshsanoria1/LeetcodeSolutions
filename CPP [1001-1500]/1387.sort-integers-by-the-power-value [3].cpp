class Solution {
public:
    int getSteps(unordered_map<int, int>& mp, int x){
        if(x == 1)
            return 0;
        if(mp.find(x) != mp.end()) // x found in map
            return mp[x];
        int steps = (x % 2 == 0) ? getSteps(mp, x/2) : getSteps(mp, 3*x + 1);
        mp[x] = 1 + steps; // store the steps for curr x in map
        return mp[x];
    }

    int getKth(int lo, int hi, int k) { // Memoization
        vector<pair<int, int>> ans; // {steps, num}
        unordered_map<int, int> mp; // num -> steps
        for(int i=lo; i<=hi; i++)
            ans.push_back({getSteps(mp, i), i});
        sort(ans.begin(), ans.end());
        return ans[k-1].second;
    }
};