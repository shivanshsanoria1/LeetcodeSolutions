class Solution {
public:
    int solve(vector<string>& strs, int i, int m, int n){
        if(i >= strs.size()) // index out of bounds
            return 0;
        int m2 = m, n2 = n;
        for(char ch: strs[i])
        {
            if(ch == '0')
                m2--;
            else
                n2--;
        }
        // including string at index i
        int in = (m2 >= 0 && n2 >= 0) ? 1 + solve(strs, i+1, m2, n2) : 0; 
        // excluding string at index i
        int ex = solve(strs, i+1, m, n); 
        return max(in, ex);
    }

    int findMaxForm(vector<string>& strs, int m, int n) { // Recursion, T.C.=O(2^n), S.C.=O(1)
        return solve(strs, 0, m, n);
    }
};