class Solution {
public:
    // T.C.=O(n), S.C.=O(n)
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> idxMp(n+1);
        for(int i=0; i<n; i++)
            idxMp[nums[i]].push_back(i);

        int ans = INT_MAX;
        for(vector<int>& idxs: idxMp){
            for(int i=1; i < (int)idxs.size()-1; i++){
                int diff1 = abs(idxs[i-1] - idxs[i]);
                int diff2 = abs(idxs[i] - idxs[i+1]);
                int diff3 = abs(idxs[i+1] - idxs[i-1]);

                ans = min(ans, diff1 + diff2 + diff3);
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};