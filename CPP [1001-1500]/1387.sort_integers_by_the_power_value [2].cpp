class Solution {
public:
    int getSteps(int x){
        if(x == 1)
            return 0;
        int steps = (x % 2 == 0) ? getSteps(x/2) : getSteps(3*x + 1);
        return 1 + steps;
    }

    int getKth(int lo, int hi, int k) { // Recursion
        vector<pair<int, int>> ans; // {steps, num}
        for(int i=lo; i<=hi; i++)
            ans.push_back({getSteps(i), i});
        sort(ans.begin(), ans.end());
        return ans[k-1].second;
    }
};