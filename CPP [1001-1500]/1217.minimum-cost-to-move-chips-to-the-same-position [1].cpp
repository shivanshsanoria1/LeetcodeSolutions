class Solution {
public:
    // T.C.=O(n^2), S.C.=O(n)
    int minCostToMoveChips(vector<int>& position) {
        // position -> coins
        unordered_map<int, int> mp;

        for(int pos: position)
            mp[pos]++;
        
        int minCost = INT_MAX;

        for(auto it: mp)
        {
            int finalPos = it.first;
            int cost = 0;

            for(auto [pos, coins]: mp)
                if(abs(finalPos - pos) % 2 == 1)
                    cost += coins;

            minCost = min(minCost, cost);
        }

        return minCost;
    }
};