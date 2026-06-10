class Solution {
public:
    int longestSubsequence(vector<int>& arr, int diff) { // T.C.=O(n), S.C.=O(n)
        int ans = 1;
        // num -> longest valid subsequence ending at num
        unordered_map<int, int> mp;
        // longest valid subsequence ending at arr[0] is 1 
        mp[arr[0]] = 1; 
        for(int i=1; i<arr.size(); i++)
        {
            int prev = arr[i] - diff;
            // prev not found in map
            // length of longest valid subsequence ending at arr[i] is 1
            if(mp.find(prev) == mp.end())
                mp[arr[i]] = 1;
            // curr length of longest valid subsequence (1 + mp[prev])
            else
                mp[arr[i]] = 1 + mp[prev];
            ans = max(ans, mp[arr[i]]);
        }
        return ans;
    }
};