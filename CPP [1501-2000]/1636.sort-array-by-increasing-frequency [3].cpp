class Solution {
public:
    // T.C.=O(n*log(n)), S.C.=O(n)
    vector<int> frequencySort(vector<int>& nums) {
        // num -> freq
        unordered_map<int, int> mp; 
        for(int num: nums)
            mp[num]++;
        
        sort(nums.begin(), nums.end(), [&](int a, int b){
            return mp[a] == mp[b] ? a > b : mp[a] < mp[b];
        });

        return nums;
    }
};