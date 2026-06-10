class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int time) {
        vector<int> vec(101, -1); // i: start-time, vec[i]: end-time
        
        // find the max end-time for each start time
        for(auto& clip: clips)
        {
            int start = clip[0], end = clip[1];
            vec[start] = max(vec[start], end);
        }

        int count = 1;
        int s1 = 0, e1 = vec[0]; // start1, end1
        while(e1 < time)
        {
            int maxS2 = -1, maxE2 = -1; // max start2, max end2
            bool overlappingIntervalFound = false;
            // check the intervals with start time in range [s1+1, e1]
            for(int i=s1+1; i<=e1; i++)
            {
                overlappingIntervalFound = true;
                int s2 = i, e2 = vec[i]; // start2, end2
                if(e2 > maxE2) // new max e2 found
                {
                    maxE2 = e2; // update max e2
                    maxS2 = s2; // update max s2
                }
            }
            // no overlapping interval found or max e2 < e1, ie, 
            // cannot move forward from (s1, e1) towards 'time'
            if(!overlappingIntervalFound || maxE2 < e1)
                return -1;
            s1 = maxS2; // update s1
            e1 = maxE2; // update e1
            count++;
        }
        return count;
    }
};