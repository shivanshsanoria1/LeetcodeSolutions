class Solution {
public:
    bool isIdealPermutation(vector<int>& nums) { //T.C.=O(n) , S.C.=O(1)
        for(int i=0; i<nums.size(); i++) //every local inversion is a subset global inversion
            if(abs(nums[i]-i) > 1) //a global inversion can be limited to be only a local inversion 
                return false; //if abs(nums[i]-i) <= 1
        return true;
    }
};
// LI: local inversion, GI: global inversion
// [0,1,2,3,4,5] LI=0, GI=0
// swapping any 2 adjacent elements from the sorted position generates 1 LI and 1 GI
// [1,0,2,3,4,5] LI=1, GI=1
// [1,0,3,2,4,5] LI=2, GI=2
// [1,0,3,2,5,4] LI=3, GI=3
// changing 3 adjacent elements from the sorted position generates unequal LI and GI
// [2,0,1,3,4,5] LI=1, GI=2