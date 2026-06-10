class Solution {
private:
    typedef pair<int, int> PI;

public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        int n=boxTypes.size();
        vector<PI> vec; // units per box -> num of boxes
        for(auto& box: boxTypes)
            vec.push_back({box[1], box[0]});
        // sort in decreasing order of units per box 
        sort(vec.begin(), vec.end(), greater<PI>());
        int ans = 0;
        for(auto& v: vec)
        {
            if(truckSize - v.second >= 0)
            {
                ans += v.first * v.second;
                truckSize -= v.second;
            }
            else
            {
                ans += v.first * truckSize;
                break;
            }
        }
        return ans;
    }
};