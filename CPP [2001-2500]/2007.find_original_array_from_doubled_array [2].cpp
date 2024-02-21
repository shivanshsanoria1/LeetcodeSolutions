class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) { // T.C.=O(n*logn), S.C.=O(n)
        int n=changed.size();
        vector<int> ans;
        if(n % 2 == 1) // changed array must be of even length
            return ans;

        unordered_map<int, int> mp; // num -> freq
        for(int num: changed)
            mp[num]++;

        sort(changed.begin(), changed.end());
        for(int num: changed)
        {
            if(mp[num] == 0) // freq of num is 0
                continue;
            if(mp[2*num] == 0) // 2*num not found in map or has freq 0
            {
                ans.clear();
                break;
            }
            ans.push_back(num);
            mp[num]--;
            mp[2*num]--;
        }    
        
        return ans;
    }
};