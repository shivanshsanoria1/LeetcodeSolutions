class Solution {
public:
    // T.C.=O(n), S.C.=O(1)
    vector<int> stableMountains(vector<int>& height, int threshold) {
        vector<int> ans;
        for(int i=1; i<height.size(); i++)
            if(height[i-1] > threshold)
                ans.push_back(i);

        return ans;
    }
};