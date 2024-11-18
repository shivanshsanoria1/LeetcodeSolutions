class Solution {
public:
    // T.C.=O(n*k), S.C.=O(1)
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> ans(n, 0);

        if(k == 0)
            return ans;

        for(int i=0; i<n; i++)
        {
            int sum = 0;
            int j = k > 0 ? (i+1) % n : (i-1+n) % n;
            int tempK = k > 0 ? k : -k;
            while(tempK--)
            {
                sum += code[j];
                j = k > 0 ? (j+1) % n : (j-1+n) % n;
            }

            ans[i] = sum;
        }

        return ans;
    }
};

/*
# for moving in forward circular motion: i = (i+1) % n
# for moving in backard circular motion: i = (i-1+n) % n
# Mathematically: A mod N = (A +- N) mod N
*/