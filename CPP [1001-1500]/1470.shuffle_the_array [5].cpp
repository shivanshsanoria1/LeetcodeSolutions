class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        // [X1,X2,X3,Y1,Y2,Y3]
        for(int i=n; i<2*n; i++) //modify the right half array
        {
            nums[i]= nums[i]<<16; //store y1 in the left 16 bits
            nums[i]= nums[i] | nums[i-n]; //store x1 in the right 16 bits
        }
        // [X1,X2,X3,y1x1,y2x2,y3x3]
        for(int i=0,j=n; j<2*n; i+=2,j++)
        {
            nums[i]= nums[j] & 0x0000FFFF; //retrieve X
            nums[i+1]= nums[j]>>16; //retrieve Y
        }
        // [X1,Y1,X2,Y2,X3,Y3]
        return nums;
    }
};