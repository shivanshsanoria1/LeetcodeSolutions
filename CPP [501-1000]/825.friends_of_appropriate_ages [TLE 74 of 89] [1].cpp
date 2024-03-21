class Solution {
public:
    // T.C.=O(n^2), S.C.=O(1)
    int numFriendRequests(vector<int>& ages) {
        int n=ages.size();
        int reqCount = 0;

        for(int x=0; x<n; x++)
            for(int y=0; y<n; y++)
            {
                if(x == y)
                    continue;
                if(ages[y] <= (ages[x] / 2 + 7) || ages[y] > ages[x] || (ages[y] > 100 && ages[x] < 100))
                    continue;
                reqCount++;
            }

        return reqCount;
    }
};