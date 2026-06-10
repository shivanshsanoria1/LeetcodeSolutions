class Solution {
public:
    int longestSubsequence(vector<int>& arr, int diff) { // T.C.=O(n^2), S.C.=O(1)
        int n=arr.size();
        int ans = 0;
        for(int i=0; i<n-1; i++)
        {
            int prev = arr[i];
            // length of longest valid subsequence starting at index i
            int len = 1; 
            for(int j=i+1; j<n; j++)
                if(arr[j] == prev + diff)
                {
                    len++;
                    prev = arr[j]; // update prev with curr value
                }
            ans = max(ans, len);
        }
        return ans;
    }
};