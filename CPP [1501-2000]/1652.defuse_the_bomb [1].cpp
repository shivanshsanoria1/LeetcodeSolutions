class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) { // T.C.=O(n*k), S.C.=O(1)
        int n = code.size();
        vector<int> ans(n, 0);
        if(k == 0)
            return ans;
        if(k > 0)
        {
            for(int i=0; i<n; i++)
            {
                int sum = 0;
                int k2 = k;
                // find the sum of next k elements
                for(int j=(i+1) % n; k2 > 0; j = (j+1) % n)
                {
                    sum += code[j];
                    k2--;
                }
                ans[i] = sum;
            }
        }
        else
        {
            for(int i=0; i<n; i++)
            {
                int sum = 0;
                int k2 = k;
                // find the sum of prev k elements
                for(int j = (n+i-1) % n; k2 < 0; j = (n+j-1) % n)
                {
                    sum += code[j];
                    k2++;
                }
                ans[i] = sum;
            }
        }
        return ans;
    }
};
/*
# In Maths: A mod N = (A +- N) mod N
# for moving in forward circular motion i = (i+1) % n
# for moving in backard circular motion i = (n+i-1) % n
*/