class Solution {
public:
    // T.C.=O(n*logn), S.C.=O(n)
    bool isNStraightHand(vector<int>& hand, int groupSize) { 
        int n=hand.size();
        // all groups cannot be of size 'groupSize'
        if(n % groupSize != 0) 
            return false;

        // num -> freq
        map<int, int> mp; 
        for(int num: hand)
            mp[num]++;

        // number of groups
        int groups = n / groupSize; 
        while(groups--)
        {
            // min num in the curr group
            int start = mp.begin()->first;
            
            for(int i=0; i<groupSize; i++)
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