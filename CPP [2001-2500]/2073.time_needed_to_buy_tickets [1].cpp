class Solution {
public:
    // T.C.=O(n), S.C.=O(1)
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int count = 0;

        for(int i=0; i<tickets.size(); i++)
        {
            if(i <= k)
                count += min(tickets[i], tickets[k]);
            // -1 is done because in the last pass we will stop after index k
            else
                count += min(tickets[i], tickets[k] - 1);
        }

        return count;
    }
};