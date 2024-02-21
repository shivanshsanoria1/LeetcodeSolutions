class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) { //bit-manipulation
        // [X1,X2,X3,Y1,Y2,Y3]
        for(int i=0; i<n; i++) //modify the left half array
        {
            nums[i]= nums[i]<<16; //store x1 in the left 16 bits
            nums[i]= nums[i] | nums[i+n]; //store y1 in the right 16 bits
        }
        // [x1y1,x2y2,x3y3,Y1,Y2,Y3]
        for(int i=n-1, j=2*n-1; i>=0; i--,j-=2)
        {
            nums[j]= nums[i] & 0x0000FFFF; //retrieve Y
            nums[j-1]= nums[i]>>16; //retrieve X
        }
        // [X1,Y1,X2,Y2,X3,Y3]
        return nums;
    }
};