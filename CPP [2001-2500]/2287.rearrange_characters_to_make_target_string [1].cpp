class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        vector<int> vec(26,0); //to store freq of each char of string s
        int count=0;
        for(int i=0; i<s.length(); i++) //find freq of each char in string s
            vec[s[i]-'a']++;
        while(1)
        {
            for(int i=0; i<target.length(); i++)
            {
                vec[target[i]-'a']--;
                if(vec[target[i]-'a'] < 0) //target cannot be formed from chars. in string s
                    return count;
            }
            count++; //target can be formed from chars. in string s
        }
        return count;
    }
};