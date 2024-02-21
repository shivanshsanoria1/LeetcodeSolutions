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
            // iterator to the smallest num currently in map
            auto itr = mp.begin();
            // smallest num in map
            int num = itr->first;
            // decrement the freq of the smallest num in map
            itr->second--;
            // if freq reaches 0, remove that num from map
            if(itr->second == 0)
                mp.erase(itr);
            // group size is 'k-1' excluding the 1st num in that group
            int size = k - 1;
            while(size--)
            {
                // next consecutive num
                num++;
                // iterator to curr num
                auto itr = mp.find(num);
                // curr num not found in map
                if(itr == mp.end())
                    return false;
                // decrement the freq of curr num
                itr->second--;
                // if freq reaches 0, remove the curr num from map
                if(itr->second == 0)
                    mp.erase(itr);
            }
        }
        return true;
    }
};