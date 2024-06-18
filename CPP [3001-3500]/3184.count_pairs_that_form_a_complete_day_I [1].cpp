class Solution {
public:
    // T.C.=O(n^2), S.C.=O(1)
    int countCompleteDayPairs(vector<int>& hours) {
        int n=hours.size();
        int count = 0;

        for(int i=0; i<n-1; i++)
            for(int j=i+1; j<n; j++)
                if((hours[i] + hours[j]) % 24 == 0)
                    count++;
        
        return count;
    }
};