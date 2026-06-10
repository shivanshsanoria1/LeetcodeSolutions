class Solution {
public:
    // T.C.=O(n*logn), S.C.=O(n)
    vector<string> findRelativeRanks(vector<int>& score) {
        // max-heap { score, index }
        priority_queue<pair<int, int>> pq;

        int n=score.size();
        for(int i=0; i<n; i++)
            pq.push({score[i], i});

        vector<string> ans(n, "");
        int pos = 1; // position
        while(!pq.empty())
        {
            auto [score, idx] = pq.top();
            pq.pop();

            if(pos == 1)
                ans[idx] = "Gold Medal";
            else if(pos == 2)
                ans[idx] = "Silver Medal";
            else if(pos == 3)
                ans[idx] = "Bronze Medal";
            else
                ans[idx] = to_string(pos);

            pos++;
        }

        return ans;
    }
};