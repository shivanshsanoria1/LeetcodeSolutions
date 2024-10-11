class Solution {
private:
    typedef pair<int, int> PII;

public:
    // T.C.=O(n*log(n)), S.C.=O(n)
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        // start time of target (for its identification after sorting, 
        // since each start-time is unique)
        int startTarget = times[targetFriend][0];
        
        // min-heap; available seats
        priority_queue<int, vector<int>, greater<int>> pq1;
        // min-heap; {end-time, seat}
        priority_queue<PII, vector<PII>, greater<PII>> pq2;

        // initially all the seats are available
        for(int i=0; i<times.size(); i++)
            pq1.push(i);

        // sort in increasing order of start-time
        sort(times.begin(), times.end());
        
        for(vector<int>& time: times)
        {
            int start = time[0];
            int end = time[1];

            // the people with end-time <= start-time of curr person
            // have already left, thus making their seats available for others
            while(!pq2.empty() && pq2.top().first <= start)
            {
                // seat is now available
                pq1.push(pq2.top().second);
                // person has now left
                pq2.pop();
            }

            // seat just taken by the curr person
            int seat = pq1.top();
            pq1.pop();

            // return the seat just taken by the target
            if(start == startTarget)
                return seat;

            // add the end-time and seat of curr person to 2nd heap
            pq2.push({end, seat});
        }

        return -1;
    }
};