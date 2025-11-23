class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int x=0;
        for(int i=0; i<nums.size(); i++)
            x=x^nums[i]; // using A XOR A = 0 and A XOR 0 = A
        return x;
    }
};