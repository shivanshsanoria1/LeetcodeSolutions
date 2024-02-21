class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {
        vector<bool> points(101, false);
        for(int i=0; i<nums.size(); i++)
            for(int j=nums[i][0]; j<=nums[i][1]; j++)
                points[j] = true;
        int count = 0;
        for(int i=1; i<=100; i++)
            if(points[i])
                count++;
        return count;
    }
};