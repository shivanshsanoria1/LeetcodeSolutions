class Solution {
private:
    typedef pair<int, int> PII;
    #define MOD int(1e9 + 7)

public:
    // T.C.=O((n^2)*log(n)), S.C.=O(n)
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        // min-heap; {sum of subarray ending at index, index}
        priority_queue<PII, vector<PII>, greater<PII>> pq;

        for(int i=0; i<n; i++)
            pq.push({nums[i], i});
        
        int sum = 0;
        for(int i=1; i<=right; i++)
        {
            auto [subSum, idx] = pq.top();
            pq.pop();

            if(i >= left)
                sum = (sum + subSum) % MOD;

            if(++idx < n)
                pq.push({subSum + nums[idx], idx});
        }

        return sum;
    }
};