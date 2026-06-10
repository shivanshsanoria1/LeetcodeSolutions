class Solution {
public:
    int minimumOperations(vector<int>& nums) { // S.C.=O(101)
        vector<bool> vec(101, false);
        for(int num: nums)
            vec[num] = true;
        int count = 0;
        for(int i=1; i<=100; i++)
            if(vec[i])
                count++;
        return count;
    }
};
// just find the num of non-zero unique numbers