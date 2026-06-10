class Solution {
public:
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
        int n=distance.size();

        int dist1 = 0;
        for(int i=start; ; i = (i+1) % n)
        {
            if(i == destination)
                break;
            dist1 += distance[i];
        }

        int dist2 = 0;
        for(int i=start; ; i = (i-1+n) % n)
        {
            if(i == destination)
                break;
            dist2 += distance[(i-1+n) % n];
        }
        
        return min(dist1, dist2);
    }
};