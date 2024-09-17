class Solution {
public:
    // T.C.=O(n + m*log(m)), S.C.=O(m)
    // n: size of timePoints[], m: min(n, 24*60)
    int findMinDifference(vector<string>& timePoints) {
        unordered_set s(timePoints.begin(), timePoints.end());
        // presence of duplicate items mean min-diff is 0
        if(s.size() != timePoints.size())
            return 0;

        vector<int> times;
        for(string hhmm: s)
        {
            string hh = hhmm.substr(0, 2);
            string mm = hhmm.substr(3);
            int time = 60*stoi(hh) + stoi(mm);

            times.push_back(time);
        }

        sort(times.begin(), times.end());

        int m=times.size();
        int minDiff = 24*60;
        for(int i=0; i<m; i++)
        {
            int diff = abs(times[(i+1) % m] - times[i]);
            if(diff > 12*60)
                diff = 24*60 - diff;

            minDiff = min(minDiff, diff);
        }
        
        return minDiff;
    }
};