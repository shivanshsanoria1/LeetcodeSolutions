class Solution {
public:
    // T.C.=O(n*logm), S.C.=O(1)
    // m: max value in piles[]
    int minEatingSpeed(vector<int>& piles, int h) {
        int minSpeed = 1;
        int maxSpeed = *max_element(piles.begin(), piles.end());

        int reqSpeed = maxSpeed; // required speed

        while(minSpeed <= maxSpeed)
        {
            int midSpeed = minSpeed + (maxSpeed - minSpeed)/2;

            int time = 0;

            for(int bananas: piles)
            {
                time += bananas % midSpeed == 0 ? bananas/midSpeed : bananas/midSpeed + 1;
                
                // curr-time exceedes the time-limit so increase the min-speed
                if(time > h)
                {
                    minSpeed = midSpeed + 1;
                    break;
                }
            }

            // curr-time is within the time-limit so decrease the max-speed
            if(time <= h)
            {
                reqSpeed = midSpeed;
                maxSpeed = midSpeed - 1;
            }
        }

        return reqSpeed;
    }
};
// speed: num of bananas eaten per hour 