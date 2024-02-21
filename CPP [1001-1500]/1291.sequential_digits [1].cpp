class Solution {
private:
    void solve(int low, int high, vector<int>& ans, int d, int num){
        if(num > high)
            return;
        if(num >= low)
            ans.push_back(num);
        if(d > 9)
            return;
        solve(low, high, ans, d+1, 10*num + d);
    }

public:
    // T.C.=O(), S.C.=O()
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        for(int i=1; i<=9; i++)
            solve(low, high, ans, i, 0);
        sort(ans.begin(), ans.end());
        return ans;
    }
};