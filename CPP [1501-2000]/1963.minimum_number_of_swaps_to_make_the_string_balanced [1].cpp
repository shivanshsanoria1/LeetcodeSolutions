class Solution {
public:
    int minSwaps(string s) { // T.C.=O(n), S.C.=O(1)
        int sum = 0;
        int ans = 0;
        for(char ch: s)
        {
            sum += ch == '[' ? 1 : -1;
            ans = min(ans, sum);
        }
        ans = abs(ans);
        return ans % 2 == 0 ? ans / 2 : (ans + 1) / 2;
    }
};