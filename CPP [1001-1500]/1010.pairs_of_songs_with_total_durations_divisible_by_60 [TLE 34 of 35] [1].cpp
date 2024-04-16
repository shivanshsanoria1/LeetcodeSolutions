class Solution {
public:
    // T.C.=O(n^2), S.C.=O(1)
    int numPairsDivisibleBy60(vector<int>& time) {
        int n=time.size();
        int count = 0;

        for(int i=0; i<n-1; i++)
            for(int j=i+1; j<n; j++)
                if((time[i] + time[j]) % 60 == 0)
                    count++;
        
        return count;
    }
};