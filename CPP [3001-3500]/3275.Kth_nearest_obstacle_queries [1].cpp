class Solution {
public:
    // T.C.=O(n*log(k)), S.C.=O(k)
    vector<int> resultsArray(vector<vector<int>>& queries, int k) {
        // max-heap
        priority_queue<int> pq;
        vector<int> ans;
        for(vector<int>& query: queries)
        {
            int x = query[0], y = query[1];

            pq.push(abs(x) + abs(y));
            if(pq.size() == k+1)
                pq.pop();

            ans.push_back(pq.size() == k ? pq.top() : -1);
        }

        return ans;
    }
};