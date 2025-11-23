class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_set<char> s(jewels.begin(),jewels.end()); //add the jewels array in set
        int c=0;
        for(int i=0; i<stones.length(); i++)
            if(s.find(stones[i]) != s.end()) //stones[i] found in set
                c++;
        return c;
    }
};