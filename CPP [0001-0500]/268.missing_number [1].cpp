class Solution {
public:
    int missingNumber(vector<int>& nums) { // T.C.=O(n), S.C.=O(n)
        int n=nums.size();
        vector<bool> visited(n+1, false);
        for(int num: nums)
            visited[num] = true;
        for(int i=0; i<n+1; i++)
            if(!visited[i])
                return i;
        return -1;
    }
};