class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) { // T.C.=O(n*logn). S.C.=O(n)
        int n=hand.size();
        if(n % groupSize != 0) // all groups cannot be of size 'groupSize'
            return false;
        unordered_map<int, int> mp; // num -> freq
        for(int num: hand)
            mp[num]++;
        priority_queue<int, vector<int>, greater<int>> pq; // min-heap
        for(auto [num, freq]: mp) // push the distinct nums in heap
            pq.push(num);
        int groups = n / groupSize; // number of groups
        while(groups--)
        {
            // min num from heap
            int num = pq.top();
            // decrement the freq of the min num
            mp[num]--;
            // if freq reaches 0, pop that num from heap
            if(mp[num] == 0)
                pq.pop();
            // group size is 'groupSize-1' excluding the min num in that group
            int size = groupSize - 1;
            while(size--)
            {
                // next consecutive num
                num++;
                // curr num not found in map
                if(mp.find(num) == mp.end())
                    return false;
                // decrement the freq of the curr num
                mp[num]--;
                // if freq reaches 0, pop the matching num from heap
                if(mp[num] == 0)
                {
                    // heap top does not match with the curr num
                    if(pq.top() != num)
                        return false;
                    pq.pop();
                }
            }
        }
        return true;
    }
};