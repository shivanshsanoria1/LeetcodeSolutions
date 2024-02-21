class Solution {
public:
    int edgeScore(vector<int>& edges) {
        int n=edges.size();
        vector<unsigned int> scores(n, 0);
        for(int i=0; i<n; i++)
            scores[edges[i]] += i;
        int maxScore = 0;
        int ans = -1;
        for(int i=0; i<n; i++)
            if(scores[i] > maxScore)
            {
                maxScore = scores[i];
                ans = i;
            }
        return ans;
    }
};