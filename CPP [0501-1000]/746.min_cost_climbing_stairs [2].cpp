class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) { // T.C.=O(n), S.C.=O(1)
        int n= cost.size();
        int s2= cost[0]; // s2 is same as S(n-2)
        int s1= cost[1]; // s1 is same as S(n-1)
        int s; // s is same as S(n)
        for(int i=2; i<n; i++)
        {
            s= min(s2, s1) + cost[i];
            s2= s1; // update s2 to s1
            s1= s; // update s1 to s
        }
        s= min(s2, s1);
        return s;
    }
};