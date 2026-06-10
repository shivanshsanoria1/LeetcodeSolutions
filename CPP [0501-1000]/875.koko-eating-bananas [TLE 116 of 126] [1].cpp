class Solution {
public:
    // T.C.=O(n*m), S.C.=O(1)
    // m: max value in piles[]
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxSpeed = *max_element(piles.begin(), piles.end());

        for(int speed = 1; speed <= maxSpeed; speed++)
        {
            int time = 0;

            for(int bananas: piles)
            {
                time += bananas % speed == 0 ? bananas/speed : bananas/speed + 1;
                
                if(time > h)
                    break;
            }

            if(time <= h)
                return speed;
        }

        return -1;
    }
};
// speed: num of bananas eaten per hour 