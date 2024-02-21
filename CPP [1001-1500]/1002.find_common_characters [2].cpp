class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<string> ans;
        vector<int> vec1(26,0); //stores the freq of char present in all strings in the array words
        vector<int> vec2(26,0); //stores the freq of char present in the string words[i]
        for(auto ch: words[0]) //store freq of char appearing in words[0]
            vec1[ch-'a']++;
        for(int i=1; i<words.size(); i++)
        {
            for(auto ch: words[i]) //store freq of char appearing in words[i]
                vec2[ch-'a']++;
            for(int j=0; j<26; j++)
            {
                vec1[j]=min(vec1[j],vec2[j]); //store min of vec1 and vec2 in vec1
                vec2[j]=0; //reset vec2
            }
        }
        for(int i=0; i<26; i++)
            while(vec1[i]--)
            {
                string s="";
                s+=i+'a';
                ans.push_back(s);
            }
        return ans;
    }
};