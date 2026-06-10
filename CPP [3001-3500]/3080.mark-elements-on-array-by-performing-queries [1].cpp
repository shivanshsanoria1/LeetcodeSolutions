class Solution {
private:
    typedef pair<int, int> PII;

public:
    // T.C.=O(n*log(n)), S.C.=O(n)
    vector<long long> unmarkedSumArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        vector<bool> isMarked(n, false);
        vector<long long int> ans;

        long long int sum = 0;
        // min-heap; {num, idx}
        priority_queue<PII, vector<PII>, greater<PII>> pq;
        for(int i=0; i<n; i++)
        {
            sum += nums[i];
            pq.push({nums[i], i});
        }

        for(vector<int>& query: queries)
        {
            int i = query[0];
            int k = query[1];

            if(!isMarked[i])
            {
                isMarked[i] = true;
                sum -= nums[i];
            }

            while(!pq.empty() && k > 0)
            {
                auto [num, idx] = pq.top();
                pq.pop();

                if(isMarked[idx])
                    continue;
                
                isMarked[idx] = true;
                sum -= nums[idx];
                k--;
            }

            ans.push_back(sum);
        }

        return ans;
    }
};