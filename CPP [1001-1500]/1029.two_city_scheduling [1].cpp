class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b){
        return a[0] - a[1] < b[0] - b[1];
    }

    int twoCitySchedCost(vector<vector<int>>& costs) { // T.C.=O(n*logn), S.C.=O(1)
        // sort in increasing order of diff between costA and costB
        sort(costs.begin(), costs.end(), cmp);
        int n=costs.size();
        int minTotalCost = 0;
        // take the costA of first n/2 elements
        for(int i=0; i<n/2; i++)
            minTotalCost += costs[i][0];
        // take the costB of the remaining n/2 elements
        for(int i=n/2; i<n; i++)
            minTotalCost += costs[i][1];
        return minTotalCost;
    }
};