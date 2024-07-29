class Solution {
public:
    // T.C.=O(n^3), S.C.=O(1)
    int numTeams(vector<int>& rating) {
        int n=rating.size();
        int count = 0;

        // count the triplets (i,j,k) such that
        // rating[i] < rating[j] < rating[k] 
        for(int i=0; i<n-2; i++)
            for(int j=i+1; j<n-1; j++)
            {
                if(rating[i] > rating[j])
                    continue;
                for(int k=j+1; k<n; k++)
                    if(rating[j] < rating[k])
                        count++;
            }
        
        // count the triplets (i,j,k) such that
        // rating[i] > rating[j] > rating[k] 
        for(int i=0; i<n-2; i++)
            for(int j=i+1; j<n-1; j++)
            {
                if(rating[i] < rating[j])
                    continue;
                for(int k=j+1; k<n; k++)
                    if(rating[j] > rating[k])
                        count++;
            }

        return count;
    }
};