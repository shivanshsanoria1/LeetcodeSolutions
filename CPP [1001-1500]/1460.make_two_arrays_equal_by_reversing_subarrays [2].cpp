class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) { //T.C.=O(n) , S.C.=O(n)
        int n=arr.size();
        unordered_map<int,int> mp; //num -> freq
        for(int i=0; i<n; i++)
            mp[arr[i]]++; //increment freq
        for(int i=0; i<n; i++)
        {
            if(mp.find(target[i]) != mp.end()) //target[i] present in map
            {
                if(mp[target[i]] > 0) //min freq can be 0
                    mp[target[i]]--; //decrement freq
                else
                    return false;
            }
            else //target[i] not present in map
                return false;
        }
        return true;
    }
};