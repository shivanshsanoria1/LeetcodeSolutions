class Solution {
public:
    // T.C.=O(n), S.C.=O(1)
    int wateringPlants(vector<int>& plants, int capacity) {
        int n=plants.size();
        int water = capacity;
        // without going back to refill water 
        // n steps are required to water n plants
        int steps = n;

        for(int i=0; i<n; i++)
        {
            // move 'i' steps back to fill the water and
            // then move 'i' steps forward to curr position
            if(water < plants[i])
            {
                steps += 2*i;
                water = capacity;
            }
            // water the curr plant
            water -= plants[i];
        }

        return steps;
    }
};