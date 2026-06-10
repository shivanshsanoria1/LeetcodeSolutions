class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        int c=0;
        unordered_map<string,int> mp;
        for(auto it: words1)
            mp[it]++;
        for(auto it: words2)
            if(mp.find(it) != mp.end()) //found in map
                if(mp[it] <= 1) //freq > 1 appear more than once in words1 so don't check them
                    mp[it]--;
        for(auto it: mp)
            if(it.second == 0) //count elements with 0 freq
                c++;
        return c;
    }
};