class Solution {
public:
    // T.C.=O(n), S.C.=O(1)
    int minCostToMoveChips(vector<int>& position) {
        int odd = 0, even = 0;

        for(int pos: position)
        {
            if(pos % 2 == 0)
                even++;
            else
                odd++;
        }

        return min(odd, even);
    }
};