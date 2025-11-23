class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> vec(26,0); //stores freq of char in string magazine
        for(int i=0; i<magazine.length(); i++)
            vec[magazine[i]-'a']++; //increment the freq of curr char
        for(int i=0; i<ransomNote.length(); i++)
        {
            if(vec[ransomNote[i]-'a']==0) //freq=0 means curr char does not appear in string magazine
                return false;
            else
                vec[ransomNote[i]-'a']--; //decrement the freq of curr char
        }
        return true;
    }
};