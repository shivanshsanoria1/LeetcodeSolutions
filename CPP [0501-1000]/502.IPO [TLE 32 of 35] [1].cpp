class Solution {
public:
    // T.C.=O(n*k), S.C.=O(n)
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n=profits.size();
        vector<bool> used(n, false);

        while(k--)
        {
            int maxProfit = -1;
            int idx = -1;

            for(int i=0; i<n; i++)
                if(!used[i] && capital[i] <= w && profits[i] > maxProfit)
                {
                    maxProfit = profits[i];
                    idx = i;
                }

            if(idx == -1)
                break;
                
            used[idx] = true;
            w += profits[idx];
        }

        return w;
    }
};