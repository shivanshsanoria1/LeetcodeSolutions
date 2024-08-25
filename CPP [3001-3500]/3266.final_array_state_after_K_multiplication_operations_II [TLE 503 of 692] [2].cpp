class Solution {
private:
    #define MOD int(1e9 + 7)
    typedef pair<int, int> PII;

public:
    // T.C.=O(n*log(n) + k*log(n)), S.C.=O(n)
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        // min-heap; {nums[i], i}
        priority_queue<PII, vector<PII>, greater<PII>> pq;
        for(int i=0; i<nums.size(); i++)
            pq.push({nums[i], i});
        
        while(k--)
        {
            auto [curr, idx] = pq.top();
            pq.pop();

            pq.push({((long long int)curr * multiplier) % MOD, idx});
        }

        while(!pq.empty())
        {
            auto [curr, idx] = pq.top();
            pq.pop();

            nums[idx] = curr;
        }

        return nums;
    }
};