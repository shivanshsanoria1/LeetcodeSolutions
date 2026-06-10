class Solution {
public:
    // T.C.=O(n^2), S.C.=O(n)
    vector<int> mostVisited(int n, vector<int>& rounds) {
        vector<int> visited(n + 1, 0);
        for(int i=0; i<rounds.size()-1; i++)
        {
            // visit the nums in range [rounds[i], rounds[i+1])
            // in a circular motion, ie, return to 1 after n
            int start = rounds[i];
            while(start != rounds[i+1])
            {
                visited[start]++;
                start++;
                if(start == n + 1)
                    start = 1;
            }
        }
        // don't forget to visit the last num
        visited[rounds.back()]++;

        vector<int> ans;
        int maxVisits = 0;
        for(int i=1; i<=n; i++)
        {
            if(visited[i] > maxVisits)
            {
                maxVisits = visited[i];
                ans.clear();
                ans.push_back(i);
            }
            else if(visited[i] == maxVisits)
                ans.push_back(i);
        }

        return ans;
    }
};