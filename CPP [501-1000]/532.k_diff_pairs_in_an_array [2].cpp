class Solution {
public:
    int findPairs(vector<int>& nums, int k) { // T.C.=O(n), S.C.=O(n)
        int count = 0;

        if(k == 0)
        {
            unordered_map<int, int> mp; // num -> freq
            for(int num: nums)
                mp[num]++;
            // find nums with freq > 1
            for(auto it: mp)
                if(it.second > 1)
                    count++;
            return count;
        }
        
        unordered_set<int> s;
        for(int num: nums)
        {
            if(s.find(num) != s.end()) // num found in set
                continue;
            if(s.find(num + k) != s.end()) // check for (num + k) in set
                count++;
            if(s.find(num - k) != s.end()) // check for (num - k) in set
                count++;
            s.insert(num);
        }
        return count;
    }
};