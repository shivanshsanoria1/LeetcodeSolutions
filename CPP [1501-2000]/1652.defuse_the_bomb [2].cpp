class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) { // T.C.=O(n), S.C.=O(1)
        int n = code.size();
        vector<int> ans(n, 0);
        if(k == 0)
            return ans;
        if(k > 0)
        {
            int sum = 0;
            for(int i=1; i<=k; i++)
                sum += code[i];
            ans[0] = sum;
            int start = 2, end = (k+1) % n;
            while(start <= n)
            {
                sum += code[end] - code[start - 1];
                ans[start - 1] = sum;
                start++;
                end = (end + 1) % n;
            }
        }
        else
        {
            k *= -1; // make k +ive
            int sum = 0;
            for(int i=n-1; i>=n-k; i--)
                sum += code[i];
            ans[0] = sum;
            int start = 0, end = n-k+1;
            while(start < n-1)
            {
                sum += code[start] - code[(n + end - 1) % n];
                ans[start + 1] = sum;
                start++;
                end = (end + 1) % n;
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