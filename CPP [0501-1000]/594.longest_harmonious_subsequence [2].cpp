class Solution {
public:
    // T.C.=O(n*log(n)), S.C.=O(n)
    int findLHS(vector<int>& nums) { 
        // num -> freq
        map<int, int> mp; 
        for(int num: nums)
            mp[num]++;

        int ans = 0;
        for(auto itr1 = mp.begin(); itr1 != mp.end(); itr1++)
        {
            int num1 = itr1->first, freq1 = itr1->second;

            auto itr2 = next(itr1);
            if(itr2 == mp.end())
                break;

            int num2 = itr2->first, freq2 = itr2->second;

            if(num2 - num1 == 1)
                ans = max(ans, freq1 + freq2);
        }
        
        return ans;
    }
};