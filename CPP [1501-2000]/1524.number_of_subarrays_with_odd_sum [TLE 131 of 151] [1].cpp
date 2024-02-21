class Solution {
private:
    #define M 1000000007 // 10^9 + 7

public:
    int numOfSubarrays(vector<int>& arr) { // T.C.=O(n^2), S.C.=O(1)
        int n = arr.size();
        int count = 0;
        for(int i=0; i<n; i++)
        {
            int sum = 0;
            for(int j=i; j<n; j++)
            {
                sum += arr[j];
                if(sum % 2 == 1)
                    count = (count + 1) % M;
            }
        }
        return count;
    }
};