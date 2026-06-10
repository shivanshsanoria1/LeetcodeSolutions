class Solution {
public:
    int getSteps(int x){
        int count = 0;
        while(x != 1)
        {
            if(x % 2 == 0)
                x /= 2;
            else
                x = 3*x + 1;
            count++;
        }
        return count;
    }

    int getKth(int lo, int hi, int k) { // Iterative
        vector<pair<int, int>> ans; // {steps, num}
        for(int i=lo; i<=hi; i++)
            ans.push_back({getSteps(i), i});
        sort(ans.begin(), ans.end());
        return ans[k-1].second;
    }
};