class Solution {
public:
    // T.C.=O(n + r), S.C.=O(n)
    // r: (maxVal - minVal)
    // Counting-sort with hash-map
    vector<int> sortArray(vector<int>& nums) { 
        // num -> freq
        unordered_map<int, int> mp; 
        for(int num: nums)
            mp[num]++;

        int minVal = *min_element(nums.begin(), nums.end());
        int maxVal = *max_element(nums.begin(), nums.end());

        for(int num = minVal, i = 0; num <= maxVal; num++)
        {
            // 'num' not found in map
            if(mp.find(num) == mp.end()) 
                continue;

            // write 'num' in nums[] 'freq' times
            int freq = mp[num];
            while(freq--)
            {
                nums[i] = num;
                i++;
            }
        }

        return nums;
    }
};