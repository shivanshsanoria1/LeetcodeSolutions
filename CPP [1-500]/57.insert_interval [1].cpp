class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        int s2 = newInterval[0], e2 = newInterval[1];
        for(int i=0; i<intervals.size(); i++)
        {
            int s1 = intervals[i][0], e1 = intervals[i][1];
            if(e2 < s1) // (s2,e2) lies before (s1,e1)
            {
                ans.push_back({s2, e2});
                // intervals starting from (s1,e1) till end lie after (s2,e2)
                ans.insert(ans.end(), intervals.begin() + i, intervals.end());
                return ans;
            }
            else if(s2 > e1) // (s2,e2) lies after (s1,e1)
                ans.push_back({s1, e1});
            else // intervals (s2,e2) and (s1,e1) intersect
            {
                // update (s2,e2)
                s2 = min(s1, s2);
                e2 = max(e1, e2);
            }
        }
        // (s2,e2) caould be the last interval to be inserted
        ans.push_back({s2, e2}); 
        return ans;
    }
};