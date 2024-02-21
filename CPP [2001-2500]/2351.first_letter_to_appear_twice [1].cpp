class Solution {
public:
    char repeatedCharacter(string s) {
        vector<int> vec(26,0);
        for(int i=0; i<s.length(); i++)
        {
            if(vec[s[i]-'a']==1)
                return s[i];
            vec[s[i]-'a']++;
        }
        return 'a'; //never executed, since string s has atleast 1 repeated character
    }
};