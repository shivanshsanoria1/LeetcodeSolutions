class Solution {
public:
    // T.C.=O(n^2), S.C.=O(1)
    int longestWPI(vector<int>& hours) {
        int n=hours.size();
        int maxLen = 0;

        for(int i=0; i<n; i++)
        {
            int count0 = 0, count1 = 0;
            for(int j=i; j<n; j++)
            {
                if(hours[j] > 8)
                    count1++;
                else // hours[j] <= 8
                    count0++;

                if(count1 > count0)
                    maxLen = max(maxLen, j-i+1);
            }
        }

        return maxLen;
    }
};

/*
# imagine replacing each num > 8 by 1 and each num <= 8 by 0
# now the ques reducess to finding the max-len of subarray 
  with more 1's than 0's
*/