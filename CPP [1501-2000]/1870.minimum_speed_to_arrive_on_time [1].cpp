class Solution {
public:
    // T.C.=O(n * log(10^7)), S.C.=O(1)
    // Binary-search
    int minSpeedOnTime(vector<int>& dist, double hour) {
        // range of values that speed can take is [1, 10^7]
        int left = 1;
        int right = int(1e7);

        int speed = -1;

        while(left <= right)
        {
            int mid = left + (right - left)/2;

            double time = 0;
            for(int d: dist)
            {
                // convert time to int value
                time = ceil(time);
                // update time
                time += (double)d / mid;

                // time has exceeded the max time limit
                if(time > hour)
                    break;
            }

            // curr time is within the time-limit so try to 
            // increase the time by decreasing the speed
            if(time <= hour)
            {
                speed = mid;
                right = mid - 1;
            }
            // curr time is more than the time-limit so try to 
            // decrease the time by increasing the speed
            else
                left = mid + 1;
        }
        
        return speed;
    }
};
// prerequisite: [1283. find-the-smallest-divisor-given-a-threshold]
// similar: [2064. minimized-maximum-of-products-distributed-to-any-store]