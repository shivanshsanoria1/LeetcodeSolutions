class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) { // T.C.=O(n*logn), S.C.=O(n)
        int n=nums.size();
        if(n % k != 0) // all groups cannot be of size k
            return false;
        map<int, int> mp; // num -> freq
        for(int num: nums)
            mp[num]++;
        int groups = n / k; // number of groups
        while(groups--)
        {
            // min num in the curr group
            int start = mp.begin()->first;
            for(int i=0; i<k; i++)
            {
                // curr num of the group
                int curr = start + i;
                // curr num not found in map
                if(mp.find(curr) == mp.end())
                    return false;
                // decrement the freq of curr num
                mp[curr]--;
                // if curr num freq reaches 0, remove that num from map
                if(mp[curr] == 0)
                    mp.erase(curr);
            }
        }
        return true;
    }
};