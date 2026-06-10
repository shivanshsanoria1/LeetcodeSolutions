class Solution {
public:
    bool isGood(vector<int>& nums) { // T.C.=O(n), S.C.=O(n)
        int minNum = *min_element(nums.begin(), nums.end());
        if(minNum != 1)
            return false;

        int maxNum = *max_element(nums.begin(), nums.end());
        int n=nums.size();
        if(n != maxNum + 1)
            return false;

        vector<int> freq(n, 0);
        for(int num: nums)
            freq[num]++;

        if(freq[n-1] != 2)
            return false;
        for(int i=1; i<n-1; i++)
            if(freq[i] != 1)
                return false;
        return true;
    }
};