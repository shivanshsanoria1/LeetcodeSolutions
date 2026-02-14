class Solution {
public:
    // T.C.=O(n), S.C.=O(1)
    vector<long long> mergeAdjacent(vector<int>& nums) {
        vector<long long int> ans;
        for(int num: nums){
            ans.push_back(num);

            while(ans.size() >= 2 && ans.end()[-2] == ans.end()[-1]){
                ans.end()[-2] += ans.end()[-1];
                ans.pop_back();
            }
        }

        return ans;
    }
};