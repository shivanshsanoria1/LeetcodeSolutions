class Solution {
public:
    // T.C.=O(n * 10^7), S.C.=O(1)
    int minSpeedOnTime(vector<int>& dist, double hour) {
        // range of values that speed can take is [1, 10^7]
        for(int speed = 1; speed <= int(1e7); speed++)
        {
            double time = 0;
            for(int d: dist)
            {
                // convert time to int value
                time = ceil(time);
                // update time
                time += (double)d/speed;

                // time has exceeded the max time limit
                if(time > hour)
                    break;
            }

            if(time <= hour)
                return speed;
        }

        return -1;
    }
};
// prerequisite: [1283. find-the-smallest-divisor-given-a-threshold]
// similar: [2064. minimized-maximum-of-products-distributed-to-any-store]