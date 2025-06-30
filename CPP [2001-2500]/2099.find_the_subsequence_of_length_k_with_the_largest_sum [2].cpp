class Solution {
private:
    typedef pair<int, int> PII;

public:
    // T.C.=O(n*log(k) + k*log(k)), S.C.=O(k)
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        // min-heap to maintain the k largest elements
        priority_queue<PII, vector<PII>, greater<PII>> pq;

        for(int i=0; i<nums.size(); i++)
        {
            pq.push({nums[i], i});
            if(pq.size() == k+1)
                pq.pop();
        }

        vector<PII> temp; // {num, idx}
        while(!pq.empty())
        {
            auto [num, i] = pq.top();
            pq.pop();
            temp.push_back({num, i});
        }

        // sort in increasing order of index
        sort(temp.begin(), temp.end(), [](PII &a, PII &b){
            return a.second < b.second;
        });

        vector<int> ans;
        for(int i=0; i<k; i++)
            ans.push_back(temp[i].first);

        return ans;
    }
};