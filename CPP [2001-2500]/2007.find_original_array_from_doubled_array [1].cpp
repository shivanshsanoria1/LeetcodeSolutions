class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) { // T.C.=O(n*logn), S.C.=O(n)
        int n=changed.size();
        vector<int> ans;
        if(n % 2 == 1) // changed array must be of even length
            return ans;

        map<int, int> mp; // num -> freq
        for(int num: changed)
            mp[num]++;
            
        for(auto it: mp)
        {
            int num = it.first;
            while(mp[num] > 0 && mp[2*num] > 0)
            {
                ans.push_back(num);
                mp[num]--;
                mp[2*num]--;
            }
        }

        for(auto [num, freq]: mp)
            if(freq > 0)
            {
                ans.clear();
                break;
            }

        return ans;
    }
};