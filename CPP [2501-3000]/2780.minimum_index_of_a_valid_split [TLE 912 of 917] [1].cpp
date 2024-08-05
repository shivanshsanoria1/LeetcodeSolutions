class Solution {
public:
    // T.C.=O(n^2), S.C.=O(n)
    int minimumIndex(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int, int> mp1;
        unordered_map<int, int> mp2;
        for(int num: nums)
            mp2[num]++;

        for(int i=0; i<n-1; i++)
        {
            mp1[nums[i]]++;

            if(--mp2[nums[i]] == 0)
                mp2.erase(nums[i]);
            
            int dom1 = -1;
            for(auto [num, freq]: mp1)
                if(freq*2 > i+1)
                {
                    dom1 = num;
                    break;
                }
            
            if(dom1 == -1)
                continue;

            int dom2 = -1;
            for(auto [num, freq]: mp2)
                if(freq*2 > n-1-i)
                {
                    dom2 = num;
                    break;
                }
            
            if(dom1 == dom2)
                return i;
        }

        return -1;
    }
};