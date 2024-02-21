class Solution {
public:
    string triangleType(vector<int>& nums) {
        int a = nums[0], b = nums[1], c = nums[2];
        // to form a triangle, the sum of any 2 sides must be greater than the 3rd side
        if(a + b <= c || b + c <= a || a + c <= b)
            return "none";
        if(a == b && b == c)
            return "equilateral";
        else if(a == b || b == c || c == a)
            return "isosceles";
        return "scalene";
    }
};