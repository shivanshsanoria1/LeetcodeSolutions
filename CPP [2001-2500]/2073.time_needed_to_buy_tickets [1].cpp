class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int ans=0, key=tickets[k];
        for(int i=0; i<tickets.size(); i++)
        {
            if(i<=k)
                ans+=min(tickets[i],key);
            else
                ans+=min(tickets[i],key-1); //-1 is done because in the last pass, we will stop after index k
        }
        return ans;
    }
};