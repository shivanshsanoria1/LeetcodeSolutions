class Solution {
public:
    // T.C.=O(n*logn). S.C.=O(n)
    bool isNStraightHand(vector<int>& hand, int groupSize) { 
        int n=hand.size();
        // all groups cannot be of size 'groupSize'
        if(n % groupSize != 0) 
            return false;

        // num -> freq
        unordered_map<int, int> mp; 
        for(int num: hand)
            mp[num]++;

        priority_queue<int, vector<int>, greater<int>> pq; // min-heap
        // push the distinct nums in heap
        for(auto [num, freq]: mp) 
            pq.push(num);

        // number of groups
        int groups = n / groupSize; 
        while(groups--)
        {
            // min num in the curr group
            int start = pq.top();
            
            for(int i=0; i<groupSize; i++)
            {
                // curr num of the group
                int curr = start + i;
                // curr num not found in map
                if(mp.find(curr) == mp.end())
                    return false;
                // decrement the freq of curr num
                mp[curr]--;
                // if curr num freq reaches 0, 
                // remove that num from map and heap
                if(mp[curr] == 0)
                {
                    // heap top does not match with the curr num
                    if(pq.top() != curr)
                        return false;
                        
                    pq.pop();
                    mp.erase(curr);
                }
            }
        }
        
        return true;
    }
};