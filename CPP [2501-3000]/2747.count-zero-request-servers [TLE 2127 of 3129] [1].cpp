class Solution {
public:
    // T.C.=O(l + q*(n+l)), S.C.=O(l)
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        vector<vector<int>> serverTimes(n+1);
        for(vector<int>& log: logs)
        {
            int id = log[0];
            int time = log[1];
            serverTimes[id].push_back(time);
        }

        vector<int> ans;
        for(int query: queries)
        {
            int start = query - x;
            int end = query;
            
            // servers that did not receive any requests in time [start, end]
            int zeros = n;
            for(int id=1; id<=n; id++)
                for(int time: serverTimes[id])
                    if(time >= start && time <= end)
                    {
                        zeros--;
                        break;
                    }
            
            ans.push_back(zeros);
        }

        return ans;
    }
};