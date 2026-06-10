class Solution {
public:
    // T.C.=O(n), S.C.=O(n)
    int minOperations(vector<int>& nums, int k) {
        int n=nums.size();
        vector<bool> visited(k+1, false);
        int count = 0;
        for(int i=n-1; i>=0; i--)
        {
            if(nums[i] > k)
                continue;
            if(!visited[nums[i]])
                count++;
            visited[nums[i]] = true;
            if(count == k)
                return n-i;
        }
        return -1;
    }
};