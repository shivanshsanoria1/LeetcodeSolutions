class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int count = 0;
        // keep on right shifting left and right until they become equal
        while(left != right) 
        {
            left = left >> 1;
            right = right >> 1;
            count++;
        }
        // now left == right
        return left << count;
    }
};