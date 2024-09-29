class Solution {
public:
    // T.C.=O(n*log(n)), S.C.=O(1)
    long long maximumTotalSum(vector<int>& maximumHeight) {
        sort(maximumHeight.begin(), maximumHeight.end(), greater<int>());

        int curr = maximumHeight[0];
        long long int sum = 0;
        for(int height: maximumHeight)
        {
            if(curr == 0)
                return -1;
                
            curr = min(curr, height);
            sum += curr;
            curr--;
        }

        return sum;
    }
};