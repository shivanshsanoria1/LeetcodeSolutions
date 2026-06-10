class Solution {
public:
    int mostFrequentEven(vector<int>& nums) { // T.C.=O(n), S.C.=O(n)
        unordered_map<int, int> mp; // num -> freq
        int maxFreq = 0;
        int ans = -1;
        for(int num: nums)
        {
            if(num % 2 == 1) // skip the odd nums
                continue;
            mp[num]++;
            int freq = mp[num];
            if(freq > maxFreq) // new max freq found
            {
                maxFreq = freq;
                ans = num;
            }
            // for same freq choose the smaller number as ans
            else if(freq == maxFreq && num < ans)
                ans = num;
        }
        return ans;
    }
};