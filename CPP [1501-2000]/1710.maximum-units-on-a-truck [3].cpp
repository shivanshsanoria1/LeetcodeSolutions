class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        vector<int> vec(1001, 0); // i: units per box, vec[i]: num of boxes
        for(auto& box: boxTypes)
            vec[box[1]] += box[0];
        int ans = 0;
        for(int i=1000; i>=1; i--)
        {
            if(vec[i] == 0) // skip the 0 boxes
                continue;
            if(truckSize - vec[i] >= 0)
            {
                ans += i * vec[i];
                truckSize -= vec[i];
            }
            else
            {
                ans += i * truckSize;
                break;
            }
        }
        return ans;
    }
};