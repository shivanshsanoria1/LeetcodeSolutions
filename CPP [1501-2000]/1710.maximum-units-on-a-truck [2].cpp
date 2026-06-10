class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        int n=boxTypes.size();
        priority_queue<pair<int, int>> pq; // max-heap, {units per box, num of boxes}
        for(auto& box: boxTypes)
            pq.push({box[1], box[0]});
        int ans = 0;
        while(!pq.empty())
        {
            int unitsPerBox = pq.top().first;
            int boxes = pq.top().second;
            pq.pop();
            if(truckSize - boxes >= 0)
            {
                ans += unitsPerBox * boxes;
                truckSize -= boxes;
            }
            else
            {
                ans += unitsPerBox * truckSize;
                break;
            }
        }
        return ans;
    }
};