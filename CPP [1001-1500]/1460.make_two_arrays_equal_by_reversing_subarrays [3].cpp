class Solution {
public:
    // T.C.=O(n), S.C.=O(n)
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        // num -> freq
        unordered_map<int, int> mp;

        for(int num: arr)
            mp[num]++;
        
        for(int num: target)
        {
            mp[num]--;
            
            if(mp[num] == 0)
                mp.erase(num);
            else if(mp[num] < 0)
                return false;
        }

        return mp.empty();
    }
};