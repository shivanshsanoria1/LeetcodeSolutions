class Solution {
public:
    // T.C.=O(n), S.C.=O(1)
    double averageWaitingTime(vector<vector<int>>& customers) {
        int time = 0;
        long long int waitingTime = 0;

        for(vector<int>& customer: customers)
        {
            int arrival = customer[0];
            int duration = customer[1];

            if(time < arrival)
                time = arrival;

            time += duration;
            waitingTime += time - arrival;
        }

        return (double)waitingTime / customers.size();
    }
};