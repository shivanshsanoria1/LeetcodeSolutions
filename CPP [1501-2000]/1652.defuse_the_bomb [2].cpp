class Solution {
public:
    // T.C.=O(n), S.C.=O(1)
    // Sliding-window (fixed-length)
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> ans(n, 0);

        if(k == 0)
            return ans;
        
        if(k < 0)
            reverse(code.begin(), code.end());

        // sum of elements of the window [0, k-1]
        int sum = accumulate(code.begin(), code.begin() + abs(k), 0);
        int left = 0, right = abs(k);
        while(left < n)
        {
            sum += code[right] - code[left];
            ans[left] = sum;

            left++;
            right = (right + 1) % n;
        }

        if(k < 0)
            reverse(ans.begin(), ans.end());

        return ans;
    }
};