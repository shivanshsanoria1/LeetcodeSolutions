class Solution {
public:
    // T.C.=O(n^2), S.C.=O(1)
    vector<int> dailyTemperatures(vector<int>& temperatures) { 
        int n = temperatures.size();
        vector<int> ans(n, 0);

        for(int i=0; i<n-1; i++)
            for(int j=i+1; j<n; j++)
                if(temperatures[i] < temperatures[j])
                {
                    ans[i] = j - i;
                    break;
                }

        return ans;
    }
};

// similar: [962. maximum-width-ramp]