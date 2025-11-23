class Solution {
public:
    // T.C.=O(n), S.C.=O(n)
    int firstMissingPositive(vector<int>& nums) { 
        int n=nums.size();
        // index 0 is never used, only indexes [1, n+1] are used
        vector<bool> visited(n+2, false);

        for(int num: nums)
            if(num >= 1 && num <= n+1)
                visited[num] = true;    

        for(int i=1; i<=n+1; i++)
            if(!visited[i])
                return i;

        return -1;
    }
};
/*
# the smallest missing +ive int. would be (n+1) in the worst case
# Eg- if i/p array is [1,2,3,4,5] so n=5,
  then the smallest missing +ive int. will be 6 = (n+1) 
  thus, the smallest missing +ive int. will be in the range [1, n+1]
*/
