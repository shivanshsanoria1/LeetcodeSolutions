class Solution {
public:
    // T.C.=O(n), S.C.=O(1)
    // Sliding-Window
    long long getDescentPeriods(vector<int>& prices) {
        int left = 0, right = 0;
        long long int count = 0;

        while(right < prices.size())
        {
            while(prices[left] - prices[right] != right - left)
                left++;

            count += right - left + 1;

            right++;
        }
        
        
        return count;
    }
};