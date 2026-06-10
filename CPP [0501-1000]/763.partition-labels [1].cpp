class Solution {
public:
    // T.C.=O(n + 26*log(26)), S.C.=O(26)
    vector<int> partitionLabels(string s) {
        int n=s.length();
        // indexes of first and last occurence of a char
        vector<int> startIdx(26, -1);
        vector<int> endIdx(26, -1);

        for(int i=0; i<n; i++)
            if(startIdx[s[i] - 'a'] == -1)
                startIdx[s[i] - 'a'] = i;
        
        for(int i=n-1; i>=0; i--)
            if(endIdx[s[i] - 'a'] == -1)
                endIdx[s[i] - 'a'] = i;

        vector<pair<int, int>> intervals;
        for(int i=0; i<26; i++)
            if(startIdx[i] != -1)
                intervals.push_back({startIdx[i], endIdx[i]});
        
        // sort in increasing order of start-index
        sort(intervals.begin(), intervals.end());

        // merge the intervals
        vector<pair<int, int>> mergedIntervals;
        for(auto [start, end]: intervals)
        {
            // no overlap between prev and curr intervals
            if(mergedIntervals.empty() || mergedIntervals.back().second < start)
                mergedIntervals.push_back({start, end});
            // merge the prev and curr intervals
            else
                mergedIntervals.back().second = max(mergedIntervals.back().second, end);
        }
        
        // push the size of each merged-interval to ans
        vector<int> ans;
        for(auto [start, end]: mergedIntervals)
            ans.push_back(end - start + 1);

        return ans;
    }
};
// prerequisite: [56. merge-intervals]