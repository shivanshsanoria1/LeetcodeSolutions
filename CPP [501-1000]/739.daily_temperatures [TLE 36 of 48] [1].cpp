class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) { // T.C.=O(n^2), S.C.=O(1)
        int n=temperatures.size();
        vector<int> ans(n, 0);
        for(int i=0; i<n-1; i++)
            for(int j=i+1; j<n; j++)
                if(temperatures[j] > temperatures[i])
                {
                    ans[i] = j - i;
                    break;
                }
        return ans;
    }
};