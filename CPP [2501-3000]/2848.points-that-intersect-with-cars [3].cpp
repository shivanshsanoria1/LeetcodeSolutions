class Solution {
private:
    static bool cmp(vector<int>& a, vector<int>& b){
        return a[0] == b[0] ? a[1] < b[1] : a[0] < b[0];
    }

public:
    int numberOfPoints(vector<vector<int>>& nums) {
        // sort by start value (in increasing order) and 
        // sort by end value (in increasing order) if start values are same 
        sort(nums.begin(), nums.end(), cmp);

        int covered = 0; // count of covered points
        int end = 0;
        for(int i=0; i<nums.size(); i++)
        {
            int s = nums[i][0], e = nums[i][1];
            if(s > end)
                covered += e - s + 1;
            else if(e > end)
                covered += e - end;

            end = max(end, e);
        }
        return covered;
    }
};