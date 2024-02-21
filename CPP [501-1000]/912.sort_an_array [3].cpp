class Solution {
public:
    vector<int> sortArray(vector<int>& nums) { // Counting-sort, T.C.=O(n + k), S.C.=O(n)
        unordered_map<int, int> mp; // num -> freq
        for(int num: nums)
            mp[num]++;
        int minVal = *min_element(nums.begin(), nums.end());
        int maxVal = *max_element(nums.begin(), nums.end());
        int j = 0;
        for(int i=minVal; i<=maxVal; i++)
        {
            if(mp.find(i) == mp.end()) // i not found in map
                continue;
            int freq = mp[i];
            while(freq--)
            {
                nums[j] = i;
                j++;
            }
        }
        return nums;
    }
};
// k: range of values of elements from min value to max value