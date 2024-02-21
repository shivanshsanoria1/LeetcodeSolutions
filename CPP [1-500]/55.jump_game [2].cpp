class Solution {
public:
    bool canJump(vector<int>& nums) { //greedy method, T.C.=O(n), S.C.=O(1)
        int n=nums.size();
        int min_jump=0;
        for(int i=n-2; i>=0; i--) //start from 2nd last index
        {
            min_jump++;
            if(nums[i]>=min_jump) //its possible to reach the end from ith index
                min_jump=0; //reset min jump
        }
        return min_jump==0 ? true : false;
    }
};