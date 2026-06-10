class Solution {
private:
    bool removeNum(unordered_map<int, int>& mp, int& dupCount, int num){
        mp[num]--;

        if(mp[num] == 1)
            dupCount--;
        else if(mp[num] == 0)
            mp.erase(num);

        return dupCount == 0;
    }

public:
    // T.C.=O(n), S.C.=O(n)
    int minOperations(vector<int>& nums) {
        // num -> freq
        unordered_map<int, int> mp;
        for(int num: nums)
            mp[num]++;
        
        int dupCount = 0;
        for(auto [num, freq]: mp)
            if(freq > 1)
                dupCount++;

        if(dupCount == 0)
            return 0;

        int n = nums.size();
        for(int i=0; i<n; i+=3){
            if(removeNum(mp, dupCount, nums[i]))
                return i/3 + 1;
            if(i+1 < n && removeNum(mp, dupCount, nums[i+1]))
                return i/3 + 1;
            if(i+2 < n && removeNum(mp, dupCount, nums[i+2]))
                return i/3 + 1;
        }

        return -1;
    }
};