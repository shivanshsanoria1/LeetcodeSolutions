class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        int c=0;
        unordered_map<string,int> mp1;
        unordered_map<string,int> mp2;
        for(int i=0; i<words1.size(); i++)
            mp1[words1[i]]++;
        for(int i=0; i<words2.size(); i++)
            mp2[words2[i]]++;
        for(auto it: mp1) //iterate map1
            if(it.second == 1) //curr element freq is 1
                if(mp2.find(it.first) != mp2.end()) //search curr element in map2
                    if(mp2[it.first] == 1) //curr element corresponding element in map2 has freq 1
                        c++;
        return c;
    }
};