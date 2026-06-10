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

        int start = nums[0][0];
        int end = nums[0][1];
        vector<pair<int, int>> intervals;
        for(int i=1; i<nums.size(); i++)
        {
            int s = nums[i][0], e = nums[i][1];
            if(s > end) // new interval found
            {
                intervals.push_back({start, end});
                start = s;
                end = e;
            }
            else
                end = max(end, e);
        }
        intervals.push_back({start, end});

        int count = 0;
        for(auto [s, e]: intervals)
            count += e - s + 1;
        return count;
    }
};