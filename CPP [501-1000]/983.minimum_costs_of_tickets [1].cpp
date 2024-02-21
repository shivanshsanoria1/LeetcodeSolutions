class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<bool> travelled_days(366,false); // keeps track of the days travelled
        for(int i=0; i<days.size(); i++) // mark the days travelled
            travelled_days[days[i]]=true;
        vector<int> dp(366,INT_MAX); // keeps track of costs till the ith day
        dp[0]=0; // cost of travelling uptil day0 is 0
        for(int i=1; i<366; i++)
        {
            if(travelled_days[i]==false) // not required to travel on this day
                dp[i]=dp[i-1];           // so update with cost uptil previous day
            else
            {
                int one=dp[i-1]+costs[0]; // 1 day pass cost
                int seven=dp[max(i-7,0)]+costs[1]; // 7 day pass cost
                int thirty=dp[max(i-30,0)]+costs[2]; // 30 day pass cost
                dp[i]=min({one,seven,thirty}); // update dp[i] with min of all pass costs
            }
        }
        return dp[365];
    }
};