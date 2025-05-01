class Solution {
public:
    // T.C.=O(n), S.C.=O(1)
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int sum = 0;
        for(int i=0; i<timeSeries.size()-1; i++)
            sum += min(timeSeries[i] + duration, timeSeries[i+1]) - timeSeries[i];

        return sum + duration;
    }
};