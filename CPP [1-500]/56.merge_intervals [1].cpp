class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        int n=intervals.size();
        sort(intervals.begin(),intervals.end()); // sort the input 2d vector based on arr[i][0]
        res.push_back(intervals[0]); // add the first interval to result
        for(int i=1; i<n; i++)
        {
            if(res.back()[1]>=intervals[i][0] && res.back()[1]<=intervals[i][1])
                res.back()[1]=intervals[i][1];
            else if(res.back()[1]<intervals[i][0])
                res.push_back(intervals[i]);
        }
        return res;
    }
};