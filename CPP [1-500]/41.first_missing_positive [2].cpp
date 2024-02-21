class Solution {
public:
    int firstMissingPositive(vector<int>& nums) { // T.C.=O(n) ; S.C.=O(n)
        int n=nums.size();
        vector<bool> check(n+1,false);
        for(int i=0; i<n; i++)
            if(nums[i]>0 && nums[i]<=n+1) // the smallest missing +ive int. would be (n+1) in the worst
                check[nums[i]-1]=true;    // ex- if i/p array is [1,2,3,4,5] so n=5 then smallest missing +ive int. will be 6 = (n+1) 
        for(int i=0; i<n+1; i++)          // thus, smallest missing +ive int. will be in the set [1,n+1]
            if(check[i]==false)
                return i+1;
        return -1;
    }
};