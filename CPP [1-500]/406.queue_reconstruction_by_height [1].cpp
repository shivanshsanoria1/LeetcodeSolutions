class Solution {
private:
    #define INF INT_MAX
    typedef pair<int, int> PII;

public:
    // T.C.=O(n^2), S.C.=O(n)
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        int n=people.size();
        // ans of size n*2 filled with infinities
        vector<vector<int>> ans(n, vector<int>(2, INF));

        // min-heap; {height, people in front with greater or equal height}
        priority_queue<PII, vector<PII>, greater<PII>> pq;
        for(vector<int>& person: people)
            pq.push({person[0], person[1]});
        
        while(!pq.empty())
        {
            auto [ht, front] = pq.top();
            pq.pop();
            // num of people in front of curr person
            // with greater or equal height
            int count = 0;

            for(int i=0; i<n; i++)
            {
                // place the curr person at ith index
                if(ans[i][1] == INF && count == front)
                {
                    ans[i][0] = ht;
                    ans[i][1] = front;
                    break;
                }
                // person with greater or equal height
                else if(ans[i][0] >= ht)
                    count++;
            }
        }

        return ans;
    }
};
// {INF, INF} represents empty-space
// empty-space is assumed to have 
// greater height than any person in people[]