class Solution {
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1, vector<vector<int>>& items2) {
        vector<int> weights(1001, 0); // i -> value, weights[i] -> weight
        for(int i=0; i<items1.size(); i++)
            weights[items1[i][0]] = items1[i][1];
        for(int i=0; i<items2.size(); i++)
            weights[items2[i][0]] += items2[i][1];
        vector<vector<int>> ans;
        for(int i=1; i<=1000; i++)
            if(weights[i] > 0)
                ans.push_back({i, weights[i]});
        return ans;
    }
};
// T.C.=O(n1 + n2), S.C.=O(1001) 