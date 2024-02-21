class Solution {
public:
    int mostFrequentEven(vector<int>& nums) { // T.C.=O(n), S.C.=O(n)
        unordered_map<int, int> mp; // num -> freq
        for(int num: nums)
            if(num % 2 == 0)
                mp[num]++;
        int maxFreq = 0;
        int ans = -1;
        for(auto it: mp)
        {
            if(it.second > maxFreq) // new max freq found
            {
                maxFreq = it.second;
                ans = it.first;
            }
            // for same freq choose the smaller number as ans
            else if(it.second == maxFreq && it.first < ans)
                ans = it.first;
        }
        return ans;
    }
};