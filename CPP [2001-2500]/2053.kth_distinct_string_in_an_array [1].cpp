class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) { // T.C.=O(n), S.C.=O(n)
        unordered_map<string, int> mp; // string -> freq
        for(string str: arr)
            mp[str]++;
        for(string str: arr)
        {
            if(mp[str] == 1) // string str is distinct
                k--;
            if(k == 0)
                return str;
        }
        return "";
    }
};