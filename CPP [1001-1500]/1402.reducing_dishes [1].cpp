class Solution {
public:
    // T.C.=O(n^2), S.C.=O(1)
    // Greedy
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end());

        // all nums are -ive, so we skip all of them
        if(satisfaction.back() < 0)
            return 0;
        
        int n=satisfaction.size();
        int ans = 0;
        for(int i=0; i<n; i++)
        {
            int sum = 0;
            for(int j=i, m=1; j<n; j++, m++)
                sum += satisfaction[j] * m;

            ans = max(ans, sum);

            if(satisfaction[i] >= 0)
                break;
        } 

        return ans;
    }
};
// we should be not skip any num which is >= 0
// we can only possibly skip the nums which are < 0