class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int> vec(26,0); //stores freq of char in string s
        for(int i=0; i<s.length(); i++)
            vec[s[i]-'a']++; //increment the freq of curr char
        for(int i=0; i<t.length(); i++)
        {
            if(vec[t[i]-'a']==0) //freq=0 means curr char does not appear in string s 
                return t[i];
            else
                vec[t[i]-'a']--; //decrement the freq of curr char
        }
        return 'x'; //return just some random value
    }
};