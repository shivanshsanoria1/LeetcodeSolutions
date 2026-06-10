class Solution {
public:
    // T.C.=O(n), S.C.=O(1)
    vector<int> minCosts(vector<int>& cost) {
        vector<int> ans;
        int minCost = 100;
        
        for(int currCost: cost)
        {
            minCost = min(minCost, currCost);
            ans.push_back(minCost);
        }

        return ans;
    }
};