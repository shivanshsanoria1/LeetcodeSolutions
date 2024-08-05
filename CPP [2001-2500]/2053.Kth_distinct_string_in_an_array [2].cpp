class Solution {
public:
    // T.C.=O(n), S.C.=O(n)
    string kthDistinct(vector<string>& arr, int k) { 
        // string -> freq
        unordered_map<string, int> mp; 
        for(string str: arr)
            mp[str]++;

        for(string str: arr)
            if(mp[str] == 1 && --k == 0)
                return str;
                
        return "";
    }
};